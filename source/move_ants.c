/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:27:38 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/01 21:46:12 by abumbier         ###   ########.fr       */
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

static void		incr_ants(t_link *path, int max_ants)
{
	if (!path)
		return ;
	if (path->ptr->ant > 0)
		incr_ants(path->next, max_ants);
	if (!path->next)
		return ;
	path->next->ptr->ant = path->ptr->ant;
//	if (path->ptr->ant == max_ants)
//	path->ptr->ant = 0;
}

void	move_ants(t_lemin *lemin, t_link *path)
{
	int		ant;
	int		stop;
	t_link	*filled_rooms;

	ant = 1;
	while (lemin->end->ant < lemin->ants)
	{
		if (!path->next)
			break ;
		incr_ants(path->next, lemin->ants);
		path->next->ptr->ant = ant;
		// delete the path after the last ant has moved in every turn?
		print_movement(path);
		ft_putchar('\n');
		if (ant < lemin->ants)
			ant++;
	}
}