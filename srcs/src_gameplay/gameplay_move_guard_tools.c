/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_guard_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:49:05 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 00:40:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get the collider guard on move, based on the move and the guard.
 * 
 * @param move movement of the guard.
 * @param guard guard struct, used to get guard position and size.
 * @param x_max x (width) max of the map.
 * @return t_collider collider of the guard on move.
 */
t_collider	get_collider_guard_on_move(t_f_vector_2 *move, t_guard *guard,
	int x_max)
{
	t_f_vector_2	hypothetical_pos;
	t_collider		chunks;

	hypothetical_pos.x = guard->guard_f_pos.x + move->x;
	hypothetical_pos.y = guard->guard_f_pos.y + move->y;
	chunks.n_w = pos_to_chunk((int)hypothetical_pos.x,
			(int)hypothetical_pos.y, x_max);
	chunks.n_e = pos_to_chunk((int)hypothetical_pos.x + guard->size.x,
			(int)hypothetical_pos.y, x_max);
	chunks.s_w = pos_to_chunk((int)hypothetical_pos.x,
			(int)hypothetical_pos.y + guard->size.x, x_max);
	chunks.s_e = pos_to_chunk((int)hypothetical_pos.x + guard->size.x,
			(int)hypothetical_pos.y + guard->size.y, x_max);
	return (chunks);
}

/**
 * @brief Set the move guard, based on the guard direction.
 * 
 * @param guard guard struct, used to get guard direction.
 * @param move movement of the guard to set.
 * @param delta_time time, used to get a move depending on the time.
 * @param axe axe of the movement to set.
 */
void	set_move_guard(t_guard *guard, t_f_vector_2 *move,
	double delta_time, t_vector_2 axe)
{
	if (axe.x == 1)
	{
		move->x = (double)guard->guard_f_dir.x * SPEED_GUARD * delta_time;
		if (move->x > CHUNK_SIZE || move->x < -CHUNK_SIZE)
			move->x = (CHUNK_SIZE - 1) * (int)guard->guard_f_dir.x;
	}
	if (axe.y == 1)
	{
		move->y = (double)guard->guard_f_dir.y * SPEED_GUARD * delta_time;
		if (move->y > CHUNK_SIZE || move->y < -CHUNK_SIZE)
			move->y = (CHUNK_SIZE - 1) * (int)guard->guard_f_dir.y;
	}
}

/**
 * @brief Set the player look direction, based on the player direction.
 * 
 * @param player player struct, to set the look direction.
 */

/**
 * @brief Set the guard look direction, based on the guard direction.
 * 
 * @param guard guard struct, to set the look direction.
 * @param player player struct, used to get the player chunk position.
 * @param move movement of the guard.
 */
void	set_guard_look_dir(t_guard *guard, t_player *player, t_f_vector_2 move)
{
	guard->guard_look_dir.x = 0;
	guard->guard_look_dir.y = 0;
	if ((int)((guard->guard_f_pos.x + move.x) / CHUNK_SIZE)
		== player->player_chunk_pos.x)
		guard->guard_look_dir.y = -1 + (2 * (guard->guard_f_dir.y > 0));
	else if ((int)((guard->guard_f_pos.y + move.y) / CHUNK_SIZE)
		== player->player_chunk_pos.y)
		guard->guard_look_dir.x = -1 + (2 * (guard->guard_f_dir.x > 0));
	else
	{
		if (guard->guard_f_dir.x != 0)
			guard->guard_look_dir.x = -1 + (2 * (guard->guard_f_dir.x > 0));
		if (guard->guard_f_dir.y != 0)
			guard->guard_look_dir.y = -1 + (2 * (guard->guard_f_dir.y > 0));
	}
}

/**
 * @brief Set the guard position, based on the move.
 * 
 * @param game game struct, to get the level.
 * @param guard guard struct, to move.
 * @param move vector of the movement of the guard.
 */
void	set_guard_pos(t_game *game, t_guard *guard, t_f_vector_2 move)
{
	guard->guard_f_pos.x += move.x;
	guard->guard_f_pos.y += move.y;
	guard->guard_pos.x = (int)guard->guard_f_pos.x;
	guard->guard_pos.y = (int)guard->guard_f_pos.y;
	guard->guard_pos_tab = pos_to_chunk(guard->guard_pos.x, guard->guard_pos.y,
			game->level->map_vector.x);
	guard->guard_chunk_pos.x = guard->guard_pos.x / CHUNK_SIZE;
	guard->guard_chunk_pos.y = guard->guard_pos.y / CHUNK_SIZE;
	set_guard_fov_direction(guard);
}

/**
 * @brief Restricts the movement of the guard, based on the collider.
 * 
 * @param move movement of the guard to restrict.
 * @param guard guard struct, used to get guard position.
 * @param collider collider position, used to restrict the movement.
 * @param axe axe of the movement to restrict.
 */
void	restrict_move_guard(t_f_vector_2 *move, t_guard *guard,
	t_vector_2 collider, t_vector_2 axe)
{
	if (axe.x == 1)
	{
		if (move->x < 0)
		{
			move->x = (collider.x + CHUNK_SIZE) - guard->guard_pos.x;
		}
		else
		{
			move->x = collider.x - (guard->guard_pos.x + guard->size.x) - 1;
		}
	}
	if (axe.y == 1)
	{
		if (move->y < 0)
		{
			move->y = (collider.y + CHUNK_SIZE) - guard->guard_pos.y;
		}
		else
		{
			move->y = collider.y - (guard->guard_pos.y + guard->size.y) - 1;
		}
	}
}
