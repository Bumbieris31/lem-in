#include "lem-in.h"

/*
** @descr: Finds and return the room with the smallest distance var for any \
** rooms *tmp connections.
*/

t_room		*find_smallest_dist(t_link *tmp)
{
	int		dist;
	t_room	*room;

	while (tmp->ptr->dist == -1)
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

t_link				*shortest_path(t_room *start, t_room *end)
{
	t_link	*path;
	t_link	*tmp;
	t_link	*find;

	path = MEM(t_link);
	path->ptr = start;
	path->name = start->name;
	tmp = path;
	while (!ft_strequ(tmp->name, end->name))
	{
		find = tmp;
		tmp->next = MEM(t_link);
		tmp = tmp->next;
		tmp->ptr = find_smallest_dist(find->ptr->link);
		tmp->name = tmp->ptr->name;
	}
	return (path);
}
