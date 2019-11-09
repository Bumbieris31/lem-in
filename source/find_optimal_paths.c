/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:42:05 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/08 19:29:28 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	free_old_ids(int **temp_path_ids)
{
	int	i;
	int	j;

	i = 0;
	while (temp_path_ids && temp_path_ids[i])
	{
		free(temp_path_ids[i]);
		i++;
	}
	if (temp_path_ids)
		free(temp_path_ids);
}

/*
** @descr: Measures the output lines for every path combination and assigns \
** the most efficient path ids to lemin->winner_ids.
*/

void	find_optimal_paths(t_lemin *lemin)
{
	int	fastest_paths;
	int	temp_paths;
	int	**temp_path_ids;
	t_link	*new_path;

	fastest_paths = -1;
	temp_path_ids = 0;
	new_path = get_path(lemin);
	while (new_path)// while new paths are being made
	{
		// add the new path at the end of lemin->paths
		temp_paths = move_ants_in_all_paths(lemin, DONT_PRINT);
		if (temp_paths < fastest_paths || fastest_paths == -1)
		{
			fastest_paths = temp_paths;
			// free path id arrays;
			free_old_ids(temp_path_ids);
			// save new path ids
			temp_path_ids = save_path_ids(lemin->paths);
		}
		new_path = get_path(lemin);
	}
	lemin->winner_ids = temp_path_ids;
}
