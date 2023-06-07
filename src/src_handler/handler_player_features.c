/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_player_features.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:58:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/08 00:36:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Handle the pickpocket feature,
 * launch the qte if the player press SPACE, the player is playing as a thief,
 * and with a guard near him. And stop the qte if the player press DELETE.
 * But don't launch the qte if a dialogue is display.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct.
 */
void	handle_pickpocket(int keysym, t_game *game)
{
	if (game->gameplay->player->player_character != e_thief)
		return ;
	if (keysym == XK_space)
	{
		game->gameplay->player->qte.pressed = true;
		if (game->gameplay->player->qte.time_to_press == false)
		{
			game->gameplay->player->qte.pressed_in_time = false;
			game->gameplay->player->qte.is_pickpocketing = true;
		}
		else
			game->gameplay->player->qte.pressed_in_time = true;
	}
	if (keysym == XK_Delete)
	{
		game->gameplay->player->qte.time_to_press = false;
		game->gameplay->player->qte.pressed_in_time = false;
		game->gameplay->player->qte.is_pickpocketing = false;
	}
}

/**
 * @brief Handle change character player.
 * When the player press 1, 2, 3 or 4 the player change character.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to exit the game if a malloc fail.
 * @param gameplay gameplay struct,
 * used to get the dialogue struct and the available_character array.
 * @param player player struct, to set his player_character.
 */
void	handle_change_character_player(int keysym, t_game *game,
	t_gameplay *gameplay, t_player *player)
{
	if (keysym == XK_1 || keysym == XK_2 || keysym == XK_3 || keysym == XK_4)
	{
		set_player_to_character(game, gameplay, player, keysym - XK_1);
		return ;
	}
}
