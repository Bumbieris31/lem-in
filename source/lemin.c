#include "lem-in.h"
#include "libft.h"
#include "ft_printf.h"

/* TESTING CONNECTIONS
*/
static void	print_connect(t_lemin *lemin)
{
	t_room	*room;
	t_link	*link;
	char	*str = "hop";
	int		ind;

	ind = hashing_funct(str);
	room = lemin->table[ind];
	link = room->link;
	while (link)
	{
		ft_printf("\n%s\n", link->ptr->name);
		link = link->next;
	}
}

void		lemin(char *file)
{
	t_lemin *lemin;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	lemin->table = (t_room**)ft_memalloc(sizeof(t_room*) * 10000);
	get_file_info(lemin, file);
	make_connect(lemin->connections, lemin->table);
	print_file(file);
	print_connect(lemin);
	// while (1)
	// 	;
}
