/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 11:36:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Update the game, called non-stop by on_update().
 * 
 * @param game game struct.
 * @return int 1 if none of the functions are called, 0 otherwise.
 */
static int	on_update_(t_game *game)
{
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
	return (1);
}

/**
 * @brief Update the game, called non-stop by mlx_loop_hook.
 * All the game is make here (display, gameplay, etc...).
 * 
 * @param game game struct.
 * @return int 0.
 */
static int	on_update(t_game *game)
{
	if (!on_update_(game))
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

/**
 * @brief Start the game, set all the hooks and start the mlx loop.
 * 
 * @param game game struct, used to set the hooks.
 */
void	start_game(t_game *game)
{
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
