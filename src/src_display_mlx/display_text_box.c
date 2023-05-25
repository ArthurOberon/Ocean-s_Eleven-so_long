/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/25 17:05:25 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_character(t_game *game, t_window *window,
	t_vector_2 pos_display, char character)
{
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

static void	display_one_page_on_text_box(t_game *game, t_text_box text_box,
	t_vector_2 pos_display, t_vector_2 pos_max)
{
	int			i;
	int			pos_display_x_start;
	int			size_letter;
	t_vector_2	pos_in_text;

	i = 0;
	pos_in_text.x = 0;
	pos_in_text.y = 0;
	pos_display_x_start = pos_display.x;
	size_letter = game->window->map_sprites[game->level->nb_cases
		+ e_alphabet]->sprite_img->size.x;
	while (text_box.text_pages[text_box.page_in][i])
	{
		if (pos_in_text.x >= pos_max.x)
		{
			pos_in_text.x = 0;
			pos_in_text.y += 1;
			pos_display.x = pos_display_x_start;
			pos_display.y += size_letter + 10;
		}
		if (pos_in_text.y >= pos_max.y)
			break ;
		display_character(game, game->window, pos_display,
			text_box.text_pages[text_box.page_in][i]);
		i++;
		pos_in_text.x++;
		pos_display.x += size_letter;
	}
}

static void	display_face(t_game *game, t_vector_2 pos_display)
{
	t_sprite	*sprite_face;

	sprite_face = game->window->map_sprites[game->level->nb_cases
		+ game->gameplay->player->player_character];
	put_image_to_image(&game->window->img, pos_display,
		&(sprite_face->sprite_img)[0]);
}

void	display_text_box(t_game *game, t_window *window, t_text_box text_box)
{
	t_sprite	*background;

	if (text_box.is_display == false)
		return ;
	background = window->map_sprites[game->level->nb_cases + e_background_text];
	put_image_to_image(&window->img, text_box.pos_display_background,
		&(background->sprite_img)[0]);
	display_face(game, text_box.pos_display_face);
	display_one_page_on_text_box(game, text_box, text_box.pos_display_text,
		text_box.characters_max);
}
