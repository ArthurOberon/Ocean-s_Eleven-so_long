/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_ui_boxs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:43:35 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 09:20:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief display the box of the number of collectibles the player has collected,
 * and set somes of the variables for the display of the number of collectibles.
 * 
 * @param game game struct, used to get the window and level structs.
 * @param sprite_box sprite struct, used to get the sprite of the box.
 * @param start_pos_display position to display the box.
 * @param size_letter size of a letter.
 */
static void	display_small_box_collectible(t_game *game, t_sprite **sprite_box,
	t_vector_2 *start_pos_display, int *size_letter)
{
	(*sprite_box) = game->assets->box;
	*start_pos_display = (t_vector_2){WINDOW_WIDTH
		- ((*sprite_box)->sprite_img->size.x + 10),
		WINDOW_HEIGHT - CHUNK_SIZE - 10};
	*size_letter = game->assets->alphabet->sprite_img->size.x;
	put_image_to_image(&game->window->img, *start_pos_display,
		&((*sprite_box)->sprite_img)[(*sprite_box)->frame]);
}

/**
 * @brief display the number of collectibles the player has collected
 * in a box on the bottom right of the screen.
 * 
 * @param game game struct, used to get the window, gameplay and level structs.
 * @param gameplay gameplay struct, used to get the number of collectibles.
 */
static void	display_number_collectibles_box(t_game *game, t_gameplay *gameplay)
{
	int			size_letter;
	t_vector_2	start_pos_display;
	t_vector_2	pos_display;
	t_sprite	*sprite_box;
	char		str_itoa[10];

	sprite_box = NULL;
	display_small_box_collectible(game, &sprite_box, &start_pos_display,
		&size_letter);
	pos_display.x = start_pos_display.x + sprite_box->sprite_img->size.x / 2
		- size_letter / 2;
	pos_display.y = start_pos_display.y + sprite_box->sprite_img->size.y / 2
		- size_letter * 2;
	pos_display.x -= (size_letter) * (ft_nbrlen(gameplay->nb_collect_get));
	ft_itoa(gameplay->nb_collect_get, str_itoa);
	display_one_str(game, pos_display, str_itoa, size_letter);
	pos_display.x = start_pos_display.x + sprite_box->sprite_img->size.x / 2
		- size_letter / 2;
	pos_display.y += size_letter * 1;
	display_one_str(game, pos_display, "/", size_letter);
	pos_display.x += size_letter;
	pos_display.y += size_letter;
	ft_itoa(game->level->nb_collect, str_itoa);
	display_one_str(game, pos_display, str_itoa, size_letter);
}

/**
 * @brief display the number of moves the player has done
 * in a box on the bottom right of the screen.
 * 
 * @param game game struct, used to get level and window structs.
 * @param window window struct, used to display on.
 * @param gameplay gameplay struct, used to get the number of moves.
 */
static void	display_number_moves_box(t_game *game, t_window *window,
	t_gameplay *gameplay)
{
	int			size_letter;
	t_vector_2	start_pos_display;
	t_vector_2	pos_display;
	t_sprite	*sprite_box;
	char		str_itoa[10];

	sprite_box = game->assets->box;
	start_pos_display = (t_vector_2){WINDOW_WIDTH
		- ((sprite_box->sprite_img->size.x * 2) + 20),
		WINDOW_HEIGHT - CHUNK_SIZE - 10};
	size_letter = game->assets->alphabet->sprite_img->size.x;
	put_image_to_image(&window->img, start_pos_display,
		&(sprite_box->sprite_img)[sprite_box->frame]);
	pos_display.x = start_pos_display.x + sprite_box->sprite_img->size.x / 2
		- size_letter / 2;
	pos_display.y = start_pos_display.y + sprite_box->sprite_img->size.x / 3
		- size_letter / 2;
	pos_display.x -= (size_letter / 2) * (ft_nbrlen(gameplay->nb_move) - 1);
	ft_itoa(gameplay->nb_move, str_itoa);
	display_one_str(game, pos_display, str_itoa, size_letter);
	pos_display.x = start_pos_display.x + size_letter * 1.5;
	pos_display.y = start_pos_display.y + sprite_box->sprite_img->size.y / 2;
	display_one_str(game, pos_display, "moves", size_letter);
}

/**
 * @brief Display the boxs of the UI,
 * i.e. the number of moves and the number of collectibles.
 * 
 * @param game game struct, used to get all the info of the game.
 * @param window window struct, used to display on.
 * @param gameplay gameplay struct,
 * used to get the number of moves and collectibles.
 */
void	display_ui_boxs(t_game *game, t_window *window, t_gameplay *gameplay)
{
	display_number_moves_box(game, window, gameplay);
	display_number_collectibles_box(game, gameplay);
}
