#include "lem-in.h"
void		reset_path(t_room **rooms, t_room *path);
t_link		*delete_path(t_link *path, int path_id);

void			switch_link_on_off(t_link *link, int connect)
{
	if (!link)
		return ;
	if (link->id == connect)
	{
		link->on = link->on == ON ? OFF : ON;
		return ;
	}
	switch_link_on_off(link->next, connect);
}

static t_link	*get_path_pointer(t_link *paths, int path_id)
{
	if (!paths)
		return (NULL);
	if (paths->id == path_id)
		return (paths);
	return (get_path_pointer(paths->next, path_id));
}

static void		path_links_on(t_link *path, t_room **rooms, int start)
{
	int		room1;
	int		room2;
	t_link	*link;
	t_room	*room;

	room = path->ptr;
	room1 = start;
	while (room)
	{
		room2 = room->id;
		switch_link_on_off(rooms[room1]->link, room2);
		switch_link_on_off(rooms[room2]->link, room1);
		room = room->to;
		room1 = room2;
	}
}

void			activate_split_path_links(t_link *new_path, t_room **rooms, t_link **paths, int start)
{
	int		path_id;
	int		room1;
	int		room2;
	t_link	*overlap_path;
	t_room	*room;

	room = new_path->ptr;
	room1 = start;
	while (room)
	{
		room2 = room->id;
		if (rooms[room2]->path)
		{
			path_id = rooms[room2]->path;
			overlap_path = get_path_pointer(*paths, rooms[room2]->path);
			path_links_on(overlap_path, rooms, start);
			reset_path(rooms, overlap_path->ptr);
			*paths = delete_path(*paths, path_id);
		}
		switch_link_on_off(rooms[room1]->link, room2);
		switch_link_on_off(rooms[room2]->link, room1);
		room = room->to;
		room1 = room2;
	}
}

void			turn_all_links_on_off(t_room **rooms, int size, int on_off)
{
	int		i;
	t_link	*link;

	i = 0;
	while (i < size)
	{
		link = rooms[i]->link;
		while (link)
		{
			link->on = on_off;
			link = link->next;
		}
		i++;
	}
}