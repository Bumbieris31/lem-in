#include "lem-in.h"

static t_room		*find_smallest_dist(t_link *tmp)
{
	int		dist;
	t_room	*room;

	dist = tmp->ptr->dist;
	room = tmp->ptr;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (dist > tmp->ptr->dist)
		{
			dist = tmp->ptr->dist;
			room = tmp->ptr;
		}
	}
	return (room);
}

t_link				*shortest_path(t_lemin *lemin)
{
	t_link	*path;
	t_link	*tmp;
	t_link	*find;

	path = MEM(t_link);
	path->ptr = lemin->start;
	tmp = path;
	while (!ft_strequ(tmp->name, lemin->end->name))
	{
		find = tmp;
		tmp->next = MEM(t_link);
		tmp = tmp->next;
		tmp->ptr = find_smallest_dist(find->ptr->link);
		tmp->name = tmp->ptr->name;
	}
	
	/* TESTING */
	tmp = path;
	while (tmp)
	{
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	return (path);
}