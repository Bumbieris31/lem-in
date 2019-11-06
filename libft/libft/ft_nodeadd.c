/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodeadd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:56:10 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:56:31 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_nodeadd(t_node **alst, t_node *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
