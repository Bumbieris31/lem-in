/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodeadd_back.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:53:59 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:54:11 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_nodeadd_back(t_node **alst, t_node *new)
{
	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
		ft_nodeadd_back(&(*alst)->next, new);
}
