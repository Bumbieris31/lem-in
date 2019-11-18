/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_links_to_delete.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:14:34 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/16 23:23:17 by flintlouis    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** By going through this link we can find rooms that belong to paths, which
** we will split.
** The lemin->del_links will be 0 form most of the nodes only not when a \
** new path is stepped upon.
*/

void	save_links_to_delete(t_lemin *lemin, t_room *path)
{
	t_del	*del_link;
	int		room1;
	int		room2;

	del_link = MEM(t_del);
	room1 = path->id;
	room2 = path->to->id;
	del_link->room1 = room1;
	del_link->room2 = room2;
	del_link->path_id = ROOMS[room1]->path;
	del_link->next = lemin->del_links;
	lemin->del_links = del_link;
	switch_link_on_off(ROOMS[room1]->link, room2, OFF);
	switch_link_on_off(ROOMS[room2]->link, room1, OFF);
}
