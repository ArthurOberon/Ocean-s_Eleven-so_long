/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_tutorial.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:15:42 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/12 15:42:18 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_tutorial(t_game *game, t_gameplay *gameplay,
	t_window *window, int tutorial_status)
{
	t_sprite	*sprite;

	// not commented
	if (tutorial_status == -1)
		return (0);
	sprite = window->map_sprites[game->level->nb_cases + e_tutorial];
	memcpy_img(&window->img, (t_vector_2){0, 0},
		&(sprite->sprite_img[0]),
		(t_vector_2[2]){{0, 0}, {0, 0}});
	display_dialogue(game, game->gameplay->dialogue);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img.mlx_img, 0, 0);
	return (1);
}
