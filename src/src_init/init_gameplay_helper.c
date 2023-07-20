/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:08:17 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 10:45:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief initialize the small variables of the gameplay struct.
 * 
 * @param game game struct, used to get the level struct.
 * @param gameplay gameplay struct to initialize.
 */
static void	init_gameplay_small_variables(t_game *game, t_gameplay *gameplay)
{
	gameplay->is_pause = false;
	gameplay->is_stop = false;
	gameplay->is_display_plus_one = false;
	gameplay->is_title_screen = false;
	gameplay->is_start = false;
	gameplay->is_end = 0;
	gameplay->victory_text_status = 0;
	gameplay->tutorial_status = 0;
	gameplay->menu_status = 0;
	gameplay->fps = 0;
	gameplay->delta_time = 0;
	gameplay->nb_collect_get = 0;
	gameplay->nb_collect_remain = game->level->nb_collect;
	gameplay->nb_move = 0;
}

/**
 * @brief Initialize the available_character and chosen_character
 * of the gameplay struct.
 * 
 * @param gameplay gameplay struct to initialize.
 * @param available_character array of int,
 * to copy in the gameplay->available_character.
 * @param chosen_character int, to copy in the gameplay->chosen_character.
 */
static void	init_available_character_(t_gameplay *gameplay,
	int *available_character, int chosen_character)
{
	gameplay->available_character[0] = available_character[0];
	gameplay->available_character[1] = available_character[1];
	gameplay->available_character[2] = available_character[2];
	gameplay->available_character[3] = available_character[3];
	gameplay->chosen_character = chosen_character;
}

/**
 * @brief Initialize the talking face sprites.
 * 
 * @param assets assets struct, where the talking face sprites are stored.
 * @param gameplay gameplay struct, where the talking face sprites are stored.
 */
static void	init_sprites_talking_face(t_sprites_assets *assets,
	t_gameplay *gameplay)
{
	gameplay->talking_face[0] = assets->talking_danny;
	gameplay->talking_face[1] = assets->talking_rusty;
	gameplay->talking_face[2] = assets->talking_linus;
	gameplay->talking_face[3] = assets->talking_basher;
}

/**
 * @brief Initialize a part of the gameplay struct.
 * 
 * @param game game struct.
 * @param gameplay gameplay struct to initialize.
 * @param available_character array of int,
 * used to know which character is available.
 * @param chosen_character int, the character chosen by the player.
 */
void	init_gameplay_helper(t_game *game, t_gameplay *gameplay,
	int *available_character, int chosen_character)
{
	init_available_character_(gameplay, available_character, chosen_character);
	init_sprites_talking_face(game->assets, gameplay);
	init_gameplay_small_variables(game, gameplay);
}
