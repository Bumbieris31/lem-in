#include "lem-in.h"

/* *************** DEBUG ****************** */
static void		print_links(t_link *link)
{
	if (!link)
		return ;
	print_links(link->next);
	ft_printf("%s\n", link->name);
}

static void		print_dist(t_lemin *lemin)
{
	int i = 0;

	while (lemin->rooms[i])
	{
		ft_printf("%-5s dist = %-2d %d\n", lemin->rooms[i]->name, lemin->rooms[i]->dist, lemin->rooms[i]->path);
		i++;
	}
	ft_putendl("");
}

void		print_path(t_link *path, t_room *end, char *start)
{
	t_room *tmp;

	if (!path)
	{
		ft_putendl("NO PATH");
		return ;
	}
	tmp = path->ptr;
	ft_printf("%-5s --> %s : %d\n", start, tmp->name, path->id);
	while (tmp->id != end->id)
	{
		ft_printf("%-5s --> ", tmp->name);
		tmp = tmp->to;
		if (tmp->id == end->id)
			break ;
		ft_printf("%s : %d\n", tmp->name, path->id);
	}
	ft_printf("%s\n\n", end->name);
}

void			print_all_paths(t_link *paths, t_room *end, char *start)
{
	t_link *path;

	path = paths;
	while (path)
	{
		print_path(path, end, start);
		path = path->next;
	}
}

static void		print_rooms(t_room **rooms)
{
	int i = 0;
	while (rooms[i])
	{
		ft_printf("ROOM : %s, ID : %d\n", rooms[i]->name, rooms[i]->id);
		i++;
	}
}
/* *************************************** */

void	add_to_paths(t_link **paths, t_link *new_path, int path_id)
{
	if (!paths || !new_path)
		return ;
	new_path->next = *paths;
	*paths = new_path;
	(*paths)->id = path_id;
}

void		lemin(char *file)
{
	t_lemin *lemin;

	lemin = MEM(t_lemin);
	get_file_info(lemin, file);
	PATHS = get_path(lemin);
	if (!PATHS)
		error_check(NO_PATH_ERROR);
	PATHS->id = 1;
	find_solution(lemin);
	print_all_paths(PATHS, END, START->name);

	// printt_file();
	// print_winner();
	// free_lemin_struct(lemin);
}
