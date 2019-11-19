#include "lem-in.h"

void			switch_link_on_off(t_link *link, int connect, int on_off)
{
	if (!link)
		return ;
	if (link->id == connect)
	{
		link->on = on_off;
		return ;
	}
	switch_link_on_off(link->next, connect, on_off);
}

void			add_delete_links(t_room **rooms, t_del *del_links, int on_off)
{
	t_del	*deltmp;
	int		id1;
	int		id2;

	deltmp = del_links;
	while (deltmp)
	{
		id1 = deltmp->room1;
		id2 = deltmp->room2;
		switch_link_on_off(rooms[id1]->link, id2, on_off);
		switch_link_on_off(rooms[id2]->link, id1, on_off);
		deltmp = deltmp->next;
	}
}

void			free_del_links(t_del **del_links)
{
	if (!*del_links)
		return ;
	free_del_links(&(*del_links)->next);
	free(*del_links);
	*del_links = NULL;
}

void			path_links_on(t_link *path, t_lemin *lemin)
{
	int		room1;
	int		room2;
	t_link	*link;
	t_room	*room;

	room = path->ptr;
	room1 = START->id;
	while (room)
	{
		room2 = room->id;
		switch_link_on_off(ROOMS[room1]->link, room2, ON);
		switch_link_on_off(ROOMS[room2]->link, room1, ON);
		room = room->to;
		room1 = room2;
	}
}

static t_link	*get_path_pointer(t_link *paths, int path_id)
{
	if (!paths)
		return (NULL);
	if (paths->id == path_id)
		return (paths);
	return (get_path_pointer(paths->next, path_id));
}

void			turn_overlap_links_on(t_lemin *lemin)
{
	t_link	*path;
	t_del	*del_link;
	int		prev_id;

	del_link = lemin->del_links;
	prev_id = 0;
	while (del_link)
	{
		if (prev_id != del_link->path_id)
		{
			path = get_path_pointer(PATHS, del_link->path_id);
			path_links_on(path, lemin);
			prev_id = del_link->path_id;
		}
		del_link = del_link->next;
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