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

static void		print_path(t_link *path, t_room *end, char *start)
{
	t_room *tmp;

	if (!path)
	{
		ft_putendl("NO PATH");
		return ;
	}
	tmp = path->ptr;
	ft_printf("%-5s --> %s : %d\n", start, tmp->name, tmp->dist);
	while (tmp->id != end->id)
	{
		ft_printf("%-5s --> ", tmp->name);
		tmp = tmp->to;
		if (tmp->id == end->id)
			break ;
		ft_printf("%s : %d\n", tmp->name, tmp->dist);
	}
	ft_printf("%s\n\n", end->name);
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

void		lemin(char *file)
{
	t_lemin *lemin;

	lemin = MEM(t_lemin);
	get_file_info(lemin, file);
	PATHS = get_path(lemin);
	if (!PATHS)
		error_check(NO_PATH_ERROR);
	print_dist(lemin);
	print_path(PATHS, END, START->name);

	PATHS->next = get_path(lemin); /* GIVES NULL IF CAN'T FIND AN EXTRA PATH */
	print_dist(lemin);
	print_path(PATHS->next, END, START->name);

	// PATHS->next->next = get_path(lemin); /* GIVES NULL IF CAN'T FIND AN EXTRA PATH */
	// print_dist(lemin);
	// print_path(PATHS->next->next, END, START->name);
}
