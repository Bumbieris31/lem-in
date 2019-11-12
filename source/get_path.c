#include "lem-in.h"
#include <stdio.h>

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

static t_room		*add_room_to_path(char *name, int id, int dist)
{
	t_room *new;

	new = MEM(t_room);
	new->name = name;
	new->id = id;
	new->dist = dist;
	return (new);
}

static t_room		*on_path(t_room *path, t_room **rooms, int dist)
{
	t_link	*link;
	t_room	*room;

	room = rooms[path->id];
	path->to = add_room_to_path(room->from->name, room->from->id, room->from->dist);
	path = path->to;
	while (path->dist != dist)
	{
		room = rooms[path->id];
		path->to = add_room_to_path(room->from->name, room->from->id, room->from->dist);
		path = path->to;
	}
	link = rooms[path->id]->link;
	while (link && link->ptr->dist != (dist - 1))
		link = link->next;
	path->to = add_room_to_path(link->ptr->name, link->ptr->id, dist - 1);
	return (path);
}

static void			get_new_path(t_room **path, t_room **rooms, t_room *end)
{
	int		dist;
	t_room	*tmp;
	t_link	*link;
	t_room	*path_option;

	tmp = *path;
	while (tmp->id != end->id)
	{
		link = rooms[tmp->id]->link;
		dist = tmp->dist - 1;
		/* if (tmp->path) // START WITH CHECKING IF ON A PATH?
			on_path() */
		while (link && (link->ptr->dist != dist || link->ptr->path))
		{
			if (link->ptr->path && link->ptr->dist != -1) /* ERROR HERE, IF CONNECTED TO 2 PATHS */
				path_option = link->ptr;
			link = link->next;
		}
		if (!link)
		{
			tmp->to = add_room_to_path(path_option->name, path_option->id, -2);
			tmp = on_path(tmp->to, rooms, dist); /* WHAT IF COMES ON NEW PATH? CAN THAT HAPPEN??? MAKE MAP TO TEST*/
		}
		else
			tmp->to = add_room_to_path(link->ptr->name, link->ptr->id, dist);
		tmp = tmp->to;
	}
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
	get_new_path(&path->ptr, ROOMS, END);
	return (path);
}
