/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_best_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:54:57 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/13 13:06:17 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/* Free lemin->paths before running this funct
*/

void	recreate_path(t_link *paths, int id)
{
	if (!paths)
		paths = (t_link*)malloc(sizeof(t_link));
	else
	{
		while (paths && paths->next)
			paths = paths->next;
		paths->next = (t_link*)malloc(sizeof(t_link));
		paths = paths->next;
	}
	paths->next = 0;
	paths->id = id;
}

t_room	*make_room(int id, t_room **rooms)
{
	t_room *room;

	room = (t_room*)malloc(sizeof(t_room));
	room->name = rooms[id]->name;
	room->dist = -1;
	room->ant = 0;
	room->id = id;
	return (room);
}

void	recreate_rooms(t_link *paths, t_lemin *lemin, int i, int j)
{
	t_room	*room;

	while (paths && paths->next)
		paths = paths->next;
	paths->ptr = make_room(lemin->winner_ids[i][j], lemin->rooms);
	room = paths->ptr;
	j++;
	while (lemin->winner_ids[i][j] != lemin->end->id)
	{
		room->to = make_room(lemin->winner_ids[i][j], lemin->rooms);
		room = room->to;
		j++;
	}
}

t_link	*create_best_paths(t_lemin *lemin)
{
	int		i;
	int		j;
	t_link	*paths;

	i = 0;
	paths = 0;
	while (lemin->winner_ids[i])
	{
		recreate_path(paths, i);
		j = 0;
		recreate_rooms(paths, lemin, i, j);
		i++;
	}
	return (paths);
}
