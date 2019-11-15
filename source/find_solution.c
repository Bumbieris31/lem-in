#include "lem-in.h"

void			find_solution(t_lemin *lemin, t_link *new_path)
{
	int **temp_path_ids;
	int path_id;

	path_id = 2;
	while (new_path)
	{
		new_path = get_path(lemin);
		if (lemin->del_links)
		{
			delete_links(ROOMS, lemin->del_links);
			reset_overlap(ROOMS, PATHS, lemin->del_links);
			delete_paths_from_paths(PATHS, lemin->del_links);
			while (new_path)
			{
				new_path = get_path(lemin);
				add_to_paths(&PATHS, new_path, path_id);
				path_id++;
			}
			add_links_back(ROOMS, lemin->del_links);
			free_del_links(&lemin->del_links);
		}
		else
		{
			add_to_paths(&PATHS, new_path, path_id);
			path_id++;
		}
		//	temp_path_ids = check_paths_save_winner(lemin);
	}
	ft_printf("LINE COUNT: %d\n", move_ants_in_all_paths(lemin, PRINT));
	// lemin->winner_ids = temp_path_ids;
}
