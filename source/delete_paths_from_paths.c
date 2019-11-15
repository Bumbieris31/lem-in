/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_paths_from_paths.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:28:31 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/15 14:14:29 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	find_and_remove_path(t_lemin *lemin, int id)
{
	t_link	*paths;

	paths = lemin->paths;
	while (paths->id != id)
	{
		if (paths->next)
			paths = paths->next;
		else
			break ;
	}
	if (paths->id == id)
		free_path_rooms(paths->ptr);
}

void	delete_paths_from_paths(t_lemin *lemin)
{
	t_del	*temp_del;

	temp_del = lemin->del_links;
	while (temp_del->next)
	{
		if (temp_del->path_id != 0) //still check if path_ids are the same as in lemin->paths->id
			find_and_remove_path(lemin, temp_del->path_id);
		temp_del = temp_del->next;
	}
	if (temp_del->path_id != 0)
		find_and_remove_path(lemin, temp_del->path_id);
}