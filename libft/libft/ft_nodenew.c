/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodenew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:52:34 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:59:00 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node		*ft_nodenew(void *content)
{
	t_node		*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
