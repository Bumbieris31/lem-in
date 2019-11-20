#include "lem-in.h"

static t_room	*add_room_to_path(char *name, int id, int dist)
{
	t_room *new;

	new = MEM(t_room);
	new->name = name;
	new->id = id;
	new->dist = dist;
	return (new);
}

static t_room	*get_starting_room(t_link *link, int dist)
{
	t_room	*room;
	t_room	*ptr;

	while (link)
	{
		ptr = link->ptr;
		if (ptr->dist == -1 || ptr->path)
			;
		else if (ptr->dist == (dist - 1))
		{
			room = add_room_to_path(ptr->name, ptr->id, ptr->dist);
			break ;
		}
		link = link->next;
	}
	return (room);
}

static t_room	*check_link(t_room *path, t_room **rms, int *dst, t_link *link)
{
	if (!link)
	{
		(*dst)--;
		return (rms[path->id]->branch);
	}
	return (link->ptr);
}

static void		go_back_one(t_room **path, t_lemin *lemin)
{
	t_room *room;

	room = ROOMS[(*path)->id]->from;
	(*path)->to = add_room_to_path(room->name, room->id, room->dist);
	*path = (*path)->to;
}

static t_room	*on_existing_path(t_room *path, t_lemin *lemin, int *dist)
{
	t_link	*link;
	t_room	*room;
	
	lemin->overlap = 1;
	go_back_one(&path, lemin);
	while (!ROOMS[path->id]->branch)
	{
		room = ROOMS[path->id]->from;
		path->to = add_room_to_path(room->name, room->id, room->dist);
		path = path->to;
	}
	room = ROOMS[path->id]->branch;
	path->to = add_room_to_path(room->name, room->id, *dist - 1);
	if (room->path)
	{
		(*dist)--;
		path->to->path = 1;
		path->to->dist = -2;
	}
	return (path);
}

static void		find_path(t_link *link, int dist, t_room **rooms, t_room *tmp)
{
	t_room	*branch;

	while (link && (!link->on || link->ptr->dist != dist || link->ptr->path))
		link = link->next;
	if (!link)
	{
		branch = rooms[tmp->id]->branch;
		tmp->to = add_room_to_path(branch->name, branch->id, -2);
		tmp->to->path = ON;
	}
	else
		tmp->to = add_room_to_path(link->ptr->name, link->ptr->id, dist);
}

static void		get_new_path(t_room **path, t_lemin *lemin)
{
	int		dist;
	t_room	*tmp;
	t_link	*link;

	tmp = *path;
	while (tmp->id != END->id)
	{
		if (tmp->path)
			tmp = on_existing_path(tmp, lemin, &dist);
		else
		{
			dist = tmp->dist - 1;
			link = ROOMS[tmp->id]->link;
			find_path(link, dist, ROOMS, tmp);
		}
		tmp = tmp->to;
	}
}

static void		set_path_id(t_link *paths, t_room **rooms, int end, int start)
{
	t_link	*path;
	t_room	*room;
	int		cur;
	int		nxt;

	path = paths;
	while (path)
	{
		room = path->ptr;
		cur = room->id;
		if (rooms[cur]->path != path->id)
		{
			rooms[cur]->from = rooms[start];
			while (room->id != end)
			{
				nxt = room->to->id;
				rooms[cur]->path = path->id;
				rooms[cur]->to = rooms[nxt];
				rooms[nxt]->from = rooms[cur];
				room = room->to;
				cur = nxt;
			}
		}
		path = path->next;
	}
	rooms[end]->path = 0;
	rooms[end]->from = NULL;
}

t_link			*get_path(t_lemin *lemin)
{
	t_link		*path;
	int			cur;
	int			nxt;

	set_path_id(PATHS, ROOMS, END->id, START->id);
	breadth_first(ROOMS, END, START->id);
	if (START->dist == -1)
		return (NULL);
	path = MEM(t_link);
	path->ptr = get_starting_room(START->link, START->dist);
	get_new_path(&path->ptr, lemin);
	path->on = START->dist;
	reset_rooms(ROOMS);
	return (path);
}
