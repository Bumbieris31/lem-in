#include "lem-in.h"

static void			reset_rooms(t_room **rooms, int end)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->dist = -1;
		rooms[i]->visited = 0;
		i++;
	}
	rooms[end]->dist = 0;
	rooms[end]->path = 0;
	rooms[end]->from = NULL;
}

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

static void			free_queue(t_link *queue)
{
	if (!queue)
		return ;
	free_queue(queue->next);
	free(queue);
}

static int			against_path(t_room *from, t_room *towards)
{
	if (towards->path && towards->to->id == from->id)
		return (1);
	return (0);
}

static void			on_path(t_link **queue, t_room *path, int dist)
{
	t_link *link;

	link = path->link;
	while (link)
	{
		if (!link->ptr->visited && link->ptr->path != path->path)
		{
			link->ptr->dist = dist;
			link->ptr->visited = 1;
			add_to_queue(queue, link->ptr);
		}
		link = link->next;
	}
	if (path->visited)
		return ;
	path->visited = 1;
	path->dist = -2;
	on_path(queue, path->to, dist);
}

<<<<<<< HEAD
static void			add_links_to_queue()
{

=======
static void			add_links_to_queue(t_link **queue)
{
	t_link	*link;

	link = (*queue)->ptr->link;
	while (link)
	{
		if (against_path((*queue)->ptr, link->ptr))
			;
		else if (!link->ptr->visited)
		{
			link->ptr->dist = (*queue)->ptr->dist + 1;
			link->ptr->visited = 1;
			add_to_queue(queue, link->ptr);
		}
		link = link->next;
	}
>>>>>>> flint
}

void				breadth_first(t_room **rooms, t_room *end, int start)
{
	t_link	*queue;
	t_link	*tmp;

	reset_rooms(rooms, end->id);
	queue = MEM(t_link);
	queue->ptr = end;
	queue->ptr->visited = 1;
	while (queue)
	{
		tmp = queue;
		if (queue->ptr->path)
			on_path(&queue, queue->ptr->to, queue->ptr->dist + 1);
		else
<<<<<<< HEAD
		{
			add_links_to_queue();
			link = queue->ptr->link;
			while (link)
			{
				if (against_path(queue->ptr, link->ptr))
					;
				else if (!link->ptr->visited)
				{
					link->ptr->dist = queue->ptr->dist + 1;
					link->ptr->visited = 1;
					add_to_queue(&queue, link->ptr);
				}
				link = link->next;
			}
		}
=======
			add_links_to_queue(&queue);
>>>>>>> flint
		queue = queue->next;
		free(tmp);
		if (queue->ptr->id == start)
		{
			free_queue(queue);
			return ;
		}
	}
}
