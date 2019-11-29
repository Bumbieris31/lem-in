/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:02:22 by fhignett          #+#    #+#             */
/*   Updated: 2019/11/28 14:12:14 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			add_to_queue(t_link **queue, t_room *room)
{
	if (!*queue)
	{
		*queue = MEM(t_link);
		(*queue)->ptr = room;
	}
	else
		add_to_queue(&(*queue)->next, room);
}

static int			against_path(t_room *from, t_room *towards)
{
	if (towards->path && towards->to->id == from->id)
		return (1);
	return (0);
}

static void			on_path(t_link **queue, t_room *path, int dist, int end)
{
	t_link *link;

	if (path->id == end)
		return ;
	link = path->link;
	while (link)
	{
		if (link->on && !link->ptr->visited && link->ptr->path != path->path)
		{
			link->ptr->dist = dist;
			link->ptr->branch = path;
			link->ptr->visited = ON;
			add_to_queue(queue, link->ptr);
		}
		link = link->next;
	}
	if (path->visited)
		return ;
	path->visited = ON;
	path->dist = -2;
	on_path(queue, path->to, dist, end);
}

static void			add_links_to_queue(t_link **queue)
{
	t_link *link;

	link = (*queue)->ptr->link;
	while (link)
	{
		if (!link->on || against_path((*queue)->ptr, link->ptr))
			;
		else if (!link->ptr->visited)
		{
			link->ptr->dist = (*queue)->ptr->dist + 1;
			link->ptr->visited = ON;
			if (link->ptr->path)
				link->ptr->branch = (*queue)->ptr;
			add_to_queue(queue, link->ptr);
		}
		link = link->next;
	}
}

void				breadth_first(t_room *end, int start)
{
	t_link	*queue;
	t_link	*tmp;

	queue = MEM(t_link);
	end->dist = 0;
	queue->ptr = end;
	queue->ptr->visited = ON;
	while (queue)
	{
		tmp = queue;
		if (queue->ptr->path)
			on_path(&queue, queue->ptr->to, queue->ptr->dist + 1, end->id);
		else
			add_links_to_queue(&queue);
		queue = queue->next;
		free(tmp);
		if (queue && queue->ptr->id == start)
		{
			free_t_link(queue);
			return ;
		}
	}
}
