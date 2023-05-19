/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:37:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/19 20:09:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_text_box(t_game *game, t_window *window, t_text_box text_box)
{
	int			i;
	int			x_size;
	t_vector_2	pos;
	t_sprite	*background;

	if (text_box.is_diplay == false)
		return ;
	game->gameplay->is_stop = true;
	background = window->map_sprites[game->level->nb_cases + e_background_text];
	pos = (t_vector_2){20, WINDOW_HEIGHT - 50 - background->sprite_img->size.y};
	put_image_to_image(&window->img, pos, &(background->sprite_img)[0]);
	x_size = window->map_sprites[game->level->nb_cases + e_alphabet]
		->sprite_img->size.x;
	i = 0;
	while (text_box.text[i])
	{
		if (text_box.text[i] != ' ')
		{
			pos = (t_vector_2){x_size * (i + 1) + 20,
				WINDOW_HEIGHT - background->sprite_img->size.y};
			put_image_to_image(&window->img, pos,
				&(window->map_sprites[game->level->nb_cases
					+ e_alphabet]->sprite_img)[text_box.text[i] - 'a']);
		}
		i++;
	}
}
