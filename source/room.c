#include "lem-in.h"
#include "libft.h"
#include "ft_printf.h"

t_room			*new_room(char *name, t_point coord)
{
	t_room *room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	room->name = ft_strdup(name);
	room->dist = -1;
	room->coord = coord;
	return (room);
}

/*
void			add_room(t_room **head, t_room *new)
{
	if (!new || !head)
		return ;
	new->next = *head;
	*head = new;
}
*/

void			add_room(t_room **head, t_room *new)
{

}


t_room			*room_exists(t_room *rooms, char *name)
{
	if (!rooms)
		return (NULL);
	if (ft_strequ(rooms->name, name))
		return (rooms);
	return (room_exists(rooms->next, name));
}

int				coord_dup(t_room *rooms, t_point coord)
{
	if (!rooms)
		return (0);
	if (rooms->coord.x == coord.x && rooms->coord.y == coord.y)
		return (1);
	return (coord_dup(rooms->next, coord));
}

void			print_rooms(t_room *room)
{
	if (!room)
		return ;
	print_rooms(room->next);
	ft_printf("%-5s %-2d %d\n", room->name, room->coord.x, room->coord.y);
}
