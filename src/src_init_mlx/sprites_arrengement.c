/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_arrengement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:03:04 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 16:45:07 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	get_wall_image(t_game *game, t_images_assets assets, t_sprite *sprite,
// 	int pos)
// {
// 	t_vector_2	value;
// 	t_vector_2	value_max;

// 	value_max.x = game->level.map_vector.x;
// 	value_max.y = game->level.map_vector.y;
// 	value.x = pos % (value_max.x--);
// 	value.y = pos / ((value_max.y--) - 1);
// 	if (value.x == 0 && value.y == 0)
// 		init_sprite(assets.wall_corner_n_o, sprite, 1);
// 	else if (value.x == value_max.x && value.y == 0)
// 		init_sprite(assets.wall_corner_n_e, sprite, 1);
// 	else if (value.x == value_max.x && value.y == value_max.y)
// 		init_sprite(assets.wall_corner_s_e, sprite, 1);
// 	else if (value.x == 0 && value.y == value_max.y)
// 		init_sprite(assets.wall_corner_s_o, sprite, 1);
// 	else if ((value.x >= 1 && value.x < value_max.x) && value.y == 0)
// 		init_sprite(assets.wall_side_up, sprite, 1);
// 	else if ((value.x >= 1 && value.x < value_max.x) && value.y == value_max.y)
// 		init_sprite(assets.wall_side_down, sprite, 1);
// 	else if (value.x == 0 && (value.y >= 1 && value.y < value_max.y))
// 		init_sprite(assets.wall_side_left, sprite, 1);
// 	else if (value.x == value_max.x && (value.y >= 1 && value.y < value_max.y))
// 		init_sprite(assets.wall_side_right, sprite, 1);
// 	else
// 		init_sprite(assets.wall_inside, sprite, 1);
// }

void	get_wall_image(t_game *game, t_sprite *sprite, int pos)
{
	t_vector_2	value;
	t_vector_2	value_max;

	value_max.x = game->level->map_vector.x;
	value_max.y = game->level->map_vector.y;
	value.x = pos % (value_max.x--);
	value.y = pos / ((value_max.y--) - 1);
	if (value.x == 0 && value.y == 0)
		*sprite = game->assets.wall_corner_n_o;
	else if (value.x == value_max.x && value.y == 0)
		*sprite = game->assets.wall_corner_n_e;
	else if (value.x == value_max.x && value.y == value_max.y)
		*sprite = game->assets.wall_corner_s_e;
	else if (value.x == 0 && value.y == value_max.y)
		*sprite = game->assets.wall_corner_s_o;
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == 0)
		*sprite = game->assets.wall_side_up;
	else if ((value.x >= 1 && value.x < value_max.x) && value.y == value_max.y)
		*sprite = game->assets.wall_side_down;
	else if (value.x == 0 && (value.y >= 1 && value.y < value_max.y))
		*sprite = game->assets.wall_side_left;
	else if (value.x == value_max.x && (value.y >= 1 && value.y < value_max.y))
		*sprite = game->assets.wall_side_right;
	else
		*sprite = game->assets.wall_inside;
}

	// printf("pos : [%d] x : [%d] y : [%d]\n\n", pos, x, y);
