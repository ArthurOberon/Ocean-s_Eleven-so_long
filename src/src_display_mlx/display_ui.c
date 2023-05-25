/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:08:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/25 16:42:04 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_character(t_game *game, t_window *window,
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

static void	display_text(t_game *game, t_window *window,
	t_vector_2 pos_display, char *text)
{
	int	i;
	int	size_letter;

	i = 0;
	size_letter = game->window->map_sprites[game->level->nb_cases
		+ e_alphabet]->sprite_img->size.x;
	while (text[i])
	{
		display_character(game, window, pos_display, text[i]);
		pos_display.x += size_letter;
		i++;
	}
}

int	ft_nbrlen(long nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		return (1);
	else
		return (1 + ft_nbrlen(nb / 10));
}

static void	display_number_moves(t_game *game, t_window *window,
	t_gameplay *gameplay, t_sprite *sprite)
{
	t_vector_2	start_pos_display;
	t_vector_2	pos_display;
	int			size_letter;

	size_letter = game->window->map_sprites[game->level->nb_cases
		+ e_alphabet]->sprite_img->size.x;
	start_pos_display = (t_vector_2){WINDOW_WIDTH
		- (sprite->sprite_img->size.x * 2),
		WINDOW_HEIGHT - CHUNK_SIZE - 10};
	put_image_to_image(&window->img, start_pos_display,
		&(sprite->sprite_img)[sprite->frame]);
	pos_display.x = start_pos_display.x + sprite->sprite_img->size.x / 2
		- size_letter / 2;
	pos_display.y = start_pos_display.y + sprite->sprite_img->size.x / 3
		- size_letter / 2;
	pos_display.x -= (size_letter / 2) * (ft_nbrlen(gameplay->nb_move) - 1);
	display_text(game, window, pos_display, ft_itoa(gameplay->nb_move));
	pos_display.x = start_pos_display.x + size_letter * 1.5;
	pos_display.y = start_pos_display.y + sprite->sprite_img->size.y / 2;
	display_text(game, window, pos_display, "moves");
}

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
		window->map_sprites[game->level->nb_cases + e_heart]);
	display_character_selection(game, window, gameplay->player);
	display_number_moves(game, window, gameplay,
		window->map_sprites[game->level->nb_cases + e_box]);
}
