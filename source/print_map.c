/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 18:57:51 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/27 16:36:26 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_map(t_list **map, int ants)
{
	char	*line;
	t_list	*del;

	ft_printf("%d\n", ants);
	while (*map)
	{
		line = (char*)(*map)->content;
		ft_putendl(line);
		del = *map;
		(*map) = (*map)->next;
		free(del->content);
		free(del);
	}
	ft_putendl("");
}
