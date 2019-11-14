/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lemin_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:24:15 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/14 16:34:02 by abumbier         ###   ########.fr       */
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

static void	free_path_rooms(t_room *room)
{
	if (room->to)
		free_path_rooms(room->to);
	if (room)
		free(room);
}

static void	free_paths(t_link *paths)
{
	free_path_rooms(paths->ptr);
	while (paths->next)
	{
		paths = paths->next;
		free_path_rooms(paths->ptr);
	}
}

void		free_lemin_struct(t_lemin	*lemin)
{
	int	i;

	free_winner_ids(lemin->winner_ids);
	free_paths(lemin->paths);
	i = lemin->size;
	while (i > 0)
	{
		if (lemin->rooms[i])
			free(lemin->rooms[i]);
		i--;
	}
}