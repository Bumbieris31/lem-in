#include "lem-in.h"

static void			reset_dist(t_room **rooms, int end)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->dist = -1;
		i++;
	}
	rooms[end]->dist = 0;
	rooms[end]->from = NULL;
}

static void			add_to_queue(t_path **queue, t_room *room)
{
	if (!*queue)
	{
		*queue = MEM(t_path);
		(*queue)->ptr = room;
	}
	else
		add_to_queue(&(*queue)->next, room);
}

void				breadth_first(t_room **rooms, t_room *end)
{
	t_path	*queue;
	t_path	*tmp;
	t_link	*link;

	reset_dist(rooms, end->id);
	queue = MEM(t_path);
	queue->ptr = end;
	queue->ptr->dist = 0;
	queue->ptr->visited = 1;
	while (queue)
	{
		tmp = queue;
		link = queue->ptr->link;
		while (link)
		{
			if (!link->ptr->visited)
			{
				link->ptr->dist = queue->ptr->dist + 1;
				link->ptr->visited = 1;
				add_to_queue(&queue, link->ptr);
			}
			link = link->next;
		}
		queue = queue->next;
		free(tmp);
	}
}
