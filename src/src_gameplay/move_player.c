/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:30:47 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/02 13:49:28 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	calculate_ideal_move(t_f_vector_2 *move,
	t_vector_2 dir_player, double delta_time)
{
	if (dir_player.y == -1)
		move->y -= SPEED * delta_time;
	if (dir_player.y == 1)
		move->y += SPEED * delta_time;
	if (dir_player.x == -1)
		move->x -= SPEED * delta_time;
	if (dir_player.x == 1)
		move->x += SPEED * delta_time;
}

static void	limit_move_at_chunk_size(t_f_vector_2 *move)
{
	if (move->y > CHUNK_SIZE)
		move->y = CHUNK_SIZE - 1;
	if (move->y < -CHUNK_SIZE)
		move->y = -(CHUNK_SIZE - 1);
	if (move->x > CHUNK_SIZE)
		move->x = CHUNK_SIZE - 1;
	if (move->x < -CHUNK_SIZE)
		move->x = (CHUNK_SIZE - 1);
}

static void	check_static_pos(t_game *game, t_player *player,
	char *map, int x_max)
{
	int				pos_tile;
	char			tile;
	t_vector_2		player_size;

	player_size = game->gameplay->player->size;
	get_tile_number(&pos_tile, player->player_f_pos.x / CHUNK_SIZE,
		player->player_f_pos.y / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, NULL, game);
	get_tile_number(&pos_tile,
		(player->player_f_pos.x + player_size.x) / CHUNK_SIZE,
		player->player_f_pos.y / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, NULL, game);
	get_tile_number(&pos_tile, player->player_f_pos.x / CHUNK_SIZE,
		(player->player_f_pos.y + player_size.y) / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, NULL, game);
	get_tile_number(&pos_tile,
		(player->player_f_pos.x + player_size.x) / CHUNK_SIZE,
		(player->player_f_pos.y + player_size.y) / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, NULL, game);
}

void	check_move_player(t_game *game, t_player *player)
{
	t_f_vector_2	move;

	move.x = 0;
	move.y = 0;
	calculate_ideal_move(&move, player->dir_player,
		game->gameplay->delta_time);
	limit_move_at_chunk_size(&move);
	if (move.x == 0 && move.y == 0)
		check_static_pos(game, player,
			game->level->map, game->level->map_vector.x);
	else
		check_collider(&move, game, player);
	player->player_f_pos.x += move.x;
	player->player_f_pos.y += move.y;
	player->player_pos.x = (int)player->player_f_pos.x;
	player->player_pos.y = (int)player->player_f_pos.y;
}
