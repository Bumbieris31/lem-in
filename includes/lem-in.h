
#ifndef LEM_IN_H
# define LEM_IN_H

# define FD_ERROR	-1
# define ROOM_ERROR	-2
# define DUP_ERROR	-3
# define ANTS_ERROR	-4

# define TABLE_SIZE	10000

# include <string.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	int				dist;
	int				ant_count;
	char			*name;
	t_point			coord;
	struct s_room	*next;
	struct s_link	*link;
}					t_room;

typedef struct		s_link
{
	char			*name;
	t_room			*ptr;
	struct s_link	*next;
}					t_link;

typedef struct		s_lemin
{
	int 			ants;
	char 			**connections;
	t_room			**table;
	t_room			*start;
	t_room			*end;
}					t_lemin;



void				lemin(char *file);
void				print_file(char *file);
void				error_check(int error);
void				add_room(t_room **head, t_room *new);
void				get_file_info(t_lemin *lemin, char *file);
void				make_connect(char **connections, t_room *table[]);

t_room				*add_to_hastable(t_room **table, t_room *new, size_t index);
t_room				*new_room(char *name, t_point coord);

int					duplicate_room(t_room **table, char *name,
					t_point coord, size_t index);

size_t				hashing_funct(char *str);

#endif