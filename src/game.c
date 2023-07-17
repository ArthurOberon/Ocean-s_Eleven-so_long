/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 23:57:01 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 0xC6BF92
// background = 0xE0E0E0

static int	on_update(t_game *game)
{
	// not commented
	if (!game->window->win_ptr)
		return (0);
	if (display_title_screen(game, game->window,
			game->gameplay->is_title_screen))
		return (0);
	if (display_tutorial(game, game->gameplay, game->window,
			game->gameplay->tutorial_status))
		return (0);
	if (game->gameplay->is_start)
		game->gameplay->is_start = false;
	if (display_victory_text(game, &game->gameplay->victory_text_status))
		return (0);
	if (display_end_screen(game, game->gameplay->is_end))
		return (0);
	if (display_menu(game, game->window, game->gameplay->is_pause))
		return (0);
	if (display_qte(game, &game->gameplay->player->qte, game->gameplay->player,
			game->gameplay->guards))
		return (0);
	if (game->gameplay->is_stop == false)
	{
		move_player(game, game->gameplay->player);
		check_collider(game, game->gameplay->player, game->gameplay->guards);
		gameplay_features(game, game->gameplay);
	}
	camera(game, game->camera, game->gameplay->player);
	display_sprites(game, game->camera, game->window);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, 0, 0);
	if (IS_DEBUG)
		debug_fps(game);
	calculate_fps(&game->gameplay->fps, &game->gameplay->delta_time);
	return (0);
}

void	start_game(t_game *game)
{
	// not commented
	game->gameplay->is_title_screen = true;
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

// 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
// 1000000000000000000000000000000000000000000000000E0000000000000000000000000000000000001
// 1000000000001111111111111111100000000000000000000C0000000000000000000000000000000000001
// 100000000000111111111111111110000000000000000000000000000000000000000000000000000000001
// 1000000000001111111111111111100000000000000000000C00C00C00C0000000000011110000000000001
// 100000000000111111111111111110000000000000000000000000000000000000000001110000000000001
// 100000000000111111111111111110000000000000G000000C00000000C0000000000001110000000000001
// 10100000000000000000000000000000000000000000000000000000G1P100000010G001000000000000001
// 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
