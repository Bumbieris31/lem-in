/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodelast.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:54:25 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:54:41 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*ft_nodelast(t_node *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
