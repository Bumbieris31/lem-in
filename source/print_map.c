/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 18:57:51 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/25 19:06:28 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		print_map(t_list **map, int ants)
{
	char	*line;
	t_list	*del;

	ft_printf("%d\n", ants);
	while (*map)
	{
		line = (char*)(*map)->content;
		if (line[0] == '#' &&
		(!ft_strequ("##start", line) && !ft_strequ("##end", line)))
			;
		else
			ft_putendl(line);
		del = *map;
		(*map) = (*map)->next;
		free(del->content);
		free(del);
	}
	ft_putendl("");
}
