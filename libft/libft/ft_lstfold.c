/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfold.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 15:01:07 by fhignett       #+#    #+#                */
/*   Updated: 2019/10/25 14:54:50 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t		listlen(t_list *head)
{
	int len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

static	size_t		listsize(t_list *head)
{
	int size;

	size = 0;
	while (head)
	{
		size += (head->content_size) - 1;
		head = head->next;
	}
	return (size);
}

static void			add_glue(const char *glue, size_t *x, char **s)
{
	size_t	g;

	g = 0;
	while (g < ft_strlen(glue))
	{
		(*s)[*x] = glue[g];
		(*x)++;
		g++;
	}
}

static char			*fillstr(t_list *head, const char *glue, char *s)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (head)
	{
		while (((char*)head->content)[i] != '\0')
		{
			s[x] = ((char*)head->content)[i];
			x++;
			i++;
			if (((char*)head->content)[i] == '\0' && head->next != NULL)
				add_glue(glue, &x, &s);
		}
		if (head->next == NULL)
			break ;
		head = head->next;
		i = 0;
	}
	s[x] = '\0';
	return (s);
}

char				*ft_lstfold(t_list *head, const char *glue)
{
	char	*s;
	size_t	size;

	if (!head)
		return (NULL);
	if (!glue)
		return (ft_lstfold(head, ""));
	size = listsize(head) + ((listlen(head) - 1) * ft_strlen(glue));
	s = (char*)malloc(sizeof(char) * size + 1);
	s = fillstr(head, glue, s);
	return (s);
}
