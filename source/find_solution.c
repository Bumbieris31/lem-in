#include "lem-in.h"
void			activate_split_path_links(t_link *new_path, t_room **rooms, t_link **paths, int start);
void			turn_all_links_on_off(t_room **rooms, int size, int on_off);

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
		{
			turn_all_links_on_off(ROOMS, lemin->size, OFF);
			activate_split_path_links(new_path, ROOMS, &PATHS, START->id);
			free_paths(new_path);
			new_path = get_path(lemin);
			while (new_path)
			{
				add_to_paths(&PATHS, new_path, path_id);
				count_lines(lemin);
				path_id++;
				new_path = get_path(lemin);
			}
			turn_all_links_on_off(ROOMS, lemin->size, ON);
			lemin->overlap = 0;
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
