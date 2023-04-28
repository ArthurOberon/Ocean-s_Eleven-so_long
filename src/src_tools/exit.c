/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 14:08:23 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_arg_error(void)
{
	ft_putstr("Not the good number of arguments.\n");
	ft_putstr("Please use so_long with this format :\n");
	ft_putstr("./so_long 'mapfile.ber'\n");
	exit(EXIT_FAILURE);
}

void	exit_map_error(char **map_2d, int y)
{
	if (map_2d)
		free_2d_char_tab(map_2d, y);
	ft_putstr("Error\n");
	ft_putstr("Not a valid map.\n");
	ft_putstr("Please use a map : with .ber extenstion, rectangular, ");
	ft_putstr("close by 1, and line_to_tab");
	ft_putstr("with only one P and E, and at least 1 C\n");
	ft_putstr("for example :\n");
	ft_putstr("1111\n1P01\n10C1\n1E01\n1111\n");
	exit(EXIT_FAILURE);
}

	// ft_putstr("1111\n1P01\n1CE1\n1111\n");

void	exit_pathfinding_error(t_level level, char flag, int pos_error)
{
	free(level.map);
	free(level.path_map);
	ft_putstr("Error\n");
	ft_putstr("Not a valid map.\n");
	if (flag == 'E')
		ft_putstr("The Exit (E) at position x : [");
	else if (flag == 'C')
		ft_putstr("The Collectible (C) at position x : [");
	ft_putnbr(pos_error % level.map_vector.x);
	ft_putstr("] y : [");
	ft_putnbr(pos_error / level.map_vector.x);
	ft_putstr("] is not reachable.\n");
	ft_putstr("Please make the Exit and all the Collectibles ");
	ft_putstr("reachable from the Player P.\n");
	ft_putstr("for example :\n");
	ft_putstr("1111\n1P01\n10C1\n1E01\n1111\n");
	exit(EXIT_FAILURE);
}
