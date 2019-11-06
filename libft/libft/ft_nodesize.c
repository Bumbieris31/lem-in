/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodesize.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:51:47 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:51:49 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nodesize(t_node *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
