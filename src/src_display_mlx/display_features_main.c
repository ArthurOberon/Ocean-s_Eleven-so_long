/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 20:56:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief display a +1 above the player when he collect a collectible.
 * 
 * @param game game struct, used to get the window and the map_sprites.
 * @param gameplay gameplay struct, used to know if we have to display the +1.
 * @param player player struct, used to get the player position.
 */
static void	is_display_plus_one_collectible(t_game *game, t_gameplay *gameplay,
	t_player *player)
{
	static struct timeval	start_time = {0, 0};
	struct timeval			time;
	double					delay;
	t_vector_2				pos_display;

	if (gameplay->is_display_plus_one == false)
		return ;
	pos_display.x = player->player_pos.x
		- game->camera->camera_f_pos.x - (CHUNK_SIZE / 5);
	pos_display.y = player->player_pos.y
		- game->camera->camera_f_pos.y - (CHUNK_SIZE / 5);
	display_one_str(game, pos_display, "+1",
		game->window->map_sprites[game->level->nb_cases + e_alphabet]
		->sprite_img->size.x);
	if (!start_time.tv_sec)
		gettimeofday(&start_time, NULL);
	gettimeofday(&time, NULL);
	delay = (((double)(time.tv_usec - start_time.tv_usec) / CLOCKS_PER_SEC)
			+ time.tv_sec - start_time.tv_sec);
	if (delay >= 2)
	{
		start_time = (struct timeval){0, 0};
		gameplay->is_display_plus_one = false;
	}
}

/**
 * @brief Display all the gameplay elements.
 * 
 * @param game game struct, used to get the level struct.
 * @param gameplay gameplay struct, used to get the elements to display.
 * @param window window struct, used to display the elements on.
 */
void	display_gameplay_features(t_game *game, t_gameplay *gameplay,
	t_window *window)
{
	if (gameplay->nb_collect_remain == 0)
		window->map_sprites[game->level->exit_pos] = game->assets->collect;
	display_guards(game, gameplay, window, gameplay->guards);
	display_bomb(gameplay->player, &gameplay->player->bomb, game, window);
	display_qte(game, &gameplay->player->qte, gameplay->player,
		gameplay->guards);
	is_display_plus_one_collectible(game, gameplay, gameplay->player);
	get_characters_on_map(game, window, gameplay);
	display_ui(game, window, gameplay);
	display_dialogue(game, game->gameplay->dialogue);
}
