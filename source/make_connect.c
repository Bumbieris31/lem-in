/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_connect.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:26:31 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/28 15:39:22 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** @descr: Adds room2 to room1->link at the end of the list.
*/

static void		bind_rooms(t_room *room1, t_room *room2)
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
	connection->on = ON;
}

static int		check_duplicate_links(t_link *link, int id)
{
	if (!link)
		return (0);
	if (link->id == id)
		return (CONN_ERROR);
	return (check_duplicate_links(link->next, id));
}

/*
** @descr: Finds the correct rooms from table and writes connection \
** in each rooms link member.
*/

static void		connect_two(char **room_names, t_room *table[])
{
	t_room	*room1;
	t_room	*room2;

	room1 = find_room(room_names[ROOM1], table);
	room2 = find_room(room_names[ROOM2], table);
	error_check(check_duplicate_links(room1->link, room2->id));
	error_check(check_duplicate_links(room2->link, room1->id));
	if (!room1 || !room2)
		error_check(CONN_ERROR);
	bind_rooms(room1, room2);
	bind_rooms(room2, room1);
}

/*
** @descr: For every connection calls functions to create that connection.
*/

static void		make_connect(char **connections, t_room *table[])
{
	int		i;
	char	**rooms;

	i = 0;
	while (connections[i])
	{
		rooms = ft_strsplit(connections[i], '-');
		if (!rooms[ROOM1] || !rooms[ROOM2] || ft_strequ(rooms[ROOM1], rooms[ROOM2]))
			error_check(CONN_ERROR);
		connect_two(rooms, table);
		ft_free_2darray((void**)rooms);
		i++;
	}
}

void			init_conncections(t_lemin *lemin, t_list **con)
{
	char *tmp;
	char **connections;

	if (!START || !END)
		error_check(ROOM_ERROR);
	if (!(*con))
		error_check(FILE_ERROR);
	tmp = ft_lstfold(*con, " ");
	connections = ft_strsplit(tmp, ' ');
	free(tmp);
	ft_lstdel(con, ft_bzero);
	make_connect(connections, lemin->rooms);
	ft_free_2darray((void**)connections);
}
