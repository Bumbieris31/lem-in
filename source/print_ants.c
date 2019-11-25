#include "lem-in.h"

/* DELETE WAS JUST A TEST */

static int		check_ant(t_room *from, t_room *to)
{
	if (!from->ant)
		return (0);
	ft_printf("L%d-%s ", from->ant, to->name);
	return (1);
}

static void		check_start_ant(t_room *start, t_room *to, int ants)
{
	int ant_id;

	if (!start->ant)
		return ;
	ant_id = (ants - start->ant) + 1;
	ft_printf("L%d-%s ", ant_id, to->name);
	start->ant--;
	to->ant = ant_id;
}

static void		move_ant(t_room *from, t_room *to, t_room *end)
{
	if (to->id == end->id)
		end->ant++;
	else
		to->ant = from->ant;
	from->ant = 0;
}

static void		move_ants(int *path, t_room **rooms, t_room *start, t_room *end, int ants)
{
	int i;
	int	from;
	int	to;

	i = path[0];
	while ( i > 1)
	{
		to = path[i];
		from = path[i - 1];
		if (check_ant(rooms[from], rooms[to]))
			move_ant(rooms[from], rooms[to], end);
		i--;
	}
	check_start_ant(start, rooms[path[i]], ants);
}

void			print_ants(t_lemin *lemin)
{
	int path;

	START->ant = lemin->ants;
	while (END->ant != lemin->ants)
	{
		path = 0;
		while (lemin->winner_ids[path])
		{
			move_ants(lemin->winner_ids[path], ROOMS, START, END, lemin->ants);
			path++;
		}
		ft_putendl("");
	}
}
