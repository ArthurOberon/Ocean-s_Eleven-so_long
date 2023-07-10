/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_game_features.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:14:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/11 00:20:49 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Close the game and free all the memory.
 * 
 * @param game game struct, to free all the memory.
 * @return int 0.
 */
int	close_game(t_game *game)
{
	exit_game(*game, NULL);
	return (0);
}

/**
 * @brief Secure the game when the player click outside the window,
 * by setting the player direction to 0.
 * 
 * @param game game struct, used to set the player direction to 0.
 * @return int 1.
 */
int	secure_lost_focus(t_game *game)
{
	game->gameplay->player->player_dir.x = 0;
	game->gameplay->player->player_dir.y = 0;
	return (0);
}

/**
 * @brief Handle the out game features, meaning the pause, restart and quit.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct, or close the game.
 */
void	handle_out_game_features(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		close_game(game);
	}
	if (keysym == XK_P || keysym == XK_p)
	{
		game->gameplay->menu_status = 0;
		if (game->gameplay->is_pause == false)
			game->gameplay->is_pause = true;
		else
		{
			game->gameplay->is_pause = false;
		}
	}
	if (keysym == XK_R || keysym == XK_r)
	{
		restart_the_game(game);
	}
}

int	handle_end_screen(int keysym, t_game *game)
{
	// not commented
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q
		|| keysym == XK_space)
		close_game(game);
	return (0);
}
