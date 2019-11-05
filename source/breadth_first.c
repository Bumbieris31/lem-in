#include "lem-in.h"

static void			reset_dist(t_room **rooms, int end)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		rooms[i]->dist = -1;
		i++;
	}
	rooms[end]->dist = 0;
	rooms[end]->from = NULL;
}

static void			set_dist(int start, int end, t_room *room, int backtrack)
{
	t_link	*link;
	int		tmp_dist;

	if (room->id == start)
		return ;
	tmp_dist = room->dist + 1;
	if (backtrack)
	{
		if (room->to->dist == -1 || room->to->dist > tmp_dist)
		{
			room->to->dist = tmp_dist;
			set_dist(start, end, room->to, 0);
		}
		return ;
	}
	link = room->link;
	while (link)
	{
		if (link->ptr->dist == -1 || link->ptr->dist > tmp_dist)
		{
			if (!link->ptr->to)
			{
				link->ptr->dist = tmp_dist;
				set_dist(start, end, link->ptr, 0);
			} else if (link->ptr->to->id == room->id)
				;
			else
			{
				link->ptr->dist = tmp_dist;
				set_dist(start, end, link->ptr, 1);
			}
		}
		link = link->next;
	}
}

void				breadth_first(int start, int end, t_room **rooms, t_path **paths)
{
	reset_dist(rooms, end);
	set_dist(start, end, rooms[end], 0);
}
