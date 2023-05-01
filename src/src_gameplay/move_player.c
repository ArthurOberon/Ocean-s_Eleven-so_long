/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:30:47 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 19:31:11 by aoberon          ###   ########.fr       */
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

void	check_move_player(t_game *game, t_player *player)
{
	t_f_vector_2	move;

	move.x = 0;
	move.y = 0;
	calculate_ideal_move(&move, player->dir_player,
		game->gameplay->delta_time);
	limit_move_at_chunk_size(&move);
	check_collider(&move, player, game->level->map, game->level->map_vector.x);
	player->player_f_pos.x += move.x;
	player->player_f_pos.y += move.y;
}
