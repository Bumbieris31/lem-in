#include "lem-in.h"
#include "libft.h"
#include "ft_printf.h"

void		lemin(char *file)
{
	t_lemin *lemin;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	lemin->table = (t_room**)ft_memalloc(sizeof(t_room*) * 10000);
	get_file_info(lemin, file);
	print_file(file);
	// while (1)
	// 	;
}
