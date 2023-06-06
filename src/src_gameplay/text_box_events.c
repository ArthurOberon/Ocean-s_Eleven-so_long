/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:10:48 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/06 21:21:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	text_box_events_start(t_game *game)
{
	if (game->gameplay->player->player_character == e_main)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_danny]);
	}
	else if (game->gameplay->player->player_character == e_eater)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_rusty]);
	}
	else if (game->gameplay->player->player_character == e_thief)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_linus]);
	}
	else if (game->gameplay->player->player_character == e_bomber)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_basher]);
	}
}

void	set_all_texts_remain_one_collectible(t_text *texts, bool status)
{
	texts[e_text_remain_one_collectible_danny].has_been_display = status;
	texts[e_text_remain_one_collectible_rusty].has_been_display = status;
	texts[e_text_remain_one_collectible_linus].has_been_display = status;
	texts[e_text_remain_one_collectible_basher].has_been_display = status;
}

static void	set_all_texts_remain_zero_collectible(t_text *texts, bool status)
{
	texts[e_text_remain_zero_collectible_danny].has_been_display = status;
	texts[e_text_remain_zero_collectible_rusty].has_been_display = status;
	texts[e_text_remain_zero_collectible_linus].has_been_display = status;
	texts[e_text_remain_zero_collectible_basher].has_been_display = status;
}

static void	text_box_events_remain_one_collectible(t_game *game,
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

static void	text_box_events_remain_zero_collectible(t_game *game,
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

void	text_box_events(t_game *game, t_gameplay *gameplay)
{
	text_box_events_remain_one_collectible(game, gameplay);
	text_box_events_remain_zero_collectible(game, gameplay);
}
