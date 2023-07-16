/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:18:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 21:56:14 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Create the chunk positions of the map.
 * 
 * @param game game struct, used to exit the program if a malloc fail.
 * @param chunk_pos chunk positions to create.
 * @param size size of the map on the x (width) and y (height) axis.
 * @param nb number of chunk in the map.
 */
static void	create_chunk_positions(t_game *game, t_vector_2 **chunk_pos,
	t_vector_2 size, int nb)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(*chunk_pos) = ft_calloc(sizeof(t_vector_2), nb);
	if (!*chunk_pos)
		exit_game(*game, "Error of malloc.\n");
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

/**
 * @brief Initialize display variables of the text_box struct.
 * 
 * @param game game struct, used to get the level and window struct.
 * @param text_box t_text_box struct to initialize.
 * @param background background sprite of the text_box.
 * @param sprite_face sprite of the face of the text_box.
 */
static void	init_text_box_display_variables(t_game *game, t_text_box *text_box,
	t_sprite *background, t_sprite *sprite_face)
{
	text_box->pos_display_background = (t_vector_2){20,
		WINDOW_HEIGHT - 50 - background->sprite_img->size.y};
	text_box->margin_size.x = 20;
	text_box->margin_size.y = 30;
	text_box->pos_display_face.x = text_box->pos_display_background.x
		+ text_box->margin_size.x;
	text_box->pos_display_face.y = text_box->pos_display_background.y
		+ text_box->margin_size.y;
	text_box->pos_display_text = text_box->pos_display_face;
	text_box->pos_display_text.x += sprite_face->sprite_img->size.x;
	text_box->size_one_alphabet = game->assets->alphabet->sprite_img->size.x;
	text_box->characters_max.x = (background->sprite_img->size.x
			- text_box->pos_display_text.x) / text_box->size_one_alphabet;
	text_box->characters_max.y = (background->sprite_img->size.y
			- (text_box->margin_size.y * 2))
		/ (text_box->size_one_alphabet + 10);
	text_box->characters_max_one_box = text_box->characters_max.x
		* text_box->characters_max.y;
}

/**
 * @brief initialize a text_box struct.
 * 
 * @param game game struct, used to get the level struct.
 * @param window window struct, used to get the map_sprites.
 * @param gameplay gameplay struct, used to get the player struct.
 * @param text_box text_box struct to initialize.
 */
void	init_one_text_box(t_game *game, t_gameplay *gameplay,
	t_text_box *text_box, int talking_character)
{
	t_sprite	*background;
	t_sprite	*sprite_face;

	// not commented
	background = game->assets->background_text;
	sprite_face = game->window->map_sprites[game->level->nb_cases
		+ gameplay->player->player_character];
	init_text_box_display_variables(game, text_box, background, sprite_face);
	text_box->is_display = false;
	text_box->read_all = false;
	text_box->page_number = 0;
	text_box->page_in = 0;
	text_box->talking_character = talking_character;
	text_box->text = NULL;
	text_box->text_pages = NULL;
}

/**
 * @brief initialize the small variables of the gameplay struct.
 * 
 * @param game game struct, used to get the level struct.
 * @param gameplay gameplay struct to initialize.
 */
static void	init_gameplay_small_variables(t_game *game, t_gameplay *gameplay)
{
	gameplay->is_pause = false;
	gameplay->is_stop = false;
	gameplay->is_display_plus_one = false;
	gameplay->is_title_screen = false;
	gameplay->is_start = false;
	gameplay->is_end = 0;
	gameplay->victory_text_status = 0;
	gameplay->tutorial_status = 0;
	gameplay->menu_status = 0;
	gameplay->fps = 0;
	gameplay->delta_time = 0;
	gameplay->nb_collect_get = 0;
	gameplay->nb_collect_remain = game->level->nb_collect;
	gameplay->nb_move = 0;
}

/**
 * @brief initialize the gameplay struct.
 * 
 * @param game game struct, used to get the level struct
 * and exit the program if a malloc fail.
 * @param available_character array of available character.
 * @param chosen_character first character chosen by the player,
 * and will be the character the player will start with
 * between the available ones.
 */
void	init_gameplay(t_game *game, int *available_character,
			int chosen_character)
{
	t_gameplay	*gameplay;

	gameplay = ft_calloc(sizeof(t_gameplay), 1);
	if (!gameplay)
		exit_game(*game, "Error of malloc.\n");
	game->gameplay = gameplay;
	init_gameplay_small_variables(game, gameplay);
	gameplay->available_character[0] = available_character[0];
	gameplay->available_character[1] = available_character[1];
	gameplay->available_character[2] = available_character[2];
	gameplay->available_character[3] = available_character[3];
	gameplay->chosen_character = chosen_character;
	create_chunk_positions(game, &gameplay->chunks_pos, game->level->map_vector,
		game->level->nb_cases);
	gameplay->map_start_state = ft_strdup(game->level->map);
	init_player(game, gameplay->player, chosen_character);
	init_guards(game, gameplay->guards);
	gameplay->dialogue = NULL;
	init_all_texts_of_the_game(game, gameplay);
	init_collectible(game, gameplay, gameplay->collectible,
		gameplay->collectible_code);
	// printf("pos : %d\n", gameplay->collectible[0].pos);
	gameplay->personage_animation
		= init_avatar_animation(game, game->assets);
	put_unavailable_character_on_map(game, gameplay);
	if (IS_DEBUG)
		debug_chunk_pos(game);
}
