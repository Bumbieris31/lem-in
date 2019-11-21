/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:03:49 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/21 13:04:55 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int			valid_room(char **room_info)
{
	int len;
	int i;

	len = 0;
	if (!room_info || !*room_info || room_info[0][0] == 'L')
		return (ROOM_ERROR);
	while (room_info[len])
	{
		len++;
		if (!room_info[len])
			break ;
		i = 0;
		while (room_info[len][i])
		{
			if (!ft_isdigit(room_info[len][i]))
				return (ROOM_ERROR);
			i++;
		}
	}
	return (len != 3 ? ROOM_ERROR : 1);
}

static t_room		*get_room(t_lemin *lemin, char *line)
{
	t_room		*room;
	char		**room_info;
	char		*name;
	t_point		coord;
	static int	id;

	room_info = ft_strsplit(line, ' ');
	error_check(valid_room(room_info));
	name = room_info[NAME];
	coord = (t_point){ft_atoi(room_info[X]), ft_atoi(room_info[Y])};
	if (duplicate_room(lemin->rooms, name, coord, id))
		error_check(DUP_ERROR);
	lemin->rooms[id] = new_room(ft_strdup(name), id, -1);
	id++;
	ft_free_2darray((void**)room_info);
	return (lemin->rooms[id - 1]);
}

static void			set_start_end(t_lemin *lemin, char *cmnd, t_list **file)
{
	*file = (*file)->next;
	if (ft_strequ(cmnd, "##start"))
		lemin->start = get_room(lemin, (char*)(*file)->content);
	else
		lemin->end = get_room(lemin, (char*)(*file)->content);
}

static t_list		*copy_map(t_lemin *lemin, int *size)
{
	char	*line;
	t_list	*copy;

	ft_get_next_line(0, &line);
	lemin->ants = ft_atoi(line);
	if (!lemin->ants || ft_strlen(line) != ft_intlen(lemin->ants))
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

void				get_map_info(t_lemin *lemin)
{
	t_list	*con;
	t_list	*copied_map;
	t_list	*tmp;
	char	*line;

	copied_map = copy_map(lemin, &lemin->size);
	con = NULL;
	tmp = copied_map;
	lemin->rooms = (t_room**)ft_memalloc(sizeof(t_room*) * (lemin->size + 1));
	while (tmp)
	{
		line = (char*)tmp->content;
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			set_start_end(lemin, line, &tmp);
		else if (line[0] == '#')
			;
		else if (ft_strchr(line, '-'))
			ft_lstadd(&con, ft_lstnew(line, ft_strlen(line) + 1));
		else
			get_room(lemin, line);
		tmp = tmp->next;
	}
	init_conncections(lemin, &con);
	lemin->map = copied_map;
}
