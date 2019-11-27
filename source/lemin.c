/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lemin.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 15:51:22 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/27 16:13:43 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

	set_path_id(PATHS, ROOMS, END->id, START->id);
	breadth_first(END, START->id);
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
	free_lemin_struct(&lemin);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_printf("%s < [file]\n", argv[0]);
	else
		lemin();
	return (0);
}
