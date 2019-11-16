#include "lem-in.h"

/* *************** DEBUG ****************** */
static void print_links(t_lemin *lemin)
{
	ft_putendl("*--------*");
	for (int i = 0; i < lemin->size; i++)
	{
		t_link *link;
		link = ROOMS[i]->link;
		ft_putendl(ROOMS[i]->name);
		while (link)
		{
			if (link->on)
				ft_printf("\t-> %s\n", link->name);
			link = link->next;
		}
	}
	ft_putendl("*--------*");
}

void		print_dist(t_lemin *lemin)
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
	ft_printf("%-5s --> %-3s : %d\n", start, tmp->name, path->id);
	while (tmp->id != end->id)
	{
		ft_printf("%-5s --> ", tmp->name);
		tmp = tmp->to;
		// if (tmp->id == end->id)
		// 	break ;
		ft_printf("%-3s : %d\n", tmp->name, path->id);
	}
	ft_putendl("");
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

static void		print_del_links(t_lemin *lemin)
{
	t_del *tmp = lemin->del_links;
	while (tmp)
	{
		ft_printf("room1 %s, room2 %s, path_id %d\n", ROOMS[tmp->room1]->name, ROOMS[tmp->room2]->name, tmp->path_id);
		tmp = tmp->next;
	}
}

static void print_rooms(t_lemin *lemin)
{
	for (int i = 0; i < lemin->size; i++)
		ft_printf("%s : %d\n", ROOMS[i]->name, ROOMS[i]->path);
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

void		lemin(void)
{
	t_lemin *lemin;

	lemin = MEM(t_lemin);
	get_map_info(lemin);
	PATHS = get_path(lemin);
	if (!PATHS)
		error_check(NO_PATH_ERROR);
	PATHS->id = 1;
	find_solution(lemin);
	print_all_paths(PATHS, END, START->name);
	// print_map(&lemin->map, lemin->ants);
	// print_winner();
	// free_lemin_struct(lemin);
}
