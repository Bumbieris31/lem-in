/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_connect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:26:31 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/30 15:40:25 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	connect_two(char **rooms, t_room *table[])
{
	hashing_funct(rooms[0])
}

void	make_connect(char **connections, t_room *table[])
{
	int		i;
	char	**rooms;

	while (connections[i])
	{
		rooms = ft_strsplit(connections[i], '-');
		connect_two(rooms, table);
	}
}