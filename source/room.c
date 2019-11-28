/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   room.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 18:47:07 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/28 15:39:36 by fhignett      ########   odam.nl         */
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

int			valid_room(char **room_info)
{
	int len;
	int i;

	len = 0;
	if (!room_info || !*room_info || room_info[0][0] == 'L')
		return (ROOM_ERROR);
	while (room_info[len])
	{
		len++;
		if (!room_info[len])
			break ;
		i = 0;
		while (room_info[len][i])
		{
			if (!ft_isdigit(room_info[len][i]))
				return (ROOM_ERROR);
			i++;
		}
	}
	return (len != 3 ? ROOM_ERROR : 1);
}

/*
** @descr: Returns the room that matches the name passed in str parameter.
** If such name doesn't exist, return the first node.
*/

t_room		*find_room(char *str, t_room *table[])
{
	int		i;

	i = 0;
	while (table[i])
	{
		if (ft_strequ(table[i]->name, str))
			return (table[i]);
		i++;
	}
	return (NULL);
}
