/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:54:57 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/08 19:55:28 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/* Free lemin->paths before running this funct
*/

void	make_new_path(t_link *paths, int id)
{
	if (!paths)
		paths = (t_link*)malloc(sizeof(t_link));
	else
	{
		while (paths && paths->next)
			paths = paths->next;
		paths->next = (t_link*)malloc(sizeof(t_link));
		
	}
	
}

t_link	*create_paths(t_lemin *lemin)
{
	int		i;
	int		j;
	t_link	*paths;
	t_link	first_path;

	i = 0;
	paths = 0;
	while (lemin->winner_ids[i])
	{
		make_new_path(paths, i);
		while ()
	}
}
