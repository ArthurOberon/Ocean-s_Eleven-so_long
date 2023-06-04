/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/04 19:55:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief transform a character to lower case.
 * 
 * @param character character to transform.
 * @return int character transformed.
 */
static int	ft_tolower(int character)
{
	if (character >= 65 && character <= 90)
		return (character + 32);
	return (character);
}

/**
 * @brief display one character/letter on the text box.
 * 
 * @param game game struct, used to get the level struct.
 * @param window window struct, used to display on.
 * @param pos_display position to display the character/letter.
 * @param character character/letter to display.
 */
void	display_character(t_game *game, t_window *window,
	t_vector_2 pos_display, char character)
{
	character = ft_tolower(character);
	if (character >= 97 && character <= 122)
	{
		if (character != ' ')
		{
			put_image_to_image(&window->img, pos_display,
				&(window->map_sprites[game->level->nb_cases
					+ e_alphabet]->sprite_img)[character - 'a']);
		}
	}
	if (character >= 33 && character <= 63)
	{
		put_image_to_image(&window->img, pos_display,
			&(window->map_sprites[game->level->nb_cases
				+ e_special_character]->sprite_img)[character - '!']);
	}
}

/**
 * @brief display only one page of a text_box.
 * 
 * @param game game struct, used to get the level struct.
 * @param text_box text_box struct, used to get the text to display.
 * @param pos_display position to display the text.
 * @param pos_max position max to display the text before going to the line.
 */
static void	display_one_page_on_text_box(t_game *game, t_text_box text_box,
	t_vector_2 pos_display, t_vector_2 pos_max)
{
	int			i;
	int			pos_display_x_start;
	int			size_letter;
	t_vector_2	pos_in_text;

	i = 0;
	pos_in_text = (t_vector_2){0, 0};
	pos_display_x_start = pos_display.x;
	size_letter = game->window->map_sprites[game->level->nb_cases
		+ e_alphabet]->sprite_img->size.x;
	while (text_box.text_pages[text_box.page_in][i])
	{
		if (pos_in_text.x++ >= pos_max.x)
		{
			pos_in_text.x = 0;
			pos_in_text.y += 1;
			pos_display.x = pos_display_x_start;
			pos_display.y += size_letter + 10;
		}
		if (pos_in_text.y >= pos_max.y)
			break ;
		display_character(game, game->window, pos_display,
			text_box.text_pages[text_box.page_in][i++]);
		pos_display.x += size_letter;
	}
}

/**
 * @brief Display the face of the talking character next to the text.
 * 
 * @param game game struct, used to get the window and level struct.
 * @param pos_display position to display the face.
 * @param talking_character the character choosen by the player.
 */
static void	display_face(t_game *game, t_vector_2 pos_display,
	int talking_character)
{
	t_sprite	*sprite_face;

	sprite_face = game->window->map_sprites[game->level->nb_cases
		+ talking_character];
	put_image_to_image(&game->window->img, pos_display,
		&(sprite_face->sprite_img)[0]);
}

/**
 * @brief Display one text box of dialogue (list of texts box).
 * 
 * @param game game struct, used to get the level struct.
 * @param window window struct, used to display on.
 * @param text_box text box,
 * first node of dialogue (list of text_box), to display.
 */
void	display_one_node_texts_box(t_game *game, t_window *window,
	t_text_box text_box)
{
	t_sprite	*background;

	if (text_box.is_display == false)
		return ;
	background = window->map_sprites[game->level->nb_cases + e_background_text];
	put_image_to_image(&window->img, text_box.pos_display_background,
		&(background->sprite_img)[0]);
	display_face(game, text_box.pos_display_face, text_box.talking_character);
	display_one_page_on_text_box(game, text_box, text_box.pos_display_text,
		text_box.characters_max);
}
