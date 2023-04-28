/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 14:51:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_one_sprite(void *ptr, t_sprite sprite)
{
	int	i;

	i = 0;
	while (i < sprite.size)
	{
		if (sprite.sprite_img[i].mlx_img)
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

static void	free_level(t_level level)
{
	if (level.map)
		free(level.map);
	if (level.path_map)
		free(level.path_map);
}

void	free_window(t_window window)
{
	if (window.map_sprites)
		free(window.map_sprites);
	if (window.mlx_ptr)
	{
		mlx_destroy_display(window.mlx_ptr);
		free(window.mlx_ptr);
	}
}

void	free_game(t_game game, const char *error)
{
	free_level(game.level);
	free_assets(game.window.mlx_ptr, game.assets);
	free_window(game.window);
	if (game.chunks_pos)
		free(game.chunks_pos);
	if (error)
	{
		ft_putstr((char *)error);
		exit(EXIT_FAILURE);
	}
}
