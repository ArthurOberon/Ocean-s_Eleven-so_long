/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:27:20 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 22:04:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Handle the key press events.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to set events depending on the key pressed.
 * @return int 0
 */
int	handle_keypress(int keysym, t_game *game)
{
	// debug text_box
	if (keysym == XK_O || keysym == XK_o)
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_debug],
			game->gameplay->player->player_character);
	// debug text_box
	if (game->gameplay->is_title_screen)
		return (handle_title_screen(keysym, game));
	if (game->gameplay->tutorial_status != -1)
		return (handle_tutorial(keysym, game));
	if (game->gameplay->is_end != 0)
		return (handle_end_screen(keysym, game));
	handle_out_game_features(keysym, game);
	if (game->gameplay->is_pause == 1)
	{
		game->gameplay->player->player_dir.x = 0;
		game->gameplay->player->player_dir.y = 0;
		handle_pause_menu(keysym, game);
		return (0);
	}
	if (handle_dialogue(keysym, game))
	{
		game->gameplay->player->player_dir.x = 0;
		game->gameplay->player->player_dir.y = 0;
		return (0);
	}
	if (game->gameplay->is_pause == false
		&& game->gameplay->is_stop == false)
	{
		handle_player_move_press(keysym, game);
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
	if (game->gameplay->is_pause == 1 || game->gameplay->is_stop == 1)
	{
		return (1);
	}
	handle_player_move_release(keysym, game);
	return (0);
}
