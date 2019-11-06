/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nodemap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 19:52:18 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/06 19:57:26 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*ft_nodemap(t_node *lst, void *(*f)(void *))
{
	t_node	*res;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst)
	{
		ft_nodeadd_back(&res, ft_nodenew(f(lst->content)));
		lst = lst->next;
	}
	return (res);
}
