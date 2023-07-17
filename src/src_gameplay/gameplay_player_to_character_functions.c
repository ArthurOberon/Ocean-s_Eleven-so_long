/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_player_to_character_functions.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:35:44 by arthurobero       #+#    #+#             */
/*   Updated: 2023/07/17 15:03:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_main_hp(t_player *player)
{
	if (player->has_been_hit == false)
		player->hp = 2;
	else
		player->hp = 1;
}

/**
 * @brief Set the player to the main character.
 * 
 * @param game game struct, used to exit the game if malloc fail.
 * @param gameplay gameplay struct, used to get the dialogue struct to add text.
 * @param player player struct, used to set the player character.
 */
void	set_player_to_main(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	set_player_main_hp(player);
	if (player->player_character == e_eater)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_rusty_to_danny_1], e_eater);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_rusty_to_danny_2], e_main);
	}
	else if (player->player_character == e_thief)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_linus_to_danny_1], e_thief);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_linus_to_danny_2], e_main);
	}
	else if (player->player_character == e_bomber)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_basher_to_danny_1], e_bomber);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_basher_to_danny_2], e_main);
	}
	player->player_character = e_main;
}

/**
 * @brief Set the player to the eater character.
 * 
 * @param game game struct, used to exit the game if malloc fail.
 * @param gameplay gameplay struct, used to get the dialogue struct to add text.
 * @param player player struct, used to set the player character.
 */
void	set_player_to_eater(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	if (player->player_character == e_main)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_danny_to_rusty_1], e_main);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_danny_to_rusty_2], e_eater);
	}
	else if (player->player_character == e_thief)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_linus_to_rusty_1], e_thief);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_linus_to_rusty_2], e_eater);
	}
	else if (player->player_character == e_bomber)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_basher_to_rusty_1], e_bomber);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_basher_to_rusty_2], e_eater);
	}
	player->player_character = e_eater;
}

/**
 * @brief Set the player to the thief character.
 * 
 * @param game game struct, used to exit the game if malloc fail.
 * @param gameplay gameplay struct, used to get the dialogue struct to add text.
 * @param player player struct, used to set the player character.
 */
void	set_player_to_thief(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	if (player->player_character == e_main)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_danny_to_linus_1], e_main);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_danny_to_linus_2], e_thief);
	}
	else if (player->player_character == e_eater)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_rusty_to_linus_1], e_eater);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_rusty_to_linus_2], e_thief);
	}
	else if (player->player_character == e_bomber)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_basher_to_linus_1], e_bomber);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_basher_to_linus_2], e_thief);
	}
	player->player_character = e_thief;
}

/**
 * @brief Set the player to bomber character.
 * 
 * @param game game struct, used to exit the game if malloc fail.
 * @param gameplay gameplay struct, used to get the dialogue struct to add text.
 * @param player player struct, used to set the player character.
 */
void	set_player_to_bomber(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	if (player->player_character == e_main)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_danny_to_basher_1], e_main);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_danny_to_basher_2], e_bomber);
	}
	else if (player->player_character == e_eater)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_rusty_to_basher_1], e_eater);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_rusty_to_basher_2], e_bomber);
	}
	else if (player->player_character == e_thief)
	{
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_linus_to_basher_1], e_thief);
		add_one_text_to_dialogue(game, &gameplay->dialogue,
			&gameplay->all_texts[e_text_linus_to_basher_2], e_bomber);
	}
	player->player_character = e_bomber;
}
