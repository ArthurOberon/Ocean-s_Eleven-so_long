/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_small_features.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:37:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/25 17:46:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_one_str(t_game *game, t_vector_2 pos_display,
	char *text, int size_letter)
{
	int	i;

	i = 0;
	while (text[i])
	{
		display_character(game, game->window, pos_display, text[i]);
		pos_display.x += size_letter;
		i++;
	}
}

void	get_one_collectible(t_game *game)
{
	t_vector_2	pos_tmp;
	t_player	*player;

	game->gameplay->nb_collect_get += 1;
	game->gameplay->nb_collect_remain -= 1;
	player = game->gameplay->player;
	pos_tmp = player->player_pos;
	player->player_pos.x = player->player_pos.x - game->camera->camera_f_pos.x;
	player->player_pos.y = player->player_pos.y - game->camera->camera_f_pos.y;
	player->player_pos.x = player->player_pos.x - (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_X)) / 2;
	player->player_pos.y = player->player_pos.y - (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_Y)) / 2;
	// pos_tmp.x -= player->size.x;
	// pos_tmp.y -= player->size.y;
	printf("TEST\n");
	display_one_str(game, (t_vector_2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2},
		"+1", game->window->map_sprites[game->level->nb_cases + e_alphabet]->sprite_img->size.x);
	player->player_pos = pos_tmp;
}
