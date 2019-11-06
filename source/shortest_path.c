#include "lem-in.h"

static int			find_smallest_dist(t_link *links)
{
	int		dist;
	t_room	*room;

	while (links->ptr->dist == -1)
		links = links->next;
	dist = links->ptr->dist;
	room = links->ptr;
	while (links->next)
	{
		links = links->next;
		if (dist > links->ptr->dist && links->ptr->dist != -1)
		{
			dist = links->ptr->dist;
			room = links->ptr;
		}
	}
	return (room->id);
}

t_path				*shortest_path(t_room **rooms, t_room *start, t_room *end)
{
	t_path		*path;
	int			cur;
	int			nxt;

	breadth_first(rooms, end);
	path = MEM(t_path);
	path->len = start->dist;
	cur = find_smallest_dist(start->link);
	path->ptr = rooms[cur];
	rooms[cur]->from = start;
	while (rooms[cur]->id != end->id)
	{
		nxt = find_smallest_dist(rooms[cur]->link);
		rooms[cur]->path = 1;
		rooms[cur]->to = rooms[nxt];
		rooms[nxt]->from = rooms[cur];
		cur = nxt;
	}
	return (path);
}
