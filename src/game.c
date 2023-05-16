/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/16 02:54:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0xC6BF92
// background(&game->window->img, 0xE0E0E0);

static int	on_update(t_game *game)
{
	if (!game->window->win_ptr)
		return (0);
	if (game->gameplay->is_pause == true)
	{
		mlx_string_put(game->window->mlx_ptr, game->window->win_ptr,
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, GREEN, "PAUSE");
		return (0);
	}
	if (game->gameplay->is_stop == false)
	{
		move_player(game, game->gameplay->player);
		check_collider(game, game->gameplay->player, game->gameplay->guards);
		gameplay_elements(game, game->gameplay);
	}
	camera(game, game->camera, game->gameplay->player);
	display_sprites(game, game->camera, game->window);
	display_ui(game, game->window, game->gameplay);
	if (IS_DEBUG)
	{
		display_debug(&game->window->img, GREEN, game->gameplay->chunks_pos,
			game->level->nb_cases);
		display_player_box_collider(&game->window->img, game->gameplay->player,
			0x800080);
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->background.mlx_img, 0, 0);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, -(int)game->camera->camera_f_pos.x,
		-(int)game->camera->camera_f_pos.y);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->ui.mlx_img, 0, 0);
	if (IS_DEBUG)
	{
		display_nb_move(game);
		debug_fps(game);
	}
	display_hp(game->window, game->gameplay->player, GREEN);
	calculate_fps(&game->gameplay->fps, &game->gameplay->delta_time);
	return (0);
}

void	start_game(t_game *game)
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
