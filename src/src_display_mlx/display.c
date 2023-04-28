/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 14:47:06 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	on_update(t_game *game)
{
	if (!game->window.win_ptr)
		return (0);
	background(&game->window.img, 0xE0E0E0);
	display_sprites(game);
	if (IS_DEBUG)
		display_debug(&game->window.img, GREEN, game->chunks_pos,
			game->level.nb_cases);
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->window.img.mlx_img, 0, 0);
	return (0);
}

void	display(t_game *game)
{
	init_window(game);
	init_sprites_assets(game, &game->assets);
	init_sprites(game);
	mlx_hook(game->window.win_ptr, DestroyNotify, KeyPressMask, close_window,
		&game->window);
	mlx_hook(game->window.win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		game);
	mlx_loop_hook(game->window.mlx_ptr, &on_update, game);
	mlx_loop(game->window.mlx_ptr);
	mlx_destroy_image(game->window.mlx_ptr, game->window.img.mlx_img);
}
