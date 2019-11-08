#include "lem-in.h"

static void			set_path_id(t_link *paths, t_room **rooms, int end, int start)
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
		path = path->next;
	}
	rooms[end]->path = 0;
	rooms[end]->from = NULL;
}

static t_room		*get_starting_room(t_link *link, int dist)
{
	t_room	*room;

	while (link->ptr->dist == -1 || link->ptr->from)
		link = link->next;
	room = MEM(t_room);
	while (link)
	{
		if (link->ptr->dist == -1 || link->ptr->from)
			;
		else if (link->ptr->dist == (dist - 1))
		{
			room->name = link->ptr->name;
			room->id = link->ptr->id;
			room->dist = link->ptr->dist;
			break ;
		}
		link = link->next;
	}
	return (room);
}

static void			get_new_path(t_room **path, t_room **rooms, t_room *end, int backtrack) /* DOESN"T WORK, REWRITE!!!!!!!!!! */
{
	t_room	*new;
	t_link	*link;
	int		dist;
	int		path_option;

	if ((*path)->id == end->id)
		return ;
	new = MEM(t_room);
	if (backtrack)
	{
		new->name = rooms[(*path)->id]->from->name;
		new->dist = (*path)->dist - 1;
		new->id = rooms[(*path)->id]->from->id;
		(*path)->to = new;
		get_new_path(&(*path)->to, rooms, end, 0);
		return ;
	}
	link = rooms[(*path)->id]->link;
	while (link->ptr->dist == -1)
		link = link->next;
	while (link)
	{
		if (link->ptr->dist == ((*path)->dist - 1))
		{
			new->name = link->ptr->name;
			new->id = link->ptr->id;
			new->dist = link->ptr->dist;
			break ;
		}
		else if (link->ptr->path && link->ptr->path != rooms[(*path)->id]->path)
			path_option = link->ptr->id;
		link = link->next;
	}
	if (!new->name)
	{
		new->name = rooms[path_option]->name;
		new->id = rooms[path_option]->id;
		new->dist = (*path)->dist;
		backtrack = 1;
	}
	(*path)->to = new;
	get_new_path(&(*path)->to, rooms, end, backtrack);
}

t_link				*get_path(t_lemin *lemin)
{
	t_link		*path;
	int			cur;
	int			nxt;

	reset_rooms(ROOMS, END->id);
	set_path_id(PATHS, ROOMS, END->id, START->id);
	breadth_first(ROOMS, END, START->id);
	if (START->dist == -1)
		return (NULL);
	path = MEM(t_link);
	path->id = 1; /* THIS WAS FOR TESTING BUT MOVE TO PATH_SPLIT, DELETE LATER */
	path->ptr = get_starting_room(START->link, START->dist);
	get_new_path(&path->ptr, ROOMS, END, 0);
	return (path);
}
