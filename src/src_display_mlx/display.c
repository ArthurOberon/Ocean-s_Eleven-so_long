/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/30 20:20:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	on_update(t_game *game)
{
	if (!game->window->win_ptr)
		return (0);
	background(&game->window->img, 0xE0E0E0);
	check_move_player(game);
	display_sprites(game);
	if (IS_DEBUG)
	{
		display_debug(&game->window->img, GREEN, game->gameplay->chunks_pos,
			game->level->nb_cases);
		display_player_box_collider(&game->window->img,
			game->gameplay->player_pos, 0x800080);
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, 0, 0);
	calculate_fps(&game->gameplay->fps, &game->gameplay->delta_time);
	if (IS_DEBUG)
		debug_fps(game);
	return (0);
}

void	display(t_game *game)
{
	mlx_hook(game->window->win_ptr, DestroyNotify, KeyPressMask, close_window,
		&game->window);
	mlx_hook(game->window->win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		game);
	mlx_hook(game->window->win_ptr, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, game);
	mlx_loop_hook(game->window->mlx_ptr, &on_update, game);
	mlx_loop(game->window->mlx_ptr);
	mlx_destroy_image(game->window->mlx_ptr, game->window->img.mlx_img);
}
