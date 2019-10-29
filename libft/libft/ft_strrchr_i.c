/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr_i.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 14:04:41 by fhignett       #+#    #+#                */
/*   Updated: 2019/10/04 14:36:37 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

ssize_t		ft_strrchr_i(const char *s, int c)
{
	ssize_t i;

	if (!s)
		return (-1);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			break ;
		i--;
	}
	return (i);
}
