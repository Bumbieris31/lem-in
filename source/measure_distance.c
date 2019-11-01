/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   measure_distance.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 18:17:00 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/01 13:18:49 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	end_of_branch(t_link *room, char *name)
{
	
}

void	write_connections(t_room *room, int dist, char *name)
{
	// mark this link before base case
	if (room->dist == -1 || room->dist > dist)
		room->dist = dist;
	// if cannot go to the next connection or connection is the previous room or room is final room {return}
	write_connections(room->link->ptr, dist + 1, room->name); //how to get the next link->ptr?
}

void	measure_distance(t_lemin *lemin)
{
	t_room *room;

	lemin->end->dist = 0;
	room = lemin->end;
	write_connections(room, 0, room->name);

}
