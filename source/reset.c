#include "lem-in.h"

static void		reset_path(t_room **rooms, t_room *path)
{
	if (!path)
		return ;
	reset_path(rooms, path->to);
	rooms[path->id]->to = NULL;
	rooms[path->id]->from = NULL;
	rooms[path->id]->path = 0;
}

void			reset_overlap(t_room **rooms, t_link *paths, t_del *del_links)
{
	t_del	*deltmp;
	t_link	*pathtmp;
	int		prev_reset_path;

	deltmp = del_links;
	prev_reset_path = 0;
	while (deltmp)
	{
		if (prev_reset_path != deltmp->path_id)
		{
			pathtmp = paths;
			while (pathtmp && pathtmp->id != deltmp->path_id)
				pathtmp = pathtmp->next;
			if (pathtmp && pathtmp->id == deltmp->path_id)
				reset_path(rooms, pathtmp->ptr);
			prev_reset_path = deltmp->path_id;
		}
		deltmp = deltmp->next;
	}
}

void			reset_rooms(t_room **rooms, int end)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->branch = NULL;
		rooms[i]->dist = -1;
		rooms[i]->visited = 0;
		i++;
	}
	rooms[end]->dist = 0;
}
