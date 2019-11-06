/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodeiter.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:54:46 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:55:09 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_nodeiter(t_node *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	f(lst->content);
	ft_nodeiter(lst->next, f);
}
