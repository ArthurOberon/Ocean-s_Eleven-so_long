/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_ui_main.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:08:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/05 21:28:20 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief display one string on the window.
 * 
 * @param game game struct, used get the window struct.
 * @param pos_display position to display the string.
 * @param text text to display.
 * @param size_letter size of a letter.
 */
void	display_one_str(t_game *game, t_vector_2 pos_display,
	char *text, int size_letter)
{
	int	i;

	i = 0;
	while (text[i])
	{
		display_character(game, game->window, pos_display, text[i]);
		pos_display.x += size_letter;
		i++;
	}
}

/**
 * @brief Display one character on the bar of character selection.
 * 
 * @param game game struct, used to get the level, window and gameplay struct.
 * @param sprite spirte struct, used to get the sprite to display.
 * @param pos_display position to display the sprite.
 * @param i index of the character on all characters.
 */
static void	display_one_character_on_bar_selection(t_game *game,
	t_sprite *sprite, t_vector_2 pos_display, int i)
{
	if (game->gameplay->available_character[i] == 1
		|| game->gameplay->available_character[i] == 3)
		put_image_to_image(&game->window->img, pos_display,
			&(sprite->sprite_img)[0]);
	else
		put_image_to_image(&game->window->img, pos_display,
			&(game->window->map_sprites[game->level->nb_cases
				+ e_avatar_character]->sprite_img)[0]);
}

/**
 * @brief Display the bar of character selection
 * on the bottom left of the screen.
 * 
 * @param game game struct, used to get the level struct.
 * @param window window struct, used to get the sprites and display on.
 * @param player player struct, used to get the know the current character.
 */
static void	display_character_bar_selection(t_game *game, t_window *window,
	t_player *player)
{
	int			i;
	int			size_sprite;
	t_sprite	*sprite;
	t_sprite	*sprite_selection_box;
	t_vector_2	pos_display;

	sprite_selection_box = window->map_sprites[game->level->nb_cases
		+ e_selection_box];
	i = -1;
	size_sprite = 0;
	while (++i < 4)
	{
		pos_display = (t_vector_2){10 + (size_sprite * i) - (i * 2),
			WINDOW_HEIGHT - CHUNK_SIZE - 10};
		sprite = window->map_sprites[game->level->nb_cases + i];
		size_sprite = sprite->sprite_img->size.x;
		put_image_to_image(&window->img, pos_display,
			&(sprite_selection_box->sprite_img)[0]);
		display_one_character_on_bar_selection(game, sprite, pos_display, i);
	}
	i = player->player_character;
	pos_display.x = 10 + (size_sprite * i) - (i * 2);
	put_image_to_image(&window->img, pos_display,
		&(sprite_selection_box->sprite_img)[1]);
}

/**
 * @brief Display the hearts of the player on the top right of the screen.
 * 
 * @param window window struct, used to display on.
 * @param player player struct, used to get the number of hp.
 * @param sprite sprite struct, used to get the sprite of the heart.
 */
static void	display_heart(t_window *window, t_player *player, t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < player->hp)
	{
		if (i == 2)
			break ;
		put_image_to_image(&window->img,
			(t_vector_2){WINDOW_WIDTH - CHUNK_SIZE - ((20 - (i * 45))),
			44 - CHUNK_SIZE},
			&(sprite->sprite_img)[sprite->frame]);
		i++;
	}
}

/**
 * @brief Display the UI of the game.
 * 
 * @param game game struct, used to get the level.
 * @param window window struct, used to get the sprites and display on.
 * @param gameplay gameplay struct, used to get the player struct.
 */
void	display_ui(t_game *game, t_window *window, t_gameplay *gameplay)
{
	display_heart(window, gameplay->player,
		window->map_sprites[game->level->nb_cases + e_heart]);
	display_character_bar_selection(game, window, gameplay->player);
	display_ui_boxs(game, window, gameplay);
}
