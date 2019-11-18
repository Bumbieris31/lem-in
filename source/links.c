#include "lem-in.h"

void	switch_link_on_off(t_link *link, int del_link, int on_off)
{
	if (!link)
		return ;
	if (link->id == del_link)
	{
		link->on = on_off;
		return ;
	}
	switch_link_on_off(link->next, del_link, on_off);
}

void			add_links_back(t_room **rooms, t_del *del_links)
{
	t_del	*deltmp;
	int		id1;
	int		id2;

	deltmp = del_links;
	while (deltmp)
	{
		id1 = deltmp->room1;
		id2 = deltmp->room2;
		switch_link_on_off(rooms[id1]->link, id2, ON);
		switch_link_on_off(rooms[id2]->link, id1, ON);
		deltmp = deltmp->next;
	}
}

void			free_del_links(t_del **del_links)
{
	if (!*del_links)
		return ;
	free_del_links(&(*del_links)->next);
	free(*del_links);
	*del_links = NULL;
}
