/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:03:49 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/27 17:04:41 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*get_room(t_lemin *lemin, char *line, t_list *con)
{
	char		**room_info;
	char		*name;
	t_point		coord;
	static int	id;

	if (con)
		error_check(FILE_ERROR);
	room_info = ft_strsplit(line, ' ');
	error_check(valid_room(room_info));
	name = room_info[NAME];
	coord = (t_point){ft_atoi(room_info[X]), ft_atoi(room_info[Y])};
	if (duplicate_room(lemin->rooms, name, coord, id))
		error_check(DUP_ERROR);
	lemin->rooms[id] = new_room(ft_strdup(name), id, -1);
	lemin->rooms[id]->coord = coord;
	id++;
	ft_free_2darray((void**)room_info);
	return (lemin->rooms[id - 1]);
}

static void		set_startend(t_lemin *lemin, char *cmnd,
				t_list **file, t_list *con)
{
	*file = (*file)->next;
	while (((char*)(*file)->content)[0] == '#')
		*file = (*file)->next;
	if (ft_strequ(cmnd, "##start"))
	{
		if (START)
			error_check(ROOM_ERROR);
		START = get_room(lemin, (char*)(*file)->content, con);
	}
	else
	{
		if (END)
			error_check(ROOM_ERROR);
		END = get_room(lemin, (char*)(*file)->content, con);
	}
}

static t_list	*copy_map(t_lemin *lemin, int *size)
{
	char	*line;
	t_list	*copy;

	ft_get_next_line(0, &line);
	if (!line)
		error_check(FILE_ERROR);
	while (line[0] == '#')
	{
		free(line);
		ft_get_next_line(0, &line);
	}
	lemin->ants = ft_atoi(line);
	if (lemin->ants <= 0 || ft_strlen(line) != ft_intlen(lemin->ants))
		error_check(ANTS_ERROR);
	free(line);
	copy = NULL;
	while (ft_get_next_line(0, &line))
	{
		if (line[0] != '#' && !ft_strchr(line, '-'))
			(*size)++;
		ft_lstadd_back(&copy, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	return (copy);
}

void			get_map_info(t_lemin *lemin)
{
	t_list	*con;
	t_list	*tmp;
	char	*line;

	lemin->map = copy_map(lemin, &lemin->size);
	if (!lemin->size)
		error_check(FILE_ERROR);
	con = NULL;
	tmp = lemin->map;
	lemin->rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (lemin->size + 1));
	while (tmp)
	{
		line = (char*)tmp->content;
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			set_startend(lemin, line, &tmp, con);
		else if (ft_strchr(line, '-'))
			ft_lstadd(&con, ft_lstnew(line, ft_strlen(line) + 1));
		else if (line[0] != '#')
			get_room(lemin, line, con);
		tmp = tmp->next;
	}
	init_conncections(lemin, &con);
}
