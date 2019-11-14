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

	deltmp = del_links;
	while (deltmp)
	{
		pathtmp = paths;
		while (pathtmp->id != deltmp->path_id)
			pathtmp = pathtmp->next;
		reset_path(rooms, paths->ptr);
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
