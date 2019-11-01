/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:17:00 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/01 17:37:03 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** @descr: Recursively goes through the map and writes down distance.
*/

void	write_connections(t_room *room, t_room *start, int dist)
{
	t_link *connect;

	connect = room->link;
	room->dist = dist;
	if (room == start)
		return ;
	while (connect)
	{
		while (connect->ptr->dist <= dist + 1 && connect->ptr->dist != -1)
		{
			if (connect->next)
				connect = connect->next;
			else
				return ;
		}
		write_connections(connect->ptr, start, dist + 1);
		if (connect->next)
			connect = connect->next;
		else
			return ;
	}
	return ;
}

void	measure_distance(t_lemin *lemin)
{
	t_room *room;

	lemin->end->dist = 0;
	room = lemin->end;
	write_connections(room, lemin->start, 0);
}