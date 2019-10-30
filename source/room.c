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


void			add_room(t_room **head, t_room *new)
{
	if (!new || !head)
		return ;
	new->next = *head;
	*head = new;
}


t_room			*add_to_hastable(t_room **table, t_room *new, size_t index)
{
	if (!table[index])
		table[index] = new;
	else
		add_room(&table[index], new);
	return (new);
}

static int		compare_coord(t_point a, t_point b)
{
	if (a.x == b.x && a.y == b.y)
		return (1);
	return (0);
}

int				duplicate_room(t_room **table, char *name, t_point coord, size_t index)
{
	t_room *tmp;

	if (!table[index])
		return (0);
	tmp = table[index];
	while (tmp)
	{
		if (compare_coord(coord, tmp->coord) || ft_strequ(name, tmp->name))
			return (1); 
		tmp = tmp->next;
	}
	return (0);
}
