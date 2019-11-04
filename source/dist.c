#include "lem-in.h"
#include <stdio.h>		// delete

static void	dist(t_room *room, char *start)
{
	t_link	*link;
	int		tmp_dist;
	static int	cond;

	if (ft_strequ(room->name, start))
	{
		cond = 1;
		return ;
	}
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
	if (cond != 1)	//change to check if start->dist is -1
		printf("shit");	// add error managment
}

void		set_dist(t_lemin *lemin)
{
	lemin->end->dist = 0;
	dist(lemin->end, lemin->start->name);
}