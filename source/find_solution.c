#include "lem-in.h"

void			find_solution(t_lemin *lemin)
{
	int		**temp_path_ids;
	int		path_id;
	t_link	*new_path;

	path_id = 2;
	new_path = get_path(lemin);
	while (new_path)
	{
		if (lemin->del_links)
		{
			free_paths(new_path);
			reset_overlap(ROOMS, PATHS, lemin->del_links);
			delete_paths_from_paths(&PATHS, lemin->del_links);
			new_path = get_path(lemin);
			while (new_path)
			{
				add_to_paths(&PATHS, new_path, path_id);
				count_lines(lemin);
				path_id++;
				new_path = get_path(lemin);
			}
			add_links_back(ROOMS, lemin->del_links);
			free_del_links(&lemin->del_links);
		}
		else
		{
			add_to_paths(&PATHS, new_path, path_id);
			count_lines(lemin);
			path_id++;
		}
		new_path = get_path(lemin);
		//	temp_path_ids = check_paths_save_winner(lemin);
	}
	// ft_printf("LINE COUNT: %d\n", move_ants_in_all_paths(lemin, PRINT));
	// lemin->winner_ids = temp_path_ids;
}
