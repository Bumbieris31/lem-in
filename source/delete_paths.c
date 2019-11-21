/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_paths_from_paths.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:28:31 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/20 14:24:33 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_link	*delete_path(t_link *path, int path_id)
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
