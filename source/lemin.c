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
		ft_printf("%s dist = %d\n", lemin->rooms[i]->name, lemin->rooms[i]->dist);
		i++;
	}
	ft_putendl("");
}

static void		print_path(t_room *room)
{
	if (!room)
		return ;
	ft_printf("%s --> %s\n", room->from->name, room->name);
	print_path(room->to);
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
	t_path	*paths;

	lemin = (t_lemin*)ft_memalloc(sizeof(t_lemin));
	get_file_info(lemin, file);
	paths = shortest_path(lemin->rooms, START, END);
	// print_file(file);
	// move_ants(lemin, path);

	breadth_first(START->id, END->id, lemin->rooms, &paths);

	// print_rooms(lemin->rooms);
	// print_links(lemin->rooms[0]->link);
	print_dist(lemin);
	// print_path(paths->ptr);
}
