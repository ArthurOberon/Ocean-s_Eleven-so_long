/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:07:00 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/10 16:47:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_menu(t_game *game, t_window *window, int nb_cases)
{
	// not commented
	t_sprite	*sprite;
	t_vector_2	pos;

	display_sprites(game, game->camera, game->window);

	sprite = window->map_sprites[nb_cases + e_button_pause];
	pos.x = WINDOW_WIDTH / 4 - sprite->size / 2;
	pos.y = WINDOW_HEIGHT / 2 - sprite->size / 2;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);

	sprite = window->map_sprites[nb_cases + e_button_restart];
	pos.x += WINDOW_WIDTH / 4;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);

	sprite = window->map_sprites[nb_cases + e_button_quit];
	pos.x += WINDOW_WIDTH / 4;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);

	sprite = window->map_sprites[nb_cases + e_button_tutorial];
	pos.y -= WINDOW_HEIGHT / 3;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);

	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, 0, 0);
}
