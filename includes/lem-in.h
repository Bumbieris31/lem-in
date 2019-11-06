
#ifndef LEM_IN_H
# define LEM_IN_H

# define FD_ERROR		-1
# define ROOM_ERROR		-2
# define DUP_ERROR		-3
# define ANTS_ERROR		-4
# define CONN_ERROR		-5
# define NO_PATH_ERROR	-6

# define MEM(x)			(x*)ft_memalloc(sizeof(x))
# define START			lemin->start
# define END			lemin->end
# define ROOMS			lemin->rooms

# include "libft.h"
# include "ft_printf.h"
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

typedef enum		e_value
{
	NAME =			0,
	X =				1,
	Y =				2,
	ROOM1 =			0,
	ROOM2 =			1
}					t_value;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	int				dist;
	int				ant;
	int				id;
	int				path;
	int				visited;
	char			*name;
	t_point			coord;
	struct s_room	*to;
	struct s_room	*from;
	struct s_link	*link;
}					t_room;

typedef struct		s_path
{
	int				len;	// ARE WE USING THIS??? could all be the same struct
	t_room			*ptr;
	struct s_path	*next;
}					t_path;

typedef struct		s_link
{
	int				id;		// ARE WE USING THIS??? could all be the same struct
	char			*name;	// ARE WE USING THIS??? could all be the same struct
	t_room			*ptr;
	struct s_link	*next;
}					t_link;

typedef struct		s_lemin
{
	int 			ants;
	int				size;
	t_room			**rooms;
	t_room			*start;
	t_room			*end;
	t_path			*paths;
}					t_lemin;

void				lemin(char *file);
void				print_file(char *file);
void				error_check(int error);
void				add_room(t_room **head, t_room *new);
void				move_ants(t_lemin *lemin, t_link *path);
void				get_file_info(t_lemin *lemin, char *file);
void				make_connect(char **connections, t_room *table[]);
void				breadth_first(t_room **rooms, t_room *end);

t_path				*shortest_path(t_room **rooms, t_room *start, t_room *end);

t_room				*add_to_hastable(t_room **table, t_room *new, size_t index);
t_room				*new_room(char *name, t_point coord, int id);

int					duplicate_room(t_room **rooms, char *name,
					t_point coord, int size);

#endif
