/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:27:38 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/04 14:11:55 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		print_movement(t_link *path)
{
	if (!path)
		return ;
	print_movement(path->next);
	if (path->ptr->ant > 0)
		ft_printf("L%d-%s ", path->ptr->ant, path->name);
}

/* Cannot delete last ant. 
static void		incr_ants(t_link *path, t_lemin *lemin)
{
	int	temp;

	temp = path->next->ptr->ant;
	while (path->next)
	{
		
		path->next->ptr->ant = path->ptr->ant;
		path = path->next;
	}
}
*/

static void		incr_ants(t_link *path, t_lemin *lemin)	//no need for lemin
{
	if (!path)
		return ;
	if (path->ptr->ant > 0 || path->ptr->ant == -1)
		incr_ants(path->next, lemin);
	if (!path->next)
		return ;
	path->next->ptr->ant = path->ptr->ant;
	path->ptr->ant = -1;
}


void	move_ants(t_lemin *lemin, t_link *path)
{
	int			ant;
	int			stop;
	int			last_ant;
	t_link		*filled_rooms;

	ant = 1;
	last_ant = 0;
	while (lemin->end->ant != lemin->ants)
	{
		if (!path->next)
			break ;
		incr_ants(path->next, lemin);
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
