/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_arrengement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:03:04 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 13:35:48 by aoberon          ###   ########.fr       */
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
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_corner_N-O_64px");
	else if (value.x == value_max.x && value.y == 0)
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_corner_N-E_64px");
	else if (value.x == value_max.x && value.y == value_max.y)
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_corner_S-E_64px");
	else if (value.x == 0 && value.y == value_max.y)
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_corner_S-O_64px");
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == 0)
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_side_up_64px");
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == value_max.y)
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_side_down_64px");
	else if (value.x == 0 && (value.y >= 1 && value.y < value_max.y))
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_side_left_64px");
	else if (value.x == value_max.x && (value.y >= 1 && value.y < value_max.y))
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/column_side_right_64px");
	else
		init_sprite(game->window.mlx_ptr, sprite, 1,
			"wall/roulette_table_64px");
}

	// printf("pos : [%d] x : [%d] y : [%d]\n\n", pos, x, y);
