/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:27:20 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/10 00:31:14 by aoberon          ###   ########.fr       */
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
	return (1);
}

/**
 * @brief Handle the out game features, meaning the pause, restart and quit.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct, or close the game.
 */
static void	handle_out_game_features(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		close_game(game);
	}
	if (keysym == XK_P || keysym == XK_p)
	{
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

/**
 * @brief Handle the key press events.
 * 
 * @param keysym 
 * @param game 
 * @return int 
 */
int	handle_keypress(int keysym, t_game *game)
{
	// debug text_box
	if (keysym == XK_O || keysym == XK_o)
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_debug]);
	// debug text_box
	handle_out_game_features(keysym, game);
	if (game->gameplay->is_pause == 1)
	{
		handle_pause_menu(keysym, game);
		return (1);
	}
	if (handle_dialogue(keysym, game))
		return (1);
	handle_player_move_press(keysym, game);
	if (game->gameplay->is_pause == false
		&& game->gameplay->is_stop == false)
	{
		handle_bomb(keysym, game);
		handle_change_character_player(keysym, game, game->gameplay,
			game->gameplay->player);
	}
	handle_pickpocket(keysym, game);
	return (0);
}

/**
 * @brief Handle the key release events.
 * 
 * @param keysym key released.
 * @param game game struct, used to set events depending on the key released.
 * @return int 0.
 */
int	handle_keyrelease(int keysym, t_game *game)
{
	if (game->gameplay->is_pause == 1)
	{
		// handle_menu_release() ?
		return (1);
	}
	handle_player_move_release(keysym, game);
	return (0);
}
