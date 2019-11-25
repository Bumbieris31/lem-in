/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_all_ants_in_paths.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:49:59 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/25 19:19:50 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		print_movement(t_room *path, t_room *end)
{
	static int	count;

	if (!path)
		return (count);
	print_movement(path->to, end);
	if (path->ant > 0)
	{
		ft_printf("L%d-%s ", path->ant, path->name);
		if (ft_strequ(path->name, end->name))
			count++;
	}
	return (count);
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

int				move_one_position(t_lemin *lemin, int *ant, int *last_ant, int count)
{
	int		stamp;
	int		next_ant;
	t_link	*paths;

	stamp = 0;
	paths = lemin->paths;
	while (paths)
	{
		next_ant = 0;
		incr_ants(paths->ptr);
		if (!*last_ant && (paths && paths->on <= (lemin->lines - count)))
		{
			paths->ptr->ant = *ant;
//			ft_putstr("\nand another one!!!\n");
			next_ant = 1;
		}
//		ft_printf("\n ------last_ant: %d\n ------paths->on: %d\n ------lemin->lines: %d\n ------lemin->lines - count: %d\n", *last_ant, paths->on, lemin->lines, lemin->lines - count);
		if (*ant == lemin->ants)
		{
//			ft_putstr(" ant == lemin->ants ");
			if (next_ant)
				*last_ant = 1;
		}
		else if (next_ant)
		{
			(*ant)++;
//			stamp = 1;
		}
		next_ant = 0;
		int	temp = print_movement(paths->ptr, END);
		if (temp == lemin->ants)
		{
//			ft_printf("SUCCESS, TEMP: %d", lemin->ants);
			return (0);
		}
		paths = paths->next;
	}
	return (1);
}

/*
** @descr: Moves ants through the paths saved in lemin->paths
*/

int				move_ants_in_all_paths(t_lemin *lemin)
{
	int		ant;
	int		count;
	int		finished;
	int		last_ant;

	ant = 1;
	count = 0;
	last_ant = 0;
	finished = 0;
		int i = 0;
//	ft_printf("LINE COUNT: %d\n", lemin->lines);
	while (!finished)// && count != lemin->lines + 1
	{
		if (!move_one_position(lemin, &ant, &last_ant, count))
			finished = 1;
		count++;
		ft_putchar('\n');
		i++;
		if (i > lemin->lines)
			break ;
	}
	return (count);
}
