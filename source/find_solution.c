#include "lem-in.h"

void	find_solution(t_lemin *lemin, t_link *new_path)
{
	int **temp_path_ids;
	int path_id;

	path_id = 2;
	while (new_path)
	{
		new_path = get_path(lemin);
	/*
		if (lemin->deleted_links)
		{
			delete_links();
			reset_path(ROOMS, new_path);
			while (overlapping_paths)
			{
				reset_path(ROOMS, overlapping_path);
			}
			delete_paths_from_paths();
			while (new_paths_found())
			{
				breadth_first();
				get_path();
				add_to_paths(&PATHS, new_path, path_id);
				path_id++;
			}
			add_links_back();
			free_deleted_links_and_set_to_null();
		}
		else
		{

	*/
			add_to_paths(&PATHS, new_path, path_id);
			path_id++;
		// }
		// temp_path_ids = check_paths_save_winner(lemin);
	}
	// lemin->winner_ids = temp_path_ids;
}