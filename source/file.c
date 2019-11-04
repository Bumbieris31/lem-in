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
	t_room	*room;
	size_t	index;
	char	**room_info;
	char	*name;
	t_point	coord;

	room_info = ft_strsplit(line, ' ');
	error_check(valid_room(room_info));
	name = room_info[NAME];
	coord = (t_point){ft_atoi(room_info[X]), ft_atoi(room_info[Y])};
	index = hashing_funct(name);
	if (duplicate_room(lemin->table, name, coord, index))
		error_check(DUP_ERROR);
	room = add_to_hastable(lemin->table, new_room(name, coord), index);
	ft_free_2darray((void**)room_info);
	return(room);
}

/*
** Sets Start and End pointers to the correct rooms
*/

static void			set_start_end(t_lemin *lemin, char *cmnd, int fd)
{
	char	*line;

	ft_get_next_line(fd, &line);
	if (ft_strequ(cmnd, "##start"))
		lemin->start = get_room(lemin, line);
	else
		lemin->end = get_room(lemin, line);
	free(line);
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
	make_connect(connections, lemin->table);
	ft_free_2darray((void**)connections);

}

/*
** Reads the given file line by line and gets the room info
*/

void				get_file_info(t_lemin *lemin, char *file)
{
	int		fd;
	char	*line;
	t_list	*con;

	fd = open(file, O_RDONLY);
	error_check(fd);
	get_ants(lemin, fd);
	con = NULL;
	while (ft_get_next_line(fd, &line))
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			set_start_end(lemin, line, fd);
		else if (line[0] == '#')
			;
		else if (ft_strchr(line, '-'))
			 ft_lstadd(&con, ft_lstnew(line, ft_strlen(line) + 1));
		else
			get_room(lemin, line);
		free(line);
	}
	close(fd);
	init_conncections(lemin, &con);
}
