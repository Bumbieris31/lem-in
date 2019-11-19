#include "lem-in.h"
void			turn_all_links_on_off(t_room **rooms, int size, int on_off);
void			path_links_on(t_link *path, t_lemin *lemin);
void			turn_overlap_links_on(t_lemin *lemin);
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
			turn_all_links_on_off(ROOMS, lemin->size, OFF);
			path_links_on(new_path, lemin);
			turn_overlap_links_on(lemin);
			free_paths(new_path);
			reset_overlap(ROOMS, PATHS, lemin->del_links);
			add_delete_links(ROOMS, lemin->del_links, OFF);
			delete_paths_from_paths(&PATHS, lemin->del_links);
			new_path = get_path(lemin);
			while (new_path)
			{
				add_to_paths(&PATHS, new_path, path_id);
				count_lines(lemin);
				path_id++;
				new_path = get_path(lemin);
			}
			// add_delete_links(ROOMS, lemin->del_links, ON);
			turn_all_links_on_off(ROOMS, lemin->size, ON);
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
