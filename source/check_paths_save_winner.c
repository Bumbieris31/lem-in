/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_paths_save_winner.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 21:42:05 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/14 16:11:30 by fhignett      ########   odam.nl         */
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

int		**check_paths_save_winner(t_lemin *lemin)
{
	static int	fastest_paths;
	int			temp_paths;
	int			**temp_path_ids;

	fastest_paths = -1;
	temp_path_ids = 0;
	// temp_paths = move_ants_in_all_paths(lemin, DONT_PRINT);
	if (temp_paths < fastest_paths || fastest_paths == -1)
	{
		fastest_paths = temp_paths;
		// free path id arrays;
		free_old_ids(temp_path_ids);
		// save new path ids
		// temp_path_ids = save_path_ids(lemin->paths);
	}
	return (temp_path_ids);
}
