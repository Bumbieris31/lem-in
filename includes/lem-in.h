
#ifndef LEM_IN_H
# define LEM_IN_H

# define FD_ERROR	-1
# define ROOM_ERROR	-2
# define DUP_ERROR	-3
# define ANTS_ERROR	-4

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	char			*name;
	t_point			coord;
	struct s_room	*next;
}					t_room;


typedef struct		s_lemin
{
	int 			ants;
	char 			**connections;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
}					t_lemin;

void				lemin(char *file);
void				error_check(int error);
void				print_rooms(t_room *room);
void				add_room(t_room **head, t_room *new);
void				get_file_info(t_lemin *lemin, char *file);

int					coord_dup(t_room *rooms, t_point coord);

t_room				*new_room(char *name, t_point coord);
t_room				*room_exists(t_room *rooms, char *name);

#endif