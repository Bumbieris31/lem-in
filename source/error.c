/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 18:56:59 by fhignett       #+#    #+#                */
/*   Updated: 2019/11/27 16:10:27 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			error_check(int error)
{
	if (error < 0)
	{
		if (error == ROOM_ERROR)
			ft_putendl("ROOM ERROR");
		else if (error == DUP_ERROR)
			ft_putendl("DUPLICATE ERROR");
		else if (error == ANTS_ERROR)
			ft_putendl("ANT ERROR");
		else if (error == CONN_ERROR)
			ft_putendl("CONNECTION ERROR");
		else if (error == NO_PATH_ERROR)
			ft_putendl("NO PATH FOUND");
		else if (error == FILE_ERROR)
			ft_putendl("FILE ERROR");
		exit(-1);
	}
}
