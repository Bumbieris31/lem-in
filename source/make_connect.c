/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:26:31 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/31 16:39:58 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** @descr: Returns the room that matches the name passed in str parameter.
** If such name doesn't exist, return the first node.
*/

static t_room	*find_room(char *str, t_room *table[], int ind)
{
	t_room	*room;

	room = table[ind];
	while (room->next)
	{
		if (ft_strequ(room->name, str))
			break ;
		else
			room = room->next;
	}
	return (room);
}

/*
** @descr: Adds room2 to room1->link at hte end of the list.
*/

void			bind_rooms(t_room *room1, t_room *room2)
{
	t_link	*connection;

	if (room1->link == 0)
	{
		room1->link = (t_link*)malloc(sizeof(t_link));
		connection = room1->link;
	}
	else
	{
		while (room1->link != 0)
			if (room1->link->next)
				room1->link = room1->link->next;
		room1->link->next = (t_link*)malloc(sizeof(t_link));
		connection = room1->link->next;
	}
	connection->name = ft_strdup(room2->name);
	connection->ptr = room2;
	connection->next = 0;
}

/*
** @descr: Finds the correct rooms from table and writes connection \
** in each rooms link member.
*/

void			connect_two(char **rooms, t_room *table[])
{
	int	ind1;
	int	ind2;
	t_room	*room1;
	t_room	*room2;

	ind1 = hashing_funct(rooms[0]);
	ind2 = hashing_funct(rooms[1]);
	room1 = find_room(rooms[0], table, ind1);
	room2 = find_room(rooms[1], table, ind2);
	bind_rooms(room1, room2);
	bind_rooms(room2, room1);
}

/*
** @descr: For every connection calls functions to create that connection.
*/

void			make_connect(char **connections, t_room *table[])
{
	int		i;
	char	**rooms;

	while (connections[i])
	{
		rooms = ft_strsplit(connections[i], '-');
		connect_two(rooms, table);
		i++;
		free(rooms[0]);
		free(rooms[1]);
		free(rooms);
	}
}
