/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_connect.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:26:31 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/14 18:49:47 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** @descr: Returns the room that matches the name passed in str parameter.
** If such name doesn't exist, return the first node.
*/

static t_room	*find_room(char *str, t_room *table[])
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

/*
** @descr: Adds room2 to room1->link at the end of the list.
*/

void			bind_rooms(t_room *room1, t_room *room2)
{
	t_link	*connection;

	if (room1->link == 0)
	{
		room1->link = MEM(t_link);
		connection = room1->link;
	}
	else
	{
		connection = room1->link;
		while (connection->next)
			connection = connection->next;
		connection->next = MEM(t_link);
		connection = connection->next;
	}
	connection->name = room2->name;
	connection->id = room2->id;
	connection->ptr = room2;
	connection->next = 0;
}

/*
** @descr: Finds the correct rooms from table and writes connection \
** in each rooms link member.
*/

void			connect_two(char **room_names, t_room *table[])
{
	t_room	*room1;
	t_room	*room2;

	room1 = find_room(room_names[ROOM1], table);
	room2 = find_room(room_names[ROOM2], table);
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

	i = 0;
	while (connections[i])
	{
		rooms = ft_strsplit(connections[i], '-');
		if (!rooms[ROOM1] || !rooms[ROOM2])
			error_check(CONN_ERROR);
		connect_two(rooms, table);
		ft_free_2darray((void**)rooms);
		i++;
	}
}
