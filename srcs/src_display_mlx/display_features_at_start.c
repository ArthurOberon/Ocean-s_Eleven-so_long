/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_at_start.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:15:42 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 11:05:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Display the tutorial.
 * 
 * @param game game struct, used to get the assets struct.
 * @param gameplay gameplay struct, used to get the dialogue struct.
 * @param window window struct, used to display on.
 * @param tutorial_status int, used to know which tutorial frame
 * must be displayed.
 * @return int 1 if the tutorial was displayed, 0 otherwise.
 */
int	display_tutorial(t_game *game, t_gameplay *gameplay,
	t_window *window, int tutorial_status)
{
	t_sprite	*sprite;

	if (tutorial_status == -1)
		return (0);
	sprite = game->assets->tutorial;
	memcpy_img(&window->img, (t_vector_2){0, 0},
		&(sprite->sprite_img[tutorial_status]),
		(t_vector_2[2]){{0, 0}, {0, 0}});
	display_dialogue(game, gameplay->dialogue);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img.mlx_img, 0, 0);
	return (1);
}

/**
 * @brief Display the title screen.
 * 
 * @param game game struct, used to get the assets struct.
 * @param window window struct, used to display on.
 * @param is_title_screen int, used to know if the title screen
 * must be displayed.
 * @return int 1 if the title screen was displayed, 0 otherwise.
 */
int	display_title_screen(t_game *game, t_window *window,
	int is_title_screen)
{
	t_sprite	*sprite;

	if (is_title_screen == 1)
	{
		sprite = game->assets->title_screen;
		memcpy_img(&window->img, (t_vector_2){0, 0},
			&(sprite->sprite_img[0]),
			(t_vector_2[2]){{0, 0}, {0, 0}});
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			window->img.mlx_img, 0, 0);
		return (1);
	}
	return (0);
}
