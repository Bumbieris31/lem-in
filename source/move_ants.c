/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_ants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 20:27:38 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/07 18:28:04 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
/* 
static void		print_movement(t_link *path)
{
	if (!path)
		return ;
	print_movement(path->next);
	if (path->ptr->ant > 0)
		ft_printf("L%d-%s ", path->ptr->ant, path->name);
}
*/
/*
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

int				move_ants_in_all_paths(t_lemin *lemin)	//add custom paths?
{
	int		ant;
	int		last_ant;
	int		count;
	t_link	*paths;

	paths = lemin->paths;	//chenge for custom paths?
	ant = 1;
	last_ant = 0;
	count = 0;
	while (lemin->end->ant != lemin->ants)
	{
		while (paths)
		{
			incr_ants(paths->ptr);
			if (!last_ant)
				paths->ptr->ant = ant;
			if (ant == lemin->ants)
				last_ant = 1;
			if (ant < lemin->ants)
				ant++;
//			print_movement(path->ptr);
			if (paths->next)	//if path is longer than amount of ants, skip it (or incrementally skip more and test?)
				paths = paths->next;
			else
				break ;
		}
		paths = lemin->paths;	//chenge for custom paths?
		count++;
		ft_putchar('\n');
	}
}

 */
/* 
static void		incr_ants(t_link *path)
{
	if (!path)
		return ;
	if (path->ptr->ant > 0 || path->ptr->ant == -1)
		incr_ants(path->next);
	if (!path->next)
		return ;
	path->next->ptr->ant = path->ptr->ant;
	path->ptr->ant = -1;
}
*/

/*
void	move_ants(t_lemin *lemin, t_link *path)
{
	int			ant;
	int			last_ant;
	t_link		*filled_rooms;

	ant = 1;
	last_ant = 0;
	while (lemin->end->ant != lemin->ants)
	{
		if (!path->next)
			break ;
		incr_ants(path->next);
		if (!last_ant)
			path->next->ptr->ant = ant;
		if (ant == lemin->ants)
			last_ant = 1;
		print_movement(path);
		ft_putchar('\n');
		if (ant < lemin->ants)
			ant++;
	}
}
 */
