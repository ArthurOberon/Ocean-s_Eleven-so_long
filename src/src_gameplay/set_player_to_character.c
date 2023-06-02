/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_to_character.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:35:44 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/02 17:14:05 by arthurobero      ###   ########.fr       */
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
	add_text(game, &gameplay->texts_box_list,
		&gameplay->texts[e_text_rusty_to_danny_1], false);
	player->player_character = e_main;
	// gameplay->texts_box_list->text_box->talking_character
		// = player->player_character;
	add_text(game, &gameplay->texts_box_list,
		&gameplay->texts[e_text_rusty_to_danny_2], false);
}

static void	set_player_to_eater(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	player->player_character = e_eater;
}

static void	set_player_to_thief(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	player->player_character = e_thief;
}

static void	set_player_to_bomber(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	player->hp = 1;
	player->player_character = e_bomber;
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
