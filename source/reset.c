/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 18:46:50 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/27 16:11:14 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		reset_path(t_room **rooms, t_room *path)
{
	if (!path)
		return ;
	reset_path(rooms, path->to);
	rooms[path->id]->to = NULL;
	rooms[path->id]->from = NULL;
	rooms[path->id]->path = 0;
}

void		reset_rooms(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->branch = NULL;
		rooms[i]->dist = -1;
		rooms[i]->visited = 0;
		i++;
	}
}

t_link		*delete_path(t_link *path, int path_id)
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
