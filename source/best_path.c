#include "lem-in.h"

static int	calc_longest_path(t_link *paths)
{
	t_link *path;
	int		longest_path;

	longest_path = 0;
	path = paths;
	while (path)
	{
		if (path->on > longest_path)
			longest_path = path->on;
		path = path->next;
	}
	return (longest_path);
}

void		count_lines(t_lemin *lemin)
{
	int		lines;
	int		longest_path;
	int		path_amount;
	t_link	*path;

	path = PATHS;
	lines = lemin->ants;
	longest_path = calc_longest_path(PATHS);
	path_amount = 0;
	while (path)
	{
		path_amount++;
		lines += longest_path - path->on;
		path = path->next;
	}
	lines = lines / path_amount;
	if (WINNER->lines == 0 || lines < WINNER->lines)
		lemin->winner->lines = lines;
}