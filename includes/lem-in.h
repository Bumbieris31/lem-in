
#ifndef LEM_IN_H
# define LEM_IN_H

# define PRINT			1
# define DONT_PRINT		0

# define MEM(x)			(x*)ft_memalloc(sizeof(x))
# define START			lemin->start
# define END			lemin->end
# define ROOMS			lemin->rooms
# define PATHS			lemin->paths
# define WINNER			lemin->winner

# include "libft.h"
# include "ft_printf.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef enum		e_value
{
	NAME =			0,
	X =				1,
	Y =				2,
	ROOM1 =			0,
	ROOM2 =			1,
	ON =			1,
	OFF =			0,
	ROOM_ERROR =	-1,
	DUP_ERROR =		-2,
	ANTS_ERROR =	-3,
	CONN_ERROR =	-4,
	NO_PATH_ERROR =	-5
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
	struct s_room	*branch;
	struct s_link	*link;
}					t_room;

typedef struct		s_del
{
	int				room1;
	int				room2;
	int				path_id;
	struct s_del	*next;
}					t_del;

typedef struct		s_link
{
	int				on;
	int				id;
	char			*name;
	t_room			*ptr;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	int				lines;
	t_link			*winner;
}					t_path;


typedef struct		s_lemin
{
	int 			ants;
	int				size;
	int				**winner_ids;
	t_path			*winner;
	t_del			*del_links;
	t_list			*map;
	t_link			*paths;
	t_room			**rooms;
	t_room			*start;
	t_room			*end;
}					t_lemin;

void				lemin(char *file);
void				error_check(int error);
void				free_paths(t_link *paths);
void				reset_rooms(t_room **rooms);
void				count_lines(t_lemin *lemin);
void				get_map_info(t_lemin *lemin);
void				free_path_rooms(t_room *room);
void				find_solution(t_lemin *lemin);
void				print_map(t_list **map, int ants);
void				free_del_links(t_del **del_links);
void				free_lemin_struct(t_lemin	*lemin);
void				add_room(t_room **head, t_room *new);
void				add_links(t_room **rooms, t_del *del_links);
void				add_links_back(t_room **rooms, t_del *del_links);
void				make_connect(char **connections, t_room *table[]);
void				save_links_to_delete(t_lemin *lemin, t_room *path);
void				breadth_first(t_room **rooms, t_room *end, int start);
void				delete_paths_from_paths(t_link **paths, t_del *del_links);
void				switch_link_on_off(t_link *link, int del_link, int on_off);
void				add_to_paths(t_link **paths, t_link *new_path, int path_id);
void				reset_overlap(t_room **rooms, t_link *paths, t_del *del_links);

t_link				*get_path(t_lemin *lemin);
t_link				*create_best_paths(t_lemin *lemin);

t_room				*new_room(char *name, t_point coord, int id);
t_room				*add_to_hastable(t_room **table, t_room *new, size_t index);

int					move_ants_in_all_paths(t_lemin *lemin, int print);
int					duplicate_room(t_room **rooms, char *name,
					t_point coord, int size);
int					**check_paths_save_winner(t_lemin *lemin);
int					**save_path_ids(t_link *paths);


/* ************ DEBUG ************ */

void		print_links(t_lemin *lemin);
void		print_dist(t_lemin *lemin);
void		print_path(t_link *path, t_room *end, char *start);
void		print_all_paths(t_link *paths, t_room *end, char *start);
void		print_del_links(t_lemin *lemin);
void		print_rooms(t_lemin *lemin);

/* ******************************* */
#endif
