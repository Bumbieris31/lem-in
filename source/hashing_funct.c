/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing_funct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:10:37 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/30 17:40:42 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

unsigned long	hashing_funct(char *str)
{
	int				c;
	unsigned long	hash;

	hash = 5381;
	c = *str;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		c = *str++;
	}
	return (hash % 100);
}
