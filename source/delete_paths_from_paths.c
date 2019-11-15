/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delete_paths_from_paths.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 22:28:31 by abumbier       #+#    #+#                */
/*   Updated: 2019/11/15 15:55:58 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_link	*delete_path(t_link *path, int path_id)
{
	t_link *ret;

	
	if (!path)
		return (NULL);
	if (path->id == path_id)
	{
		ret = path->next;
		free_path_rooms(path->ptr);
		free(path);
		return (ret);
	}
	path->next = delete_path(path->next, path_id);
	return (path);
}

void	delete_paths_from_paths(t_link **paths, t_del *del_links)
{
	t_del	*temp_del;
	int		prev_del_path;

	temp_del = del_links;
	prev_del_path = 0;
	while (temp_del)
	{
		if (prev_del_path != temp_del->path_id)
		{
			*paths = delete_path(*paths, temp_del->path_id);
			prev_del_path = temp_del->path_id;
		}
		temp_del = temp_del->next;
	}
}
