/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   links.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 17:57:40 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/20 17:59:35 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_link	*get_path_pointer(t_link *paths, int path_id)
{
	if (!paths)
		return (NULL);
	if (paths->id == path_id)
		return (paths);
	return (get_path_pointer(paths->next, path_id));
}

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

void			split_links(t_link *new_path, t_lemin *lemin)
{
	int		path_id;
	int		room1;
	int		room2;
	t_link	*overlap_path;
	t_room	*room;

	room = new_path->ptr;
	room1 = START->id;
	while (room)
	{
		room2 = room->id;
		if (ROOMS[room2]->path)
		{
			path_id = ROOMS[room2]->path;
			overlap_path = get_path_pointer(PATHS, ROOMS[room2]->path);
			path_links_on(overlap_path, ROOMS, START->id);
			reset_path(ROOMS, overlap_path->ptr);
			PATHS = delete_path(PATHS, path_id);
		}
		switch_link_on_off(ROOMS[room1]->link, room2);
		switch_link_on_off(ROOMS[room2]->link, room1);
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
