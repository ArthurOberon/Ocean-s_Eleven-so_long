/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:01:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 19:34:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_collider_up(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, char *map, int x_max)
{
	char	tile;

	tile = get_tile(hypothetical_pos.x / CHUNK_SIZE,
			hypothetical_pos.y / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->y = move->y - double_modulo(move->y, CHUNK_SIZE);
	}
	tile = get_tile((hypothetical_pos.x + PLAYER_SIZE) / CHUNK_SIZE,
			hypothetical_pos.y / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->y = move->y - double_modulo(move->y, CHUNK_SIZE);
	}
}

static void	check_collider_down(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, char *map, int x_max)
{
	char	tile;

	tile = get_tile(hypothetical_pos.x / CHUNK_SIZE,
			(hypothetical_pos.y + PLAYER_SIZE) / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->y = move->y - double_modulo(move->y, CHUNK_SIZE);
	}
	tile = get_tile((hypothetical_pos.x + PLAYER_SIZE) / CHUNK_SIZE,
			(hypothetical_pos.y + PLAYER_SIZE) / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->y = move->y - double_modulo(move->y, CHUNK_SIZE);
	}
}

static void	check_collider_left(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, char *map, int x_max)
{
	char	tile;

	tile = get_tile(hypothetical_pos.x / CHUNK_SIZE,
			hypothetical_pos.y / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->x = move->x - double_modulo(move->x, CHUNK_SIZE);
	}
	tile = get_tile(hypothetical_pos.x / CHUNK_SIZE,
			(hypothetical_pos.y + PLAYER_SIZE) / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->x = move->x - double_modulo(move->x, CHUNK_SIZE);
	}
}

static void	check_collider_right(t_f_vector_2 *move,
	t_f_vector_2 hypothetical_pos, char *map, int x_max)
{
	char	tile;

	tile = get_tile((hypothetical_pos.x + PLAYER_SIZE) / CHUNK_SIZE,
			hypothetical_pos.y / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->x = move->x - double_modulo(move->x, CHUNK_SIZE);
	}
	tile = get_tile((hypothetical_pos.x + PLAYER_SIZE) / CHUNK_SIZE,
			(hypothetical_pos.y + PLAYER_SIZE) / CHUNK_SIZE, map, x_max);
	if (tile == '1')
	{
		move->x = move->x - double_modulo(move->x, CHUNK_SIZE);
	}
}

void	check_collider(t_f_vector_2 *move, t_player *player,
	char *map, int x_max)
{
	t_f_vector_2	hypothetical_pos;

	hypothetical_pos.x = player->player_f_pos.x + move->x;
	hypothetical_pos.y = player->player_f_pos.y + move->y;
	printf("move : x : [%f] y: [%f]\n", move->x, move->y);
	if (move->y < 0)
	{
		check_collider_up(move, hypothetical_pos, map, x_max);
	}
	if (move->y > 0)
	{
		check_collider_down(move, hypothetical_pos, map, x_max);
	}
	if (move->x < 0)
	{
		check_collider_left(move, hypothetical_pos, map, x_max);
	}
	if (move->x > 0)
	{
		check_collider_right(move, hypothetical_pos, map, x_max);
	}
	printf("move : x : [%f] y: [%f]\n\n", move->x, move->y);
}
