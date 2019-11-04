#include "lem-in.h"

static void	dist(t_room *room, char *start)
{
	t_link	*link;
	int		tmp_dist;

	if (ft_strequ(room->name, start))
		return ;
	link = room->link;
	while (link)
	{
		tmp_dist = room->dist + 1;
		if (link->ptr->dist == -1 || link->ptr->dist > tmp_dist)
		{
			link->ptr->dist = tmp_dist;
			dist(link->ptr, start);
		}
		link = link->next;
	}
}

void		set_dist(t_lemin *lemin)
{
	lemin->end->dist = 0;
	dist(lemin->end, lemin->start->name);
	if (lemin->start->dist == -1)
		error_check(NO_PATH_ERROR);
}
