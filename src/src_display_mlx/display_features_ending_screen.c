/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_ending_screen.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:58:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 22:06:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// not commented ALL !!!

static void	display_characters_end_up(t_game *game, t_gameplay *gameplay,
	t_window *window)
{
	t_sprite	*sprite;
	t_vector_2	pos;

	pos.x = WINDOW_WIDTH / 2 - (CHUNK_SIZE * 1.5);
	if (gameplay->available_character[2] == 1
		|| gameplay->available_character[2] == 3)
	{
		pos.y = WINDOW_HEIGHT / 2;
		sprite = game->assets->player_linus_idle;
		put_image_to_image(&window->img, pos, &(sprite->sprite_img)[0]);
	}
	if (gameplay->available_character[3] == 1
		|| gameplay->available_character[3] == 3)
	{
		pos.x = WINDOW_WIDTH / 2 + (CHUNK_SIZE / 2);
		sprite = game->assets->player_basher_idle;
		put_image_to_image(&window->img, pos, &(sprite->sprite_img)[0]);
	}
}

static void	display_characters_end_down(t_game *game, t_gameplay *gameplay,
	t_window *window)
{
	t_sprite	*sprite;
	t_vector_2	pos;

	pos.y = (WINDOW_HEIGHT / 2) + CHUNK_SIZE / 2;
	if (gameplay->available_character[0] == 1
		|| gameplay->available_character[0] == 3)
	{
		pos.x = (WINDOW_WIDTH / 2) - CHUNK_SIZE;
		sprite = game->assets->player_danny_idle;
		put_image_to_image(&window->img, pos, &(sprite->sprite_img)[0]);
	}
	if (gameplay->available_character[1] == 1
		|| gameplay->available_character[1] == 3)
	{
		pos.x = WINDOW_WIDTH / 2;
		sprite = game->assets->player_rusty_idle;
		put_image_to_image(&window->img, pos, &(sprite->sprite_img)[0]);
	}
}

void	display_win_screen(t_game *game, t_gameplay *gameplay, t_window *window)
{
	t_sprite	*sprite;

	sprite = game->assets->win_screen;
	put_image_to_image(&window->img, (t_vector_2){0, 0},
		&(sprite->sprite_img)[0]);
	display_characters_end_up(game, gameplay, window);
	display_characters_end_down(game, gameplay, window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img.mlx_img, 0, 0);
}

void	display_lose_screen(t_game *game, t_gameplay *gameplay,
	t_window *window)
{
	t_vector_2	pos;
	t_sprite	*sprite;

	sprite = game->assets->lose_screen;
	put_image_to_image(&window->img, (t_vector_2){0, 0},
		&(sprite->sprite_img)[0]);
	display_characters_end_up(game, gameplay, window);
	display_characters_end_down(game, gameplay, window);
	put_image_to_image(&window->img, (t_vector_2){0, 0},
		&(sprite->sprite_img)[1]);
	put_image_to_image(&window->img, (t_vector_2){0, 0},
		&(sprite ->sprite_img)[2]);
	pos.x = CHUNK_SIZE + (CHUNK_SIZE / 2);
	pos.y = WINDOW_HEIGHT - (CHUNK_SIZE + (CHUNK_SIZE / 2));
	sprite = game->assets->guard_idle;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[0]);
	pos.x = WINDOW_WIDTH - (CHUNK_SIZE + (CHUNK_SIZE / 2)) - CHUNK_SIZE;
	put_image_to_image(&window->img, pos, &(sprite->sprite_img)[0]);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->img.mlx_img, 0, 0);
}

int	display_end_screen(t_game *game, int is_end)
{
	if (is_end == 0)
		return (0);
	if (is_end == 1)
		display_win_screen(game, game->gameplay, game->window);
	else if (is_end == 2)
		display_lose_screen(game, game->gameplay, game->window);
	return (1);
}
