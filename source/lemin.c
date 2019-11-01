#include "lem-in.h"

/* TESTING CONNECTIONS
static void	print_connect(t_lemin *lemin)
{
	t_room	*room;
	t_link	*link;
	char	*str = "bam";
	int		ind;

	ind = hashing_funct(str);
	room = lemin->table[ind];
	link = room->link;
	while (link)
	{
		ft_printf("\n%s\n", link->name);
		if (link->next)
			link = link->next;
		else
			link = 0;
	}
}
*/

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

void				set_dist(t_lemin *lemin);
t_link				*shortest_path(t_lemin *lemin);

void		lemin(char *file)
{
	t_lemin *lemin;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	lemin->table = (t_room**)ft_memalloc(sizeof(t_room*) * TABLE_SIZE);
	get_file_info(lemin, file);
	make_connect(lemin->connections, lemin->table);
	set_dist(lemin);
	// measure_distance();
	// print_file(file);
	// print_connect(lemin);
	// print_links(lemin->start->link);
}
