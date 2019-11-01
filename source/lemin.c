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
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		t_room *tmp = lemin->table[i];
		while (tmp)
		{
			ft_printf("%s : dist = %d\n", tmp->name, tmp->dist);
			tmp = tmp->next;
		}
	}
}

static void		print_path(t_link *path)
{
	if (!path)
		return ;
	print_path(path->next);
	ft_putendl(path->name);
}

void		lemin(char *file)
{
	t_lemin *lemin;
	t_link	*path;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	lemin->table = (t_room**)ft_memalloc(sizeof(t_room*) * TABLE_SIZE);
	get_file_info(lemin, file);
	make_connect(lemin->connections, lemin->table);
	set_dist(lemin);
	path = shortest_path(lemin);
	// print_file(file);
	print_path(path);
}
