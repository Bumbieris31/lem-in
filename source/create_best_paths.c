/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_best_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:54:57 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/20 21:24:33 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	recreate_path(t_link **new_paths, int id)		//id not needed?
{
	t_link	*paths;

	paths = *new_paths;
	if (!paths)
		paths = MEM(t_link);
	else
	{
		while (paths && paths->next)
			paths = paths->next;
		paths->next = MEM(t_link);
		ft_printf("path id: %d", paths->id);
		paths = paths->next;
	}
	paths->next = 0;
	paths->id = id;
	ft_printf("final path id: %d", paths->id);
}

t_room	*make_room(int id, t_room **rooms)
{
	t_room *room;

	room = MEM(t_room);
	room->name = rooms[id]->name;
	room->dist = -1;
	room->ant = 0;
	room->id = id;
	return (room);
}

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

void	recreate_rooms(t_link *paths, t_lemin *lemin, int i, int j)
{
	t_room	*room;

	while (paths && paths->next)
	{
		ft_printf("paths id: %d\n", paths->id);
		paths = paths->next;
	}
	paths->ptr = make_room(lemin->winner_ids[i][j], lemin->rooms);
	room = paths->ptr;
	j++;
	while (lemin->winner_ids[i][j] != lemin->end->id)
	{
		room->to = make_room(lemin->winner_ids[i][j], lemin->rooms);
		room = room->to;
		j++;
	}
	room->to = make_room(lemin->winner_ids[i][j], lemin->rooms);
	paths->on = new_paths_len(paths->ptr);
	ft_printf("path len: %d", paths->on);
	exit(0);
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
		recreate_path(&paths, i);
		j = 0;
		recreate_rooms(paths, lemin, i, j);
		i++;
	}
	return (paths);
}
