/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_best_paths_new.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 15:49:16 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/27 16:10:17 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		new_paths_len(t_room *room)
{
	int	i;

	i = 1;
	while (room->to)
	{
		i++;
		room = room->to;
	}
	return (i);
}

void	recreate_path(t_link **paths, int id, int len)
{
	if (!*paths)
	{
		(*paths) = MEM(t_link);
		(*paths)->id = id;
		(*paths)->on = len;
		return ;
	}
	else
		recreate_path(&(*paths)->next, id, len);
}

void	recreate_rooms(t_link **paths, t_lemin *lemin, int i)
{
	t_link	*node;
	t_room	*room;
	int		j;
	int		id;

	j = 1;
	node = *paths;
	while (node->next)
		node = node->next;
	id = lemin->winner_ids[i][j];
	node->ptr = new_room(ROOMS[id]->name, id, -1);
	room = node->ptr;
	while (lemin->winner_ids[i][j] != END->id)
	{
		j++;
		id = lemin->winner_ids[i][j];
		room->to = new_room(ROOMS[id]->name, id, -1);
		room = room->to;
	}
	node->on = new_paths_len(node->ptr);
}

t_link	*create_best_paths_new(t_lemin *lemin)
{
	int		i;
	t_link	*paths;

	i = 0;
	paths = 0;
	while (lemin->winner_ids[i])
	{
		recreate_path(&paths, i, lemin->winner_ids[i][0]);
		recreate_rooms(&paths, lemin, i);
		i++;
	}
	return (paths);
}
