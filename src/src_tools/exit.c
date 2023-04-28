/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 22:38:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_arg_error(void)
{
	printf("Not the good number of arguments.\n");
	printf("Not the good number of arguments.\n");
	printf("Please use so_long with this format :\n");
	printf("./so_long 'mapfile.ber'\n");
	exit(EXIT_FAILURE);
}

void	exit_map_error(char **map_2d, int y)
{
	if (map_2d)
		free_2d_char_tab(map_2d, y);
	printf("Error\n");
	printf("Not a valid map.\n");
	printf("Please use a map : with .ber extenstion, rectangular, ");
	printf("close by 1, and line_to_tab ");
	printf("with only one P and E, and at least 1 C\n");
	printf("for example :\n");
	printf("1111\n1P01\n10C1\n1E01\n1111\n");
	exit(EXIT_FAILURE);
}

	// ft_putstr("1111\n1P01\n1CE1\n1111\n");

void	exit_pathfinding_error(t_level level, char flag, int pos_error)
{
	free(level.map);
	free(level.path_map);
	printf("Error\n");
	printf("Not a valid map.\n");
	if (flag == 'E')
		printf("The Exit (E) at position x : [%d] y : [%d] ",
			pos_error % level.map_vector.x, pos_error / level.map_vector.y);
	else if (flag == 'C')
		printf("The Collectible (C) at position x : [%d] y : [%d] ",
			pos_error % level.map_vector.x, pos_error / level.map_vector.y);
	printf("is not reachable.\n");
	printf("Please make the Exit and all the Collectibles ");
	printf("reachable from the Player P.\n");
	printf("for example :\n");
	printf("1111\n1P01\n10C1\n1E01\n1111\n");
	exit(EXIT_FAILURE);
}
