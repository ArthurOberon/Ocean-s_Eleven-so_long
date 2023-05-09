/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/09 21:31:48 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0xC6BF92
// background(&game->window->img, 0xE0E0E0);

	// mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		// game->camera->img_background.mlx_img, 0, 0);

static int	on_update(t_game *game)
{
	if (!game->window->win_ptr)
		return (0);
	move_player(game, game->gameplay->player);
	check_collider(game, game->gameplay->player);
	camera(game, game->camera, game->gameplay->player);
	display_sprites(game, game->camera, game->window);
	if (IS_DEBUG)
	{
		display_debug(&game->window->img, GREEN, game->gameplay->chunks_pos,
			game->level->nb_cases);
		display_player_box_collider(&game->window->img, game->gameplay->player,
			0x800080);
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, -(int)game->camera->camera_f_pos.x,
		-(int)game->camera->camera_f_pos.y);
	calculate_fps(&game->gameplay->fps, &game->gameplay->delta_time);
	if (IS_DEBUG)
	{
		display_nb_move(game);
		debug_fps(game);
	}
	return (0);
}

void	display(t_game *game)
{
	mlx_hook(game->window->win_ptr, DestroyNotify, KeyPressMask, &close_game,
		game);
	mlx_hook(game->window->win_ptr, KeyPress, KeyPressMask, &handle_keypress,
		game);
	mlx_hook(game->window->win_ptr, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, game);
	mlx_hook(game->window->win_ptr, FocusOut, FocusChangeMask,
		&secure_lost_focus, game);
	mlx_loop_hook(game->window->mlx_ptr, &on_update, game);
	mlx_loop(game->window->mlx_ptr);
}
