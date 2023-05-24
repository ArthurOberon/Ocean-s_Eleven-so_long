/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:08:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/24 22:17:21 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_character_selection(t_game *game, t_window *window,
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
		put_image_to_image(&window->img, pos_display,
			&(sprite->sprite_img)[0]);
	}
	i = player->player_character;
	pos_display.x = 10 + (size_sprite * i) - (i * 2);
	put_image_to_image(&window->img, pos_display,
		&(sprite_selection_box->sprite_img)[1]);
}

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

void	display_ui(t_game *game, t_window *window, t_gameplay *gameplay)
{
	display_heart(window, gameplay->player,
		game->window->map_sprites[game->level->nb_cases + e_heart]);
	display_character_selection(game, window, gameplay->player);
}
