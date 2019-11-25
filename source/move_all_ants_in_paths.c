/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_all_ants_in_paths.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:49:59 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/24 19:57:53 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		print_movement(t_room *path)
{
	if (!path)
		return ;
	print_movement(path->to);
	if (path->ant > 0)
		ft_printf("L%d-%s ", path->ant, path->name);
}

static void		incr_ants(t_room *path)
{
	if (!path)
		return ;
	if (path->ant > 0 || path->ant == -1)
		incr_ants(path->to);
	if (!path->to)
		return ;
	path->to->ant = path->ant;
	path->ant = -1;
}

void			move_one_position(t_lemin *lemin, int *ant, int *last_ant, int count)
{
	t_link	*paths;
	int		next_ant;

	next_ant = 0;
	paths = lemin->paths;
	while (paths)
	{
		incr_ants(paths->ptr);
		if (!*last_ant && (paths && paths->on <= (lemin->lines + 1 - count)))
		{
			paths->ptr->ant = *ant;
			next_ant = 1;
		}
		if (*ant == lemin->ants)
			*last_ant = 1;
		else if (next_ant)
			(*ant)++;
		next_ant = 0;
		print_movement(paths->ptr);
		paths = paths->next;
	}
}
// 
/*
** @descr: Moves ants through the paths saved in lemin->paths
*/

int				move_ants_in_all_paths(t_lemin *lemin)
{
	int		ant;
	int		last_ant;
	int		count;

	ant = 1;
	last_ant = 0;
	count = 0;
	while (lemin->end->ant != lemin->ants && count != lemin->lines + 1)
	{
		move_one_position(lemin, &ant, &last_ant, count);
		count++;
		ft_putchar('\n');
	}
	return (count);
}
