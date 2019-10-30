/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashing_funct.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:10:37 by abumbier       #+#    #+#                */
/*   Updated: 2019/10/30 18:11:57 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <string.h>

size_t	hashing_funct(char *str)
{
	int		c;
	size_t	hash;

	hash = 5381;
	c = *str;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		c = *str++;
	}
	return (hash % 100);
}
