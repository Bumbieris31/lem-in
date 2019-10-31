#include "lem-in.h"

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

static t_room		*get_room(t_lemin *lemin, char *line)
{
	t_room	*room;
	size_t	index;
	char	**room_info;
	char	*name;
	t_point	coord;

	room_info = ft_strsplit(line, ' ');
	error_check(valid_room(room_info));
	name = room_info[0];
	coord = (t_point){ft_atoi(room_info[1]), ft_atoi(room_info[2])};
	index = hashing_funct(name);
	if (duplicate_room(lemin->table, name, coord, index))
		error_check(DUP_ERROR);
	room = add_to_hastable(lemin->table, new_room(name, coord), index);
	ft_free_2darray((void**)room_info);
	return(room);
}

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

static void			get_ants(t_lemin *lemin, int fd)
{
	char *line;

	ft_get_next_line(fd, &line);
	lemin->ants = ft_atoi(line);
	free(line);
	if (!lemin->ants)
		error_check(ANTS_ERROR);
}

void				get_file_info(t_lemin *lemin, char *file)
{
	int		fd;
	char	*line;
	char	*tmp;
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
	tmp = ft_lstfold(con, " ");
	lemin->connections = ft_strsplit(tmp, ' ');
	free(tmp);
	ft_lstdel(&con, ft_bzero);
	close(fd);
}
