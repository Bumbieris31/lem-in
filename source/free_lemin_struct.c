/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_lemin_struct.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 15:24:15 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/20 18:46:29 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	free_winner_ids(int **winner_ids)
{
	int	i;

	i = 0;
	while (winner_ids[i])
	{
		free(winner_ids[i]);
		i++;
	}
	if (winner_ids)
		free(winner_ids);
}

void		free_path_rooms(t_room *room)
{
	if (room->to)
		free_path_rooms(room->to);
	free(room);
	room = NULL;
}

void		free_t_link(t_link *link)
{
	if (!link)
		return ;
	free_t_link(link->next);
	free(link);
}

void		free_paths(t_link *paths)
{
	if (!paths)
		return ;
	free_paths(paths->next);
	free_path_rooms(paths->ptr);
	free(paths);
	paths = NULL;
}

void		free_lemin_struct(t_lemin	*lemin)
{
	int	i;

	free_winner_ids(lemin->winner_ids);
	free_paths(PATHS);
	i = lemin->size;
	while (i > 0)
	{
		if (ROOMS[i])
		{
			// free name and t_link links if there are any
			free(ROOMS[i]);
		}
		i--;
	}
	free(lemin);
}