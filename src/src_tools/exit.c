/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/03 19:00:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_arg_error(void)
{
	ft_printf("Not the good number of arguments.\n");
	ft_printf("Not the good number of arguments.\n");
	ft_printf("Please use so_long with this format :\n");
	ft_printf("./so_long 'mapfile.ber'\n");
	exit(EXIT_FAILURE);
}

void	exit_map_error(char **map_2d, int y)
{
	if (map_2d)
		free_2d_char_tab(map_2d, y);
	ft_printf("Error\n");
	ft_printf("Not a valid map.\n");
	ft_printf("Please use a map : with .ber extenstion, rectangular, ");
	ft_printf("close by 1, and line_to_tab ");
	ft_printf("with only one P and E, and at least 1 C\n");
	ft_printf("for example :\n");
	ft_printf("1111\n1P01\n10C1\n1E01\n1111\n");
	exit(EXIT_FAILURE);
}

	// ft_printf("1111\n1P01\n1CE1\n1111\n");

void	exit_pathfinding_error(t_level *level, char flag, int pos_error)
{
	free(level->map);
	free(level->path_map);
	ft_printf("Error\n");
	ft_printf("Not a valid map.\n");
	if (flag == 'E')
		ft_printf("The Exit (E) at position x : [%d] y : [%d] ",
			pos_error % level->map_vector.x, pos_error / level->map_vector.y);
	else if (flag == 'C')
		ft_printf("The Collectible (C) at position x : [%d] y : [%d] ",
			pos_error % level->map_vector.x, pos_error / level->map_vector.y);
	ft_printf("is not reachable.\n");
	ft_printf("Please make the Exit and all the Collectibles ");
	ft_printf("reachable from the Player P.\n");
	ft_printf("for example :\n");
	ft_printf("1111\n1P01\n10C1\n1E01\n1111\n");
	exit(EXIT_FAILURE);
}
