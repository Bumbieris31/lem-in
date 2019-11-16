#include "lem-in.h"

/* Create new t_room */

t_room			*new_room(char *name, t_point coord, int id)
{
	t_room *room;

	room = MEM(t_room);
	room->name = ft_strdup(name);
	room->dist = -1;
	room->id = id;
	room->coord = coord;
	return (room);
}

static int		compare_coord(t_point a, t_point b)
{
	if (a.x == b.x && a.y == b.y)
		return (1);
	return (0);
}

/* Checker to see if coord or name already exists */

int				duplicate_room(t_room **rooms, char *name, t_point coord, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (compare_coord(coord, rooms[i]->coord) || ft_strequ(name, rooms[i]->name))
			return (1); 
		i++;
	}
	return (0);
}
