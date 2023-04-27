/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_arrengement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:03:04 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 14:04:25 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_wall_image(t_game *game, t_sprite *sprite, int pos)
{
	t_vector_2	value;
	t_vector_2	value_max;

	value_max.x = game->level.map_vector.x;
	value_max.y = game->level.map_vector.y;
	value.x = pos % (value_max.x--);
	value.y = pos / ((value_max.y--) - 1);
	if (value.x == 0 && value.y == 0)
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_CORNER_N_O);
	else if (value.x == value_max.x && value.y == 0)
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_CORNER_N_E);
	else if (value.x == value_max.x && value.y == value_max.y)
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_CORNER_S_E);
	else if (value.x == 0 && value.y == value_max.y)
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_CORNER_S_O);
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == 0)
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_SIDE_UP);
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == value_max.y)
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_SIDE_DOWN);
	else if (value.x == 0 && (value.y >= 1 && value.y < value_max.y))
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_SIDE_LEFT);
	else if (value.x == value_max.x && (value.y >= 1 && value.y < value_max.y))
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_SIDE_RIGHT);
	else
		init_sprite(game->window.mlx_ptr, sprite, 1, PATH_WALL_INSIDE);
}

	// printf("pos : [%d] x : [%d] y : [%d]\n\n", pos, x, y);
