/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_links_to_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:14:34 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/14 18:06:27 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** By going through this link we can find rooms that belong to paths, which
** we will split.
*/

void	save_links_to_delete(t_lemin *lemin, t_room *pre_link_room)
{
	t_del	*temp_head;

	if (!lemin->del_links)
		lemin->del_links = MEM(t_del);
	lemin->del_links->room_with_to = pre_link_room;
	lemin->del_links->room_with_from = pre_link_room->to; // is there *to for path rooms?
	
}
