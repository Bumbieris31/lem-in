/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:17:51 by fhignett          #+#    #+#             */
/*   Updated: 2019/11/21 16:39:18 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_room			*get_starting_room(t_link *link, int dist)
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
			room = new_room(ptr->name, ptr->id, ptr->dist);
			break ;
		}
		link = link->next;
	}
	return (room);
}

static void		go_back_one(t_room **path, t_lemin *lemin)
{
	t_room *room;

	room = ROOMS[(*path)->id]->from;
	(*path)->to = new_room(room->name, room->id, room->dist);
	*path = (*path)->to;
}

static t_room	*on_existing_path(t_room *path, t_lemin *lemin, int *dist)
{
	t_link	*link;
	t_room	*room;

	lemin->overlap = ON;
	go_back_one(&path, lemin);
	while (!ROOMS[path->id]->branch)
	{
		room = ROOMS[path->id]->from;
		path->to = new_room(room->name, room->id, room->dist);
		path = path->to;
	}
	room = ROOMS[path->id]->branch;
	path->to = new_room(room->name, room->id, *dist - 1);
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
		tmp->to = new_room(branch->name, branch->id, -2);
		tmp->to->path = ON;
	}
	else
		tmp->to = new_room(link->ptr->name, link->ptr->id, dist);
}

void			get_new_path(t_room **path, t_lemin *lemin)
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
