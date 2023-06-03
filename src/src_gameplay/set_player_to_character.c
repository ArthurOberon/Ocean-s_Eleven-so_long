/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_to_character.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:35:44 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/02 19:21:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_to_main(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	if (player->has_been_hit == false)
		player->hp = 2;
	else
		player->hp = 1;
	if (player->player_character == e_eater)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_rusty_to_danny_1], false);
		player->player_character = e_main;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_rusty_to_danny_2], false);
	}
	else if (player->player_character == e_thief)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_linus_to_danny_1], false);
		player->player_character = e_main;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_linus_to_danny_2], false);
	}
	else if (player->player_character == e_bomber)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_basher_to_danny_1], false);
		player->player_character = e_main;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_basher_to_danny_2], false);
	}
}

static void	set_player_to_eater(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	if (player->player_character == e_main)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_danny_to_rusty_1], false);
		player->player_character = e_eater;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_danny_to_rusty_2], false);
	}
	else if (player->player_character == e_thief)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_linus_to_rusty_1], false);
		player->player_character = e_eater;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_linus_to_rusty_2], false);
	}
	else if (player->player_character == e_bomber)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_basher_to_rusty_1], false);
		player->player_character = e_eater;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_basher_to_rusty_2], false);
	}
}

static void	set_player_to_thief(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	if (player->player_character == e_main)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_danny_to_linus_1], false);
		player->player_character = e_thief;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_danny_to_linus_2], false);
	}
	else if (player->player_character == e_eater)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_rusty_to_linus_1], false);
		player->player_character = e_thief;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_rusty_to_linus_2], false);
	}
	else if (player->player_character == e_bomber)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_basher_to_linus_1], false);
		player->player_character = e_thief;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_basher_to_linus_2], false);
	}
}

static void	set_player_to_bomber(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	if (player->player_character == e_main)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_danny_to_basher_1], false);
		player->player_character = e_bomber;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_danny_to_basher_2], false);
	}
	else if (player->player_character == e_eater)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_rusty_to_basher_1], false);
		player->player_character = e_bomber;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_rusty_to_basher_2], false);
	}
	else if (player->player_character == e_thief)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_linus_to_basher_1], false);
		player->player_character = e_bomber;
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_linus_to_basher_2], false);
	}
}

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
