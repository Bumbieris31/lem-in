/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_i.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 14:04:44 by fhignett       #+#    #+#                */
/*   Updated: 2019/10/04 16:46:47 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

ssize_t		ft_strchr_i(const char *s, int c)
{
	ssize_t i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
