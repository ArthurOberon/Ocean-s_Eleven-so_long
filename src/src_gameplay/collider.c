/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:01:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 22:46:05 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_collider_up(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, t_game *game)
{
	int				x_max;
	int				pos_tile;
	char			tile;
	char			*map;
	t_vector_2		player_size;

	x_max = game->level->map_vector.x;
	player_size = game->gameplay->player->size;
	map = game->level->map;
	get_tile_number(&pos_tile, hypothetical_pos.x / CHUNK_SIZE,
		hypothetical_pos.y / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->y, game);
	get_tile_number(&pos_tile,
		(hypothetical_pos.x + player_size.x) / CHUNK_SIZE,
		hypothetical_pos.y / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->y, game);
}

static void	check_collider_down(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, t_game *game)
{
	int				x_max;
	int				pos_tile;
	char			tile;
	char			*map;
	t_vector_2		player_size;

	x_max = game->level->map_vector.x;
	player_size = game->gameplay->player->size;
	map = game->level->map;
	get_tile_number(&pos_tile, hypothetical_pos.x / CHUNK_SIZE,
		(hypothetical_pos.y + player_size.y) / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->y, game);
	get_tile_number(&pos_tile,
		(hypothetical_pos.x + player_size.x) / CHUNK_SIZE,
		(hypothetical_pos.y + player_size.y) / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->y, game);
}

static void	check_collider_left(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, t_game *game)
{
	int				x_max;
	int				pos_tile;
	char			tile;
	char			*map;
	t_vector_2		player_size;

	x_max = game->level->map_vector.x;
	player_size = game->gameplay->player->size;
	map = game->level->map;
	get_tile_number(&pos_tile, hypothetical_pos.x / CHUNK_SIZE,
		hypothetical_pos.y / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->x, game);
	get_tile_number(&pos_tile, hypothetical_pos.x / CHUNK_SIZE,
		(hypothetical_pos.y + player_size.y) / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->x, game);
}

static void	check_collider_right(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, t_game *game)
{
	int				x_max;
	int				pos_tile;
	char			tile;
	char			*map;
	t_vector_2		player_size;

	x_max = game->level->map_vector.x;
	player_size = game->gameplay->player->size;
	map = game->level->map;
	get_tile_number(&pos_tile,
		(hypothetical_pos.x + player_size.x) / CHUNK_SIZE,
		hypothetical_pos.y / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->x, game);
	get_tile_number(&pos_tile,
		(hypothetical_pos.x + player_size.x) / CHUNK_SIZE,
		(hypothetical_pos.y + player_size.y) / CHUNK_SIZE, x_max);
	tile = map[pos_tile];
	check_tile(tile, pos_tile, &move->x, game);
}

void	check_collider(t_f_vector_2 *move, t_game *game, t_player *player)
{
	t_f_vector_2	hypothetical_pos;

	hypothetical_pos.x = player->player_f_pos.x;
	hypothetical_pos.y = player->player_f_pos.y + move->y;
	if (move->y < 0)
	{
		check_collider_up(move, hypothetical_pos, game);
	}
	if (move->y > 0)
	{
		check_collider_down(move, hypothetical_pos, game);
	}
	hypothetical_pos.x = player->player_f_pos.x + move->x;
	hypothetical_pos.y = player->player_f_pos.y + move->y;
	if (move->x < 0)
	{
		check_collider_left(move, hypothetical_pos, game);
	}
	if (move->x > 0)
	{
		check_collider_right(move, hypothetical_pos, game);
	}
}
// printf("move : x : [%f] y: [%f]\n\n", move->x, move->y);
// printf("hypo : x : [%f] y : [%f]\n", hypothetical_pos.x, hypothetical_pos.y);

// move->x = move->x - double_modulo(move->x, CHUNK_SIZE);
// move->y = move->y - double_modulo(move->y, CHUNK_SIZE);
