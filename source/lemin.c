/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:08:59 by fhignett          #+#    #+#             */
/*   Updated: 2019/11/25 13:19:08 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		set_path_id(t_link *paths, t_room **rooms, int end, int start)
{
	t_link	*path;
	t_room	*room;
	int		cur;
	int		nxt;

	path = paths;
	while (path)
	{
		room = path->ptr;
		cur = room->id;
		if (rooms[cur]->path != path->id)
		{
			rooms[cur]->from = rooms[start];
			while (room->id != end)
			{
				nxt = room->to->id;
				rooms[cur]->path = path->id;
				rooms[cur]->to = rooms[nxt];
				rooms[nxt]->from = rooms[cur];
				room = room->to;
				cur = nxt;
			}
		}
		path = path->next;
	}
}

t_link			*get_path(t_lemin *lemin)
{
	t_link		*path;
	int			cur;
	int			nxt;

	set_path_id(PATHS, ROOMS, END->id, START->id);
	breadth_first(ROOMS, END, START->id);
	if (START->dist == -1)
		return (NULL);
	path = MEM(t_link);
	path->ptr = get_starting_room(START->link, START->dist);
	get_new_path(&path->ptr, lemin);
	path->on = START->dist;
	reset_rooms(ROOMS);
	return (path);
}

static void		lemin(void)
{
	t_lemin *lemin;

	lemin = MEM(t_lemin);
	get_map_info(lemin);
	PATHS = get_path(lemin);
	if (!PATHS)
		error_check(NO_PATH_ERROR);
	PATHS->id = 1;
	if (PATHS->ptr->id == END->id)
	{
		START->to = END;
		START->path = 1;
	}
	count_lines(lemin);
	if (lemin->ants > 1)
		find_solution(lemin);
	print_map(&lemin->map, lemin->ants);
	move_ants_in_all_paths(lemin);
	// ft_printf("TOTAL PATHS FOUND : %-2d, TOTAL PATHS USED : %-2d, ANTS : %-3d, LINES : %-2d\n", lemin->paths_found, lemin->paths_used, lemin->ants, lemin->lines);
	free_lemin_struct(&lemin);
	// print_winner_ids(ROOMS, lemin->winner_ids, START->id, END->id);
}

int				main(int argc, char **argv)
{
	if (argc == 2 && ft_strequ("--help", argv[1]))
		ft_putendl("Print help");
	else
		lemin();
	return (0);
}
