/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_guard_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:49:05 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 23:49:14 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	get_move_guard(t_guard *guard, t_f_vector_2 *move,
	double delta_time, t_vector_2 axe)
{
	if (axe.x == 1)
	{
		move->x = (double)guard->guard_f_dir.x * SPEED_GUARD * delta_time;
		if (move->x > CHUNK_SIZE || move->x < -CHUNK_SIZE)
			move->x = (CHUNK_SIZE - 1) * guard->guard_f_dir.x;
	}
	if (axe.y == 1)
	{
		move->y = (double)guard->guard_f_dir.y * SPEED_GUARD * delta_time;
		if (move->y > CHUNK_SIZE || move->y < -CHUNK_SIZE)
			move->y = (CHUNK_SIZE - 1) * guard->guard_f_dir.y;
	}
}

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
			move->x = collider.x - (guard->guard_pos.x + CHUNK_SIZE) - 1;
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
			move->y = collider.y - (guard->guard_pos.y + CHUNK_SIZE) - 1;
		}
	}
}
