#include "lem-in.h"

void	write_path(t_room *room, int *path_ids, int len)
{
	int	i;

	path_ids[0] = len;
	i = 1;
	while (i <= len)
	{
		path_ids[i] = room->id;
		i++;
		room = room->to;
	}
}

/*
** @descr: Saves the id values of every path in a 2d int array.
*/

static int	**save_path_ids(t_link *paths, int path_count)
{
	int	i;
	int	**path_ids;

	i = 0;
	path_ids = (int**)ft_memalloc(sizeof(int*) * (path_count + 1));
	while (paths)
	{
		path_ids[i] = (int*)ft_memalloc(sizeof(int) * (paths->on + 1));
		write_path(paths->ptr, path_ids[i], paths->on);
		i++;
		paths = paths->next;
	}
	return (path_ids);
}

/*
** @descr: Bubble sort.
*/

static int	**sort_winner_ids(int **winner_ids)
{
	int i;
	int	*swap;

	i = 0;
	while (winner_ids[i + 1])
	{
		if (winner_ids[i][0] > winner_ids[i + 1][0])
		{
			swap =  winner_ids[i + 1];
			winner_ids[i + 1] = winner_ids[i];
			winner_ids[i] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (winner_ids);
}

void		count_lines(t_lemin *lemin)
{
	int		lines;
	int		path_count;
	t_link	*path;

	path = PATHS;
	lines = lemin->ants;
	path_count = 0;
	while (path)
	{
		path_count++;
		lines += path->on - 1;
		path = path->next;
	}
	lines = ((double)lines / path_count) + 0.5;
	if (lemin->lines == 0 || lines < lemin->lines)
	{
		lemin->lines = lines;
		if (lemin->winner_ids)
			free_winner_ids(lemin->winner_ids);
		lemin->winner_ids = save_path_ids(PATHS, path_count);
		lemin->paths_used = path_count; //////////
	}
	lemin->paths_found = path_count; //////////
	lemin->winner_ids = sort_winner_ids(lemin->winner_ids);
}
