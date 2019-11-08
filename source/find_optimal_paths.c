/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:42:05 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/08 17:51:34 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	free_old_ids(int ***temp_path_ids)
{
	int	i;
	int	j;

	i = 0;
	while (*temp_path_ids && (*temp_path_ids)[i])
	{
		free((*temp_path_ids)[i]);
		i++;
	}
	if (*temp_path_ids)
		free(*temp_path_ids);
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

	fastest_paths = -1;
	temp_path_ids = 0;
	while (1)// while new paths are being made
	{
		/*
		** Path searching function which resets distance and returns next path
		*/
		temp_paths = move_ants_in_all_paths(lemin);
		if (temp_paths < fastest_paths || fastest_paths == -1)
		{
			fastest_paths = temp_paths;
			// free path id arrays;
			free_old_ids(&temp_path_ids);
			// save new path ids
			temp_path_ids = save_path_ids(lemin->paths);
		}
	}
	lemin->winner_ids = temp_path_ids;
}
