/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 22:02:41 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_one_sprite(void *ptr, t_sprite sprite)
{
	int	i;

	i = 0;
	while (i < sprite.size)
	{
		mlx_destroy_image(ptr, sprite.sprite_img[i].mlx_img);
		i++;
	}
	free(sprite.sprite_img);
}

static void	free_assets(void *ptr, t_sprites_assets assets)
{
	free_one_sprite(ptr, assets.player);
	free_one_sprite(ptr, assets.exit);
	free_one_sprite(ptr, assets.collect);
	free_one_sprite(ptr, assets.ground);
	free_one_sprite(ptr, assets.wall_corner_n_o);
	free_one_sprite(ptr, assets.wall_corner_n_e);
	free_one_sprite(ptr, assets.wall_corner_s_e);
	free_one_sprite(ptr, assets.wall_corner_s_o);
	free_one_sprite(ptr, assets.wall_side_up);
	free_one_sprite(ptr, assets.wall_side_down);
	free_one_sprite(ptr, assets.wall_side_left);
	free_one_sprite(ptr, assets.wall_side_right);
	free_one_sprite(ptr, assets.wall_inside);
}

void	free_game(t_game game)
{
	free(game.level.map);
	free(game.level.path_map);
	free(game.chunks_pos);
	free_assets(game.window.mlx_ptr, game.assets);
	free(game.window.map_sprites);
	mlx_destroy_display(game.window.mlx_ptr);
	free(game.window.mlx_ptr);
}
