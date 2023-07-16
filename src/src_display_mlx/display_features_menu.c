/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:07:00 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 21:23:28 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_menu(t_game *game, t_window *window, int is_pause)
{
	// not commented
	t_sprite	*sprite;
	t_vector_2	pos;

	if (is_pause == 0)
		return (0);
	pos.x = (WINDOW_WIDTH / 6) - (CHUNK_SIZE / 2);
	pos.y = (WINDOW_HEIGHT / 2) - (CHUNK_SIZE / 2);
	sprite = game->assets->button_pause;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);
	pos.x = (WINDOW_WIDTH / 2) - (CHUNK_SIZE / 2);
	sprite = game->assets->button_reset;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);
	pos.x = (WINDOW_WIDTH - (WINDOW_WIDTH / 6)) - (CHUNK_SIZE / 2);
	sprite = game->assets->button_quit;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);
	pos.y = 0;
	sprite = game->assets->button_tutorial;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[sprite->frame]);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img.mlx_img, 0, 0);
	return (1);
}
