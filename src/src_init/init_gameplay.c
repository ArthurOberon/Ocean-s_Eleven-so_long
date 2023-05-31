/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:18:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/31 23:36:51 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_chunk_positions(t_game *game, t_vector_2 **chunk_pos,
	t_vector_2 size, int nb)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(*chunk_pos) = ft_calloc(sizeof(t_vector_2), nb);
	if (!*chunk_pos)
		free_game(*game, "Error of malloc.\n");
	i = 0;
	y = 0;
	while (i < size.y)
	{
		j = 0;
		x = 0;
		while (j < size.x)
		{
			(*chunk_pos)[(i * size.x) + j] = (t_vector_2){x, y};
			j++;
			x += CHUNK_SIZE;
		}
		i++;
		y += CHUNK_SIZE;
	}
}

static void	init_text_box(t_game *game, t_window *window, t_gameplay *gameplay,
	t_text_box *text_box)
{
	t_sprite	*background;
	t_sprite	*sprite_face;

	background = window->map_sprites[game->level->nb_cases + e_background_text];
	sprite_face = game->window->map_sprites[game->level->nb_cases
		+ game->gameplay->player->player_character];
	text_box->is_display = false;
	text_box->read_all = false;
	text_box->pos_display_background = (t_vector_2){20,
		WINDOW_HEIGHT - 50 - background->sprite_img->size.y};
	text_box->margin_size.x = 20;
	text_box->margin_size.y = 30;
	text_box->pos_display_face.x = text_box->pos_display_background.x + text_box->margin_size.x;
	text_box->pos_display_face.y = text_box->pos_display_background.y + text_box->margin_size.y;
	text_box->pos_display_text = text_box->pos_display_face;
	text_box->pos_display_text.x += sprite_face->sprite_img->size.x;
	text_box->size_one_alphabet = window->map_sprites[game->level->nb_cases
		+ e_alphabet]->sprite_img->size.x;
	text_box->characters_max.x = (background->sprite_img->size.x
			- text_box->pos_display_text.x) / text_box->size_one_alphabet;
	text_box->characters_max.y = (background->sprite_img->size.y
			- (text_box->margin_size.y * 2))
		/ (text_box->size_one_alphabet + 10);
	text_box->characters_max_one_box = text_box->characters_max.x
		* text_box->characters_max.y;
	text_box->page_number = 0;
	text_box->page_in = 0;
	text_box->talking_character = gameplay->player->player_character;
	text_box->text = NULL;
	text_box->text_pages = NULL;
}

static void	init_texts(t_game *game, t_gameplay *gameplay)
{
	int		i;
	t_text	*texts;

	texts = ft_calloc(sizeof(t_text), e_total_text_number);
	if (!texts)
		free_game(*game, "Error of malloc.\n");
	gameplay->texts = texts;
	texts[e_text_start].text = "let's get thoses collectibles !";
	texts[e_text_remain_one_collectible].text = "one more to go !";
	texts[e_text_remain_zero_collectible].text = "perfect ! now let's go to the safe";
	texts[e_text_take_danny].text = "abcdefghijqlmnopqrstuvwxyz  !\"#$%&'()*+,-./0123456789:;<=?>";
	i = 0;
	while (i < e_total_text_number)
	{
		texts[i].has_been_display = false;
		i++;
	}
}

void	init_gameplay(t_game *game, int *available_character,
			int chosen_character)
{
	t_gameplay	*gameplay;

	gameplay = ft_calloc(sizeof(t_gameplay), 1);
	if (!gameplay)
		free_game(*game, "Error of malloc\n");
	game->gameplay = gameplay;
	gameplay->is_pause = false;
	gameplay->is_stop = false;
	gameplay->display_plus_one = false;
	gameplay->available_character[0] = available_character[0];
	gameplay->available_character[1] = available_character[1];
	gameplay->available_character[2] = available_character[2];
	gameplay->available_character[3] = available_character[3];
	gameplay->chosen_character = chosen_character;
	gameplay->fps = 0;
	gameplay->delta_time = 0;
	gameplay->nb_collect_get = 0;
	gameplay->nb_collect_remain = game->level->nb_collect;
	gameplay->nb_move = 0;
	get_chunk_positions(game, &gameplay->chunks_pos, game->level->map_vector,
		game->level->nb_cases);
	gameplay->map_start_state = ft_strdup(game->level->map);
	init_player(game, gameplay->player, chosen_character);
	init_guards(game, gameplay->guards);
	init_text_box(game, game->window, gameplay, &gameplay->text_box);
	init_texts(game, gameplay);
	if (IS_DEBUG)
		debug_chunk_pos(game);
}
