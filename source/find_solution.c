#include "lem-in.h"

static void		free_path(t_room *path)
{
	if (!path)
		return ;
	free_path(path->to);
	free(path);
	path = NULL;
}

static t_link	*delete_path(t_link *path, int path_id)
{
	t_link *ret;

	if (!path)
		return (NULL);
	if (path->id == path_id)
	{
		ret = path->next;
		free_path(path->ptr);
		free(path);
		return (ret);
	}
	path->next = delete_path(path->next, path_id);
	return (path);
}

static void		delete_overlap_from_paths(t_link *paths, t_del *del_links)
{
	t_del	*deltmp;
	int		prev_del_path;

	deltmp = del_links;
	prev_del_path = 0;
	while (deltmp)
	{
		if (prev_del_path != deltmp->path_id)
		{
			paths = delete_path(paths, deltmp->path_id);
			prev_del_path = deltmp->path_id;
		}
		deltmp = deltmp->next;
	}
}

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
			delete_overlap_from_paths(PATHS, lemin->del_links);
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
		// temp_path_ids = check_paths_save_winner(lemin);
	}
	// lemin->winner_ids = temp_path_ids;
}
