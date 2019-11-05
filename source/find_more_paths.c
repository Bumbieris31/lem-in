/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_more_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:50:31 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/05 21:44:30 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_path	*split_path() // returns new paths llist?
{
	
/*
	go through next smallest dist
	while (1)
	if walk upon a node that has *from != 0 {walk one back(to *from)(and save walk_back nodes id_s for *to and *from for every connection) and look for new smallest distance 
		if not found {walk back more} 
		else if {back to start the path is not there}
		else {found a new smallest dist continue to the smallest and repeat}}
	if end is reached {delete saved id connection paths.}
	if start is reached clear all the saved id_s.
	mark path nodes as used (dist = -1)
 */
}

void	find_more_paths(t_lemin *lemin)
{
	int	fastest_network;
	int	temp_network;
	t_room	*check_path;
	t_path	*new_paths;
		//save path that might be split (when encounter a node with *from(mark path nodes with path_id?))
	fastest_network = move_ants_in_all_paths(lemin);
	check_path = find_smallest_dist(lemin->start->link);
	while (check_path != 0)
	{
		new_paths = split_path();
		temp_network = move_ants_in_all_paths(lemin); //with new_paths passed in
		if (temp_network < fastest_network)
		{
			//del lemin->paths
			lemin->paths = new_paths;
		}
		else
		{
			//free new_paths
		}
	}
	/*
	while (more paths can be taken from the start)
	{
		run the ants through shortest paths and save the number of lines;
		run the split function and then run ants through the paths again;
		if performance increased save the split else delete and look for a new one;
	}
	*/
}
