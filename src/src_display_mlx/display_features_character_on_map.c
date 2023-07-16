/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_character_on_map.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:17:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 20:49:08 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief display one character on the map.
 * 
 * @param game game struct, used to get the level and camera struct.
 * @param window window struct, used to display on.
 * @param sprite the sprite to display.
 * @param i index of the map.
 */
static void	display_one_character_on_map(t_game *game,
	t_window *window, t_sprite *sprite, int i)
{
	t_vector_2	pos_tmp;

	pos_tmp = chunk_to_pixel_pos(i, game->level->map_vector.x);
	pos_tmp.x = pos_tmp.x - game->camera->camera_f_pos.x;
	pos_tmp.y = pos_tmp.y - game->camera->camera_f_pos.y;
	if (pos_tmp.x > game->camera->camera_f_size.x)
		pos_tmp.x = game->camera->camera_f_size.x - 1;
	if (pos_tmp.y > game->camera->camera_f_size.y)
		pos_tmp.y = game->camera->camera_f_size.y - 1;
	display_one_sprite_with_transparency(window, sprite, pos_tmp);
}

/**
 * @brief display the characters not available for the player on the map.
 * 
 * @param game game struct, used to get the level struct.
 * @param window window struct, used to display on.
 * @param gameplay gameplay struct, used to get the available characters.
 * @param i index of the map.
 */
static void	display_characters_on_map(t_game *game, t_window *window, int i)
{
	t_sprite	*sprite;

	sprite = NULL;
	if (game->level->map[i] == 'D')
		sprite = game->assets->player_danny_idle;
	else if (game->level->map[i] == 'R')
		sprite = game->assets->player_rusty_idle;
	else if (game->level->map[i] == 'L')
		sprite = game->assets->player_linus_idle;
	else if (game->level->map[i] == 'B')
		sprite = game->assets->player_basher_idle;
	if (sprite != NULL)
	{
		update_frame(sprite);
		display_one_character_on_map(game, window, sprite, i);
	}
}

/**
 * @brief Get the characters not available for the player on the map.
 * 
 * @param game game struct, used to get the level struct.
 * @param window window struct, used to display on.
 * @param gameplay gameplay struct, used to check the available characters.
 */
void	get_characters_on_map(t_game *game, t_window *window,
	t_gameplay *gameplay)
{
	int			i;

	if ((gameplay->available_character[0] == 1
			|| gameplay->available_character[0] == 3)
		&& (gameplay->available_character[1] == 1
			|| gameplay->available_character[1] == 3)
		&& (gameplay->available_character[2] == 1
			|| gameplay->available_character[2] == 3)
		&& (gameplay->available_character[3] == 1
			|| gameplay->available_character[3] == 3))
		return ;
	i = 0;
	while (i < game->level->nb_cases)
	{
		display_characters_on_map(game, window, i);
		i++;
	}
}
