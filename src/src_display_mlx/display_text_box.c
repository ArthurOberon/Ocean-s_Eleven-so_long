/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/22 16:04:39 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_character(t_game *game, t_window *window,
	t_vector_2 pos_display, char character)
{
	if (character != ' ')
	{
		put_image_to_image(&window->img, pos_display,
			&(window->map_sprites[game->level->nb_cases
				+ e_alphabet]->sprite_img)[character - 'a']);
	}
}

static void	display_text(t_game *game, t_text_box text_box,
	t_vector_2 pos_display, t_vector_2 pos_max)
{
	int			i;
	int			pos_display_x_start;
	int			size_alphabet;
	t_vector_2	pos_in_text;

	i = 0;
	pos_in_text.x = 0;
	pos_in_text.y = 0;
	pos_display_x_start = pos_display.x;
	size_alphabet = game->window->map_sprites[game->level->nb_cases
		+ e_alphabet]->sprite_img->size.x;
	while (text_box.text[i])
	{
		if (pos_in_text.x >= pos_max.x)
		{
			pos_in_text.x = 0;
			pos_in_text.y += 1;
			pos_display.x = pos_display_x_start;
			pos_display.y += size_alphabet + 10;
		}
		// printf("%d / %d\n", pos_in_text.y, pos_max.y);
		if (pos_in_text.y >= pos_max.y)
			break ;
		display_character(game, game->window, pos_display, text_box.text[i]);
		i++;
		pos_in_text.x++;
		pos_display.x += size_alphabet;
	}
}

static void	display_face(t_game *game, t_vector_2 *pos_display)
{
	t_sprite	*sprite_face;

	sprite_face = game->window->map_sprites[game->level->nb_cases
		+ game->gameplay->player->player_character];
	put_image_to_image(&game->window->img, *pos_display,
		&(sprite_face->sprite_img)[0]);
	pos_display->x += sprite_face->sprite_img->size.x;
}

void	display_text_box(t_game *game, t_window *window, t_text_box text_box)
{
	int			size_alphabet;
	t_vector_2	pos_display;
	t_sprite	*background;
	t_vector_2	size_max;
	t_vector_2	margin_size;

	if (text_box.is_diplay == false)
		return ;
	game->gameplay->is_stop = true;
	background = window->map_sprites[game->level->nb_cases + e_background_text];
	pos_display = (t_vector_2){20,
		WINDOW_HEIGHT - 50 - background->sprite_img->size.y};
	put_image_to_image(&window->img, pos_display, &(background->sprite_img)[0]);
	margin_size.x = 20;
	margin_size.y = 30;
	pos_display.x += margin_size.x;
	pos_display.y += margin_size.y;
	display_face(game, &pos_display);
	size_alphabet = window->map_sprites[game->level->nb_cases + e_alphabet]
		->sprite_img->size.x;
	size_max.x = (background->sprite_img->size.x - pos_display.x)
		/ size_alphabet;
	size_max.y = (background->sprite_img->size.y - (margin_size.y * 2))
		/ (size_alphabet + 10);
	display_text(game, text_box, pos_display, size_max);
}
