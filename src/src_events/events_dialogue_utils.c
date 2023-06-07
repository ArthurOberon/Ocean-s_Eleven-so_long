/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box_events_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:17:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 22:17:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set the all texts remain one collectible to a status (true or false).
 * 
 * @param texts texts struct, used to set the texts.
 * @param status status to set the texts.
 */
static void	set_all_texts_remain_one_collectible(t_text *texts, bool status)
{
	texts[e_text_remain_one_collectible_danny].has_been_display = status;
	texts[e_text_remain_one_collectible_rusty].has_been_display = status;
	texts[e_text_remain_one_collectible_linus].has_been_display = status;
	texts[e_text_remain_one_collectible_basher].has_been_display = status;
}

/**
 * @brief Set the all texts remain zero collectible to a status (true or false).
 * 
 * @param texts texts struct, used to set the texts.
 * @param status status to set the texts.
 */
static void	set_all_texts_remain_zero_collectible(t_text *texts, bool status)
{
	texts[e_text_remain_zero_collectible_danny].has_been_display = status;
	texts[e_text_remain_zero_collectible_rusty].has_been_display = status;
	texts[e_text_remain_zero_collectible_linus].has_been_display = status;
	texts[e_text_remain_zero_collectible_basher].has_been_display = status;
}

/**
 * @brief Get the dialogue when it's remaining 1 collectible.
 * 
 * @param game 
 * @param gameplay 
 */
void	get_text_box_events_remain_one_collectible(t_game *game,
	t_gameplay *gameplay)
{
	if (gameplay->nb_collect_remain == 1 && game->level->nb_collect != 1)
	{
		if (gameplay->player->player_character == e_main)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_one_collectible_danny]);
		else if (gameplay->player->player_character == e_eater)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_one_collectible_rusty]);
		else if (gameplay->player->player_character == e_thief)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_one_collectible_linus]);
		else if (gameplay->player->player_character == e_bomber)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_one_collectible_basher]);
		else
			return ;
		set_all_texts_remain_one_collectible(gameplay->all_texts, true);
	}
}

/**
 * @brief Get the dialogue when it's remaining 0 collectible.
 * 
 * @param game game struct, used to exit the game if a malloc fail.
 * @param gameplay gameplay struct,
 * used to get the player and the dialogue struct.
 */
void	get_text_box_events_remain_zero_collectible(t_game *game,
	t_gameplay *gameplay)
{
	if (gameplay->nb_collect_remain == 0)
	{
		if (gameplay->player->player_character == e_main)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_zero_collectible_danny]);
		if (gameplay->player->player_character == e_eater)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_zero_collectible_rusty]);
		if (gameplay->player->player_character == e_thief)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_zero_collectible_linus]);
		if (gameplay->player->player_character == e_bomber)
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_remain_zero_collectible_basher]);
		else
			return ;
		set_all_texts_remain_zero_collectible(gameplay->all_texts, true);
	}
}
