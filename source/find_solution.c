#include "lem-in.h"

/* DEBUG */
static void print_links(t_lemin *lemin)
{
	ft_putendl("*--------*");
	for (int i = 0; i < lemin->size; i++)
	{
		t_link *link;
		link = ROOMS[i]->link;
		ft_putendl(ROOMS[i]->name);
		while (link)
		{
			ft_printf("\t-> %s\n", link->name);
			link = link->next;
		}
	}
	ft_putendl("*--------*");
}

static void		print_del_links(t_lemin *lemin)
{
	t_del *tmp = lemin->del_links;
	while (tmp)
	{
		ft_printf("room1 %s, room2 %s, path_id %d\n", ROOMS[tmp->room1]->name, ROOMS[tmp->room2]->name, tmp->path_id);
		tmp = tmp->next;
	}
}

void		print_path(t_link *path, t_room *end, char *start);

/* DEBUG */

void			find_solution(t_lemin *lemin)
{
	int **temp_path_ids;
	int path_id;
	t_link *new_path;

	path_id = 2;
	new_path = get_path(lemin);
	while (new_path)
	{
		if (lemin->del_links)
		{
			delete_links(ROOMS, lemin->del_links);
			reset_overlap(ROOMS, PATHS, lemin->del_links);
			delete_paths_from_paths(&PATHS, lemin->del_links);
			new_path = get_path(lemin);
			while (new_path)
			{
				add_to_paths(&PATHS, new_path, path_id);
				path_id++;
				new_path = get_path(lemin);
			}
			add_links_back(ROOMS, lemin->del_links);
			free_del_links(&lemin->del_links);
			print_del_links(lemin);
		}
		else
		{
			add_to_paths(&PATHS, new_path, path_id);
			path_id++;
		}
		new_path = get_path(lemin);
		temp_path_ids = check_paths_save_winner(lemin);
	}
	lemin->winner_ids = temp_path_ids;
//	free_paths(lemin->paths);
//	lemin->paths = create_best_paths(lemin);
//	ft_printf("LINE COUNT: %d\n", move_ants_in_all_paths(lemin, PRINT));
}
