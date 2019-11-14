#include "lem-in.h"

void			reset_path(t_room **rooms, t_room *path)
{
	if (!path)
		return ;
	reset_path(rooms, path->to);
	rooms[path->id]->to = NULL;
	rooms[path->id]->from = NULL;
	rooms[path->id]->path = 0;
}

void				reset_rooms(t_room **rooms, int end)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->path = 0; /* DON'T NEED THIS? */
		rooms[i]->to = NULL; /* DON'T NEED THIS? */
		rooms[i]->from = NULL; /* DON'T NEED THIS? */
		rooms[i]->branch = NULL;
		rooms[i]->dist = -1;
		rooms[i]->visited = 0;
		i++;
	}
	rooms[end]->dist = 0;
}
