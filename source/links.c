#include "lem-in.h"

static t_link	*delete_link(t_link *link, int del_link)
{
	t_link *ret;

	if (!link)
		return (NULL);
	if (link->ptr->id == del_link)
	{
		ret = link->next;
		free(link);
		return (ret);
	}
	link->next = delete_link(link->next, del_link);
	return (link);
}

void			delete_links(t_room **rooms, t_del *del_links)
{
	t_del	*deltmp;
	int		id1;
	int		id2;

	deltmp = del_links;
	while (deltmp)
	{
		id1 = deltmp->room1;
		id2 = deltmp->room2;
		rooms[id1]->link = delete_link(rooms[id1]->link, id2);
		rooms[id2]->link = delete_link(rooms[id2]->link, id1);
		deltmp = deltmp->next;
	}
}

static void		add_link(t_link **link, t_room *room)
{
	t_link *new;

	if (!link || !room)
		return ;
	new = MEM(t_link);
	new->id = room->id;
	new->name = room->name;
	new->ptr = room;
	new->next = *link;
	*link = new;

}

void			add_links(t_room **rooms, t_del *del_links)
{
	t_del	*deltmp;
	int		id1;
	int		id2;

	deltmp = del_links;
	while (deltmp)
	{
		id1 = deltmp->room1;
		id2 = deltmp->room2;
		add_link(&rooms[id1]->link, rooms[id2]);
		add_link(&rooms[id2]->link, rooms[id1]);
		deltmp = deltmp->next;
	}
}
