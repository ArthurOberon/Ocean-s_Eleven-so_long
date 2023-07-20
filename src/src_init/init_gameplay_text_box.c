/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_text_box.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:03:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 11:11:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize display variables of the text_box struct.
 * 
 * @param game game struct, used to get the level and window struct.
 * @param text_box t_text_box struct to initialize.
 * @param background background sprite of the text_box.
 * @param sprite_face sprite of the face of the text_box.
 */
static void	init_text_box_display_variables(t_game *game, t_text_box *text_box,
	t_sprite *background, t_sprite *sprite_face)
{
	text_box->pos_display_background = (t_vector_2){20,
		WINDOW_HEIGHT - 50 - background->sprite_img->size.y};
	text_box->margin_size.x = 20;
	text_box->margin_size.y = 30;
	text_box->pos_display_face.x = text_box->pos_display_background.x
		+ text_box->margin_size.x;
	text_box->pos_display_face.y = text_box->pos_display_background.y
		+ text_box->margin_size.y;
	text_box->pos_display_text = text_box->pos_display_face;
	text_box->pos_display_text.x += sprite_face->sprite_img->size.x;
	text_box->size_one_alphabet = game->assets->alphabet->sprite_img->size.x;
	text_box->characters_max.x = (background->sprite_img->size.x
			- text_box->pos_display_text.x) / text_box->size_one_alphabet;
	text_box->characters_max.y = (background->sprite_img->size.y
			- (text_box->margin_size.y * 2))
		/ (text_box->size_one_alphabet + 10);
	text_box->characters_max_one_box = text_box->characters_max.x
		* text_box->characters_max.y;
}

/**
 * @brief initialize a text_box struct.
 * 
 * @param game game struct, used to get the assets struct.
 * @param gameplay gameplay struct, used to get the t_sprite array talking_face.
 * @param text_box text_box struct to initialize.
 * @param talking_character talking character of the text_box.
 */
void	init_one_text_box(t_game *game, t_gameplay *gameplay,
	t_text_box *text_box, int talking_character)
{
	t_sprite	*background;
	t_sprite	*sprite_face;

	background = game->assets->background_text;
	sprite_face = gameplay->talking_face[talking_character];
	init_text_box_display_variables(game, text_box, background, sprite_face);
	text_box->is_display = false;
	text_box->read_all = false;
	text_box->page_number = 0;
	text_box->page_in = 0;
	text_box->talking_character = talking_character;
	text_box->text = NULL;
	text_box->text_pages = NULL;
}
