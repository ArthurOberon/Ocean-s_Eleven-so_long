/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_player_to_character_main.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:25:01 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 23:42:12 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set the player to a character.
 * 
 * @param game game struct, used to exit the game if a malloc fail.
 * @param gameplay gameplay struct,
 * used to get the dialogue struct and the available_character array.
 * @param player player struct, to set his player_character.
 * @param character character to set the player to.
 */
void	set_player_to_character(t_game *game, t_gameplay *gameplay,
	t_player *player, int character)
{
	if (character == e_main && (gameplay->available_character[e_main] == 1
			|| gameplay->available_character[e_main] == 3))
	{
		set_player_to_main(game, gameplay, player);
	}
	else if (character == e_eater
		&& (gameplay->available_character[e_eater] == 1
			|| gameplay->available_character[e_eater] == 3))
	{
		set_player_to_eater(game, gameplay, player);
	}
	else if (character == e_thief
		&& (gameplay->available_character[e_thief] == 1
			|| gameplay->available_character[e_thief] == 3))
	{
		set_player_to_thief(game, gameplay, player);
	}
	else if (character == e_bomber
		&& (gameplay->available_character[e_bomber] == 1
			|| gameplay->available_character[e_bomber] == 3))
	{
		set_player_to_bomber(game, gameplay, player);
	}
}
