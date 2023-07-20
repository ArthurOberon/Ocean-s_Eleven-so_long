/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_message.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:13:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 12:50:08 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Exit the game, with argument error message.
 * 
 */
void	exit_arg_error(void)
{
	ft_printf("Error\nNot the good number of arguments.\n\
		Please use so_long with this format :\n./so_long 'mapfile.ber'\n");
	exit(EXIT_FAILURE);
}

/**
 * @brief Exit the game, with map error message.
 * 
 * @param map_2d map 2d array, used to free it.
 * @param y size of the map (height).
 * @return int 0;
 */
int	exit_map_error(char **map_2d, int y)
{
	if (map_2d)
		free_2d_char_tab(map_2d, y);
	ft_printf("Error\nNot a valid map.\nPlease use a map : with .ber extenstion, \
rectangular, close by 1, and line_to_tab with only one P and E, and at least one C\n\
for example :\n1111\n1P01\n10C1\n1E01\n1111\n");
	return (0);
}

/**
 * @brief Exit the game, with pathfinding error message.
 * 
 * @param level level struct, used to free map and path_map.
 * @param flag error flag to write the right error message.
 * @param pos_error position on the map of the error.
 * @return int 0;
 */
int	exit_pathfinding_error(t_level *level, char flag, int pos_error)
{
	free(level->map);
	free(level->path_map);
	ft_printf("Error\nNot a valid map.\n");
	if (flag == 'E')
		ft_printf("The Exit (E) at position x : [%d] y : [%d] ",
			pos_error % level->map_vector.x, pos_error / level->map_vector.y);
	else if (flag == 'C')
		ft_printf("The Collectible (C) at position x : [%d] y : [%d] ",
			pos_error % level->map_vector.x, pos_error / level->map_vector.y);
	ft_printf("is not reachable.\nPlease make the Exit and all the Collectibles \
reachable from the Player P.\nfor example :\n1111\n1P01\n10C1\n1E01\n1111\n");
	free(level);
	return (0);
}

/**
 * @brief Exit the game, with option error message.
 * 
 * @param available_character array of available character to free.
 */
void	exit_option_error(int *available_character)
{
	ft_printf("Error\nNot a valid option.\n\
The option allows you to choose which character you will \
have at the start, the character not selectioned will be lay randomly \
on the map.\nPlease only use :\n-d or -D (to get Danny)\n\
-r or -R (to get Rusty)\n-l or -L (to get Linus)\n-b or -B (to get Basher)\n\
Notice that the first option you write will be the character you will play at \
the start between all the characters selected.\n");
	if (available_character)
		free(available_character);
	exit (EXIT_FAILURE);
}
