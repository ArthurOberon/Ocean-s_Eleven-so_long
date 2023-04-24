/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_arrengement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:03:04 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/24 14:15:25 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_wall_image(t_data *data, t_sprite *map_sprites, int pos)
{
	int	x_max;
	int	y_max;
	int	x;
	int	y;

	x_max = data->game.level.map_vector.x;
	y_max = data->game.level.map_vector.y;
	x = pos % x_max;
	y = pos / (y_max - 1);
	x_max--;
	y_max--;
	if (x == 0 && y == 0)
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_N-O_64px.xpm",
			&map_sprites[pos]);
	else if (x == x_max && y == 0)
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_N-E_64px.xpm",
			&map_sprites[pos]);
	else if (x == x_max && y == y_max)
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_S-E_64px.xpm",
			&map_sprites[pos]);
	else if (x == 0 && y == y_max)
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_S-O_64px.xpm",
			&map_sprites[pos]);
	else if ((x >= 1 && x < x_max) && y == 0)
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_up_64px.xpm",
			&map_sprites[pos]);
	else if ((x >= 1 && x < x_max) && y == y_max)
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_down_64px.xpm",
			&map_sprites[pos]);
	else if (x == 0 && (y >= 1 && y < y_max))
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_left_64px.xpm",
			&map_sprites[pos]);
	else if (x == x_max && (y >= 1 && y < y_max))
		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_right_64px.xpm",
			&map_sprites[pos]);
	else
		get_img_sprite(data->mlx_ptr, "sprites/wall/roulette_table_64px.xpm",
			&map_sprites[pos]);
}
// 13 extra lines

	// printf("pos : [%d] x : [%d] y : [%d]\n\n", pos, x, y);
