#include "lem-in.h"

/*
** Checks if it's a valid room
*/

static int			valid_room(char **room_info)
{
	int len;
	int i;

	len = 0;
	if (!room_info || !*room_info)
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

/*
** Gets room info and makes a room struct and puts it in the hashtable
*/

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
	lemin->rooms[id] = new_room(name, coord, id);
	id++;
	ft_free_2darray((void**)room_info);
	return(lemin->rooms[id - 1]);
}

/*
** Sets Start and End pointers to the correct rooms
*/

static void			set_start_end(t_lemin *lemin, char *cmnd, t_list **file)
{
	*file = (*file)->next;
	if (ft_strequ(cmnd, "##start"))
		lemin->start = get_room(lemin, (char*)(*file)->content);
	else
		lemin->end = get_room(lemin, (char*)(*file)->content);
}

/*
** Gets the amount of ants
*/

static void			get_ants(t_lemin *lemin, int fd)
{
	char *line;

	ft_get_next_line(fd, &line);
	lemin->ants = ft_atoi(line);
	if (!lemin->ants || ft_strlen(line) != ft_intlen(lemin->ants))
		error_check(ANTS_ERROR);
	free(line);
}

/*
** Add connections to the rooms
*/

static void			init_conncections(t_lemin *lemin, t_list **con)
{
	char *tmp;
	char **connections;

	tmp = ft_lstfold(*con, " ");
	connections = ft_strsplit(tmp, ' ');
	free(tmp);
	ft_lstdel(con, ft_bzero);
	make_connect(connections, lemin->rooms);
	ft_free_2darray((void**)connections);

}

static t_list			*copy_map(t_lemin *lemin, int *size)
{
	char	*line;
	t_list	*copy;

	get_ants(lemin, 0);
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

/*
** Reads the given file line by line and gets the room info
*/

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
