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

void		lemin(char *file)
{
	t_lemin *lemin;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	lemin->table = (t_room**)ft_memalloc(sizeof(t_room*) * TABLE_SIZE);
	get_file_info(lemin, file);
	make_connect(lemin->connections, lemin->table);
<<<<<<< HEAD
	measure_distance(lemin);
	print_file(file);
//	print_connect(lemin);
=======
	// measure_distance();
	// print_file(file);
	// print_connect(lemin);
>>>>>>> 52ca864a51bc6e2fd8609703515399507d8d899f
}
