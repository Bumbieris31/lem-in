/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   room.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 18:47:07 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/27 16:11:18 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*new_room(char *name, int id, int dist)
{
	t_room *room;

	room = MEM(t_room);
	room->name = name;
	room->dist = dist;
	room->id = id;
	return (room);
}

static int	compare_coord(t_point a, t_point b)
{
	if (a.x == b.x && a.y == b.y)
		return (1);
	return (0);
}

int			duplicate_room(t_room **rooms, char *name, t_point coord, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (compare_coord(coord, rooms[i]->coord))
			return (1);
		if (ft_strequ(name, rooms[i]->name))
			return (1);
		i++;
	}
	return (0);
}
