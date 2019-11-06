/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodeclear.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:55:43 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:56:04 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_nodeclear(t_node **lst, void (*del)(void *))
{
	if (!lst || !*lst)
		return ;
	ft_nodeclear(&(*lst)->next, del);
	ft_nodedelone(*lst, del);
	*lst = NULL;
}
