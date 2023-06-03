/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/03 17:44:39 by aoberon          ###   ########.fr       */
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
	display_texts_box_list(game, game->gameplay->texts_box_list);
	if (IS_DEBUG)
	{
		display_debug(&game->window->img, GREEN, game->gameplay->chunks_pos,
			game->level->nb_cases);
		display_player_box_collider(&game->window->img, game->gameplay->player,
			0x800080);
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, 0, 0);
	if (IS_DEBUG)
		debug_fps(game);
	calculate_fps(&game->gameplay->fps, &game->gameplay->delta_time);
	return (0);
}

void	start_game(t_game *game)
{
	text_box_events_start(game);
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
