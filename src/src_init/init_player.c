/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:36:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 16:18:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player_positioning(t_game *game, t_player *player)
{
	player->player_dir.x = 0;
	player->player_dir.y = 0;
	player->player_chunk_pos.x = game->level->player_pos_tab
		% game->level->map_vector.x;
	player->player_chunk_pos.y = game->level->player_pos_tab
		/ game->level->map_vector.x;
	player->player_pos.x = player->player_chunk_pos.x * CHUNK_SIZE;
	player->player_pos.y = player->player_chunk_pos.y * CHUNK_SIZE;
	player->player_f_pos.x = player->player_pos.x;
	player->player_f_pos.y = player->player_pos.y;
	player->player_look_dir.x = 1;
	player->player_look_dir.y = 0;
}

static void	init_bomb(t_player *player)
{
	player->bomb.bomb_total = BOMB_NUMBER;
	player->bomb.bomb_plant = 0;
	player->bomb.bomb_chunk_pos = -1;
	player->bomb.bomb_pos.x = -1;
	player->bomb.bomb_pos.y = -1;
	player->bomb.time = (struct timeval){0, 0};
	player->bomb.last_time = (struct timeval){0, 0};
}

void	init_player(t_game *game, t_player *player)
{
	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		free_game(*game, "Error of malloc.\n");
	game->gameplay->player = player;
	player->size.x = (CHUNK_SIZE * RATIO_PLAYER_SIZE_X);
	player->size.y = (CHUNK_SIZE * (RATIO_PLAYER_SIZE_Y));
	init_player_positioning(game, player);
	init_bomb(player);
	player->player_character = e_main;
	player->hp = 100000;
	player->iframes = false;
	player->iframes_flashing = 0;
	player->iframes_start_time = (struct timeval){0, 0};
	player->iframes_time = (struct timeval){0, 0};
}
