/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodedelone.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:55:24 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 20:00:07 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_nodedelone(t_node *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	lst->next = NULL;
	free(lst);
	lst = NULL;
}
