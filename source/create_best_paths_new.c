#include "lem-in.h"

static t_link	*add_new_path(int id)
{
	t_link *new;

	new = MEM(t_link);
	new->id = id;
	return (new);
}

int		new_paths_len(t_room *room)
{
	int	i;

	i = 1;
	while (room->to)
	{
		i++;
		room = room->to;
	}
	return (i);
}

t_room	*make_room(int id, t_room **rooms)
{
	t_room *room;

	room = MEM(t_room);
	room->name = rooms[id]->name;
	room->dist = -1;
	room->ant = 0;
	room->id = id;
	room->to = 0;
	return (room);
}

void	recreate_path(t_link **paths, int id)
{
	if (!*paths)
	{
		(*paths) = MEM(t_link);
		(*paths)->id = id;
		return ;
	}
	else
		recreate_path(&(*paths)->next, id);
	// t_link	*node;

	// node = *paths;
	// if (!node)
	// {
	// 	node = MEM(t_link);
	// 	node->id = id;
	// }
	// else
	// {
	// 	while (node->next)
	// 		node = node->next;
	// 	node->next = add_new_path(id);
	// }
}

void	add_room_to_recreated_paths()
{

}

void	recreate_rooms(t_link **paths, t_lemin *lemin, int i)
{
	t_link	*node;
	t_room	*room;
	int j;

	j = 0;
	node = *paths;
	while (node->next)
		node = node->next;
	
	node->ptr = make_room(lemin->winner_ids[i][j], ROOMS);
	room = node->ptr;
	while (lemin->winner_ids[i][j] != END->id)
	{
		j++;
		room->to = make_room(lemin->winner_ids[i][j], ROOMS);
		room = room->to;
	}
//	print_path(node, END, START->name);
	node->on = new_paths_len(node->ptr);
}

t_link	*create_best_paths_new(t_lemin *lemin)
{
	int		i;
	// int		j;
	t_link	*paths;

	i = 0;
	paths = 0;
	while (lemin->winner_ids[i])
	{
		recreate_path(&paths, i);
		// j = 0;
		recreate_rooms(&paths, lemin, i);
		i++;
	}
	return (paths);
}