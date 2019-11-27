/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:06:43 by fhignett          #+#    #+#             */
/*   Updated: 2019/11/27 20:50:14 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define MEM(x)			(x*)ft_memalloc(sizeof(x))
# define START			lemin->start
# define END			lemin->end
# define ROOMS			lemin->rooms
# define PATHS			lemin->paths

# include "libft.h"
# include "ft_printf.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef enum		e_value
{
	NAME = 0,
	X = 1,
	Y = 2,
	ROOM1 = 0,
	ROOM2 = 1,
	ON = 1,
	OFF = 0,
	ROOM_ERROR = -1,
	DUP_ERROR = -2,
	ANTS_ERROR = -3,
	CONN_ERROR = -4,
	NO_PATH_ERROR = -5,
	FILE_ERROR = -6
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

typedef struct		s_lemin
{
	int				ants;
	int				size;
	int				**winner_ids;
	int				overlap;
	int				lines;
	int				paths_found;
	int				paths_used;
	t_list			*map;
	t_link			*paths;
	t_room			**rooms;
	t_room			*start;
	t_room			*end;
}					t_lemin;

void				error_check(int error);
void				free_t_link(t_link *link);
void				free_paths(t_link *paths);
void				reset_rooms(t_room **rooms);
void				count_lines(t_lemin *lemin);
void				get_map_info(t_lemin *lemin);
void				free_path_rooms(t_room *room);
void				find_solution(t_lemin *lemin);
void				free_winner_ids(int **winner_ids);
void				print_map(t_list **map);
void				free_lemin_struct(t_lemin **lemin);
void				breadth_first(t_room *end, int start);
void				reset_path(t_room **rooms, t_room *path);
void				get_new_path(t_room **path, t_lemin *lemin);
void				split_links(t_link *new_path, t_lemin *lemin);
void				init_conncections(t_lemin *lemin, t_list **con);
void				turn_all_links_on_off(t_room **rooms, int size, int on_off);

t_link				*get_path(t_lemin *lemin);
t_link				*create_best_paths_new(t_lemin *lemin);
t_link				*delete_path(t_link *path, int path_id);

t_room				*new_room(char *name, int id, int dist);
t_room				*get_starting_room(t_link *link, int dist);

int					only_digits(char *str);
int					valid_room(char **room_info);
int					move_ants_in_all_paths(t_lemin *lemin);
int					duplicate_room(t_room **rooms, char *name,
					t_point coord, int size);

#endif
