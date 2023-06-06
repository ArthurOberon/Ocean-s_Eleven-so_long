/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_arrengement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:03:04 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 15:17:01 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get a random inside wall image.
 * 
 * @param game game struct, used to get the assets struct.
 * @param sprite sprite struct, where the image will be stored.
 */
static void	get_random_inside_wall_image(t_game *game, t_sprite **sprite)
{
	if (rand() % 101 > 50)
		*sprite = game->assets->wall_roulette;
	else
		*sprite = game->assets->wall_poker;
}

/**
 * @brief Get the wall image depending on the position of the wall.
 * 
 * @param game game struct, used to get the level and assets struct.
 * @param sprite sprite struct, where the image will be stored.
 * @param pos position of the wall on the map.
 */
void	get_wall_image(t_game *game, t_sprite **sprite, int pos)
{
	t_vector_2	value;
	t_vector_2	value_max;

	value_max.x = game->level->map_vector.x;
	value_max.y = game->level->map_vector.y - 1;
	value.x = pos % (value_max.x);
	value.y = pos / (value_max.x--);
	if (value.x == 0 && value.y == 0)
		*sprite = game->assets->wall_corner_n_o;
	else if (value.x == value_max.x && value.y == 0)
		*sprite = game->assets->wall_corner_n_e;
	else if (value.x == value_max.x && value.y == value_max.y)
		*sprite = game->assets->wall_corner_s_e;
	else if (value.x == 0 && value.y == value_max.y)
		*sprite = game->assets->wall_corner_s_o;
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == 0)
		*sprite = game->assets->wall_side_up;
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == value_max.y)
		*sprite = game->assets->wall_side_down;
	else if (value.x == 0 && (value.y >= 1 && value.y < value_max.y))
		*sprite = game->assets->wall_side_left;
	else if (value.x == value_max.x && (value.y >= 1 && value.y < value_max.y))
		*sprite = game->assets->wall_side_right;
	else
		get_random_inside_wall_image(game, sprite);
}
