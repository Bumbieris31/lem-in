/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:57:51 by fhignett          #+#    #+#             */
/*   Updated: 2019/11/27 20:50:03 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_map(t_list **map)
{
	char	*line;
	t_list	*del;

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
