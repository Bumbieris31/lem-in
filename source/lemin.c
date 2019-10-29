#include "lem-in.h"
#include "libft.h"
#include "ft_printf.h"

/* DELETE LATER */
static void	info_lemin(t_lemin *lemin)
{
	ft_printf("Ants: %d\n\n", lemin->ants);
	ft_printf("Rooms:\n");
	print_rooms(lemin->rooms);
	ft_putendl("");
	if (lemin->start)
		ft_printf("start:\n%-5s %-2d %d\n", lemin->start->name, lemin->start->coord.x, lemin->start->coord.y);
	if (lemin->end)
		ft_printf("end:\n%-5s %-2d %d\n", lemin->end->name, lemin->end->coord.x, lemin->end->coord.y);
	
	int i = 0;
	while (lemin->connections[i])
		ft_putendl(lemin->connections[i++]);
}

void		lemin(char *file)
{
	t_lemin *lemin;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	get_file_info(lemin, file);



	info_lemin(lemin); /* DELETE LATER */
}
