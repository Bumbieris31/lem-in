#include "lem-in.h"

void		count_lines(t_lemin *lemin)
{
	int		lines;
	int		path_amount;
	t_link	*path;

	path = PATHS;
	lines = lemin->ants;
	path_amount = 0;
	while (path)
	{
		path_amount++;
		lines += path->on - 1;
		path = path->next;
	}
	lines = lines / path_amount;
	if (WINNER->lines == 0 || lines < WINNER->lines)
		lemin->winner->lines = lines;
}