/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_links_to_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:14:34 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/15 15:01:10 by abumbier         ###   ########.fr       */
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
	t_del	*temp_head;

	temp_head = MEM(t_del);
	temp_head->room1 = ROOMS[path->id]->id;
	temp_head->room2 = path->to->id;
	temp_head->path_id = ROOMS[path->id]->path;
	if (lemin->del_links)
		temp_head->next = lemin->del_links;
	lemin->del_links = temp_head;
}
