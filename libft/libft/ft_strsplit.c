/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:22:42 by fhignett       #+#    #+#                */
/*   Updated: 2019/10/25 14:35:52 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			countc(char const *s, char c)
{
	int	x;

	x = 0;
	while (*s != c && *s != '\0')
	{
		x++;
		s++;
	}
	return (x);
}

static const char	*copy_str(char const *s, char c, int *x, char **arraystr)
{
	int	y;

	y = 0;
	while (*s != c && *s != '\0')
	{
		arraystr[*x][y] = *s;
		y++;
		s++;
	}
	arraystr[*x][y] = '\0';
	return (s);
}

static char			**malloc_array(char const *s, char **arraystr, char c)
{
	int		x;
	int		chrs;

	x = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			chrs = countc(s, c);
			arraystr[x] = (char*)malloc(sizeof(char) * chrs + 1);
			if (!arraystr[x])
				return (NULL);
			s = copy_str(s, c, &x, arraystr);
			x++;
		}
		else
			s++;
	}
	arraystr[x] = NULL;
	return (arraystr);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**arraystr;
	int		words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	arraystr = (char**)malloc(sizeof(char*) * (words + 1));
	if (!arraystr)
		return (NULL);
	arraystr = malloc_array(s, arraystr, c);
	return (arraystr);
}
