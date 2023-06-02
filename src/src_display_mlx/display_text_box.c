/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/02 16:38:24 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_tolower(int character)
{
	if (character >= 65 && character <= 90)
		return (character + 32);
	return (character);
}

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

static void	display_face(t_game *game, t_vector_2 pos_display,
	int talking_character)
{
	t_sprite	*sprite_face;

	sprite_face = game->window->map_sprites[game->level->nb_cases
		+ talking_character];
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
	display_face(game, text_box.pos_display_face, text_box.talking_character);
	display_one_page_on_text_box(game, text_box, text_box.pos_display_text,
		text_box.characters_max);
}

void	display_texts_box_list(t_game *game, t_texts_box_list *texts_box_list)
{
	if (texts_box_list == NULL)
		return ;
	display_text_box(game, game->window, *texts_box_list->text_box);
}
