#include "lem-in.h"

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
		ft_printf("%s dist = %d\n", lemin->rooms[i]->name, lemin->rooms[i]->dist);
		i++;
	}
	ft_putendl("");
}

static void		print_path(t_link *path)
{
	if (!path)
		return ;
	ft_putendl(path->name);
	print_path(path->next);
}

void		lemin(char *file)
{
	t_lemin *lemin;
	t_link	*path;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	get_file_info(lemin, file);
	set_dist(lemin);
	path = shortest_path(lemin->start, lemin->end);
	print_file(file);
	move_ants(lemin, path);

	// print_links(lemin->rooms[0]->link);
	// print_dist(lemin);
	// print_path(path);
}
