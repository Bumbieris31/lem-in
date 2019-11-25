#include "lem-in.h"

static void		add_to_paths(t_link **paths, t_link *new_path, int path_id)
{
	if (!paths || !new_path)
		return ;
	new_path->next = *paths;
	*paths = new_path;
	(*paths)->id = path_id;
}

static void		split_paths(t_link *new_path, t_lemin *lemin, int *path_id)
{
	turn_all_links_on_off(ROOMS, lemin->size, OFF);
	split_links(new_path, lemin);
	free_paths(new_path);
	new_path = get_path(lemin);
	while (new_path)
	{
		add_to_paths(&PATHS, new_path, *path_id);
		count_lines(lemin);
		(*path_id)++;
		new_path = get_path(lemin);
	}
	turn_all_links_on_off(ROOMS, lemin->size, ON);
	lemin->overlap = 0;
}

void			find_solution(t_lemin *lemin)
{
	int		**temp_path_ids;
	int		path_id;
	t_link	*new_path;

	path_id = 2;
	new_path = get_path(lemin);
	while (new_path)
	{
		if (lemin->overlap)
			split_paths(new_path, lemin, &path_id);
		else
		{
			add_to_paths(&PATHS, new_path, path_id);
			count_lines(lemin);
			path_id++;
		}
		new_path = get_path(lemin);
	}
	free_paths(lemin->paths);
	lemin->paths = create_best_paths_new(lemin);
}
