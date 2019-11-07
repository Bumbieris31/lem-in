#include "lem-in.h"

/*
** @descr: Finds and return the room with the smallest distance var for any \
** rooms *tmp connections.
*/

t_room		*find_smallest_dist(t_link *tmp)
{
	int		dist;
	t_room	*room;

	while (tmp->ptr->dist == -1 || tmp->ptr->path)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
			return (0);
	}
	dist = tmp->ptr->dist;
	room = tmp->ptr;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (dist > tmp->ptr->dist && tmp->ptr->dist != -1)
		{
			dist = tmp->ptr->dist;
			room = tmp->ptr;
		}
	}
	return (room);
}

t_link				*shortest_path(t_room **rooms, t_room *start, t_room *end)
{
	t_link		*path;
	int			cur;
	t_link		*path;
	t_room		*nxt;

	breadth_first(rooms, end, start->id);
	if (start->dist == -1)
		error_check(NO_PATH_ERROR);
	path = MEM(t_link);
	cur = find_smallest_dist(start->link);
	path->ptr = rooms[cur];
	rooms[cur]->from = start;
	while (rooms[cur]->id != end->id)
	{
		nxt = find_smallest_dist(rooms[cur]->link);
		rooms[cur]->path = 1;
		rooms[cur]->to = rooms[nxt->id];
		rooms[nxt->id]->from = rooms[cur];
		cur = nxt->id;
	}
	return (path);
}
