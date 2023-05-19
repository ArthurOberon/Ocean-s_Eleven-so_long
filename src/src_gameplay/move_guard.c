/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_guard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:27:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/19 14:09:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_guard_on_x(t_game *game, t_guard *guard, t_f_vector_2 *move)
{
	int			collider_chunk;
	t_collider	chunks;
	t_vector_2	collider;

	get_move_guard(guard, move, game->gameplay->delta_time, (t_vector_2){1, 0});
	chunks = get_collider_guard_on_move(move, guard, game->level->map_vector.x);
	collider_chunk = check_wall_collider(game->level->map, chunks);
	if (collider_chunk != -1)
	{
		collider = chunk_to_pixel_pos(collider_chunk,
				game->level->map_vector.x);
		restrict_move_guard(move, guard, collider, (t_vector_2){1, 0});
	}
}

static void	move_guard_on_y(t_game *game, t_guard *guard, t_f_vector_2 *move)
{
	int			collider_chunk;
	t_collider	chunks;
	t_vector_2	collider;

	get_move_guard(guard, move, game->gameplay->delta_time, (t_vector_2){0, 1});
	chunks = get_collider_guard_on_move(move, guard, game->level->map_vector.x);
	collider_chunk = check_wall_collider(game->level->map, chunks);
	if (collider_chunk != -1)
	{
		collider = chunk_to_pixel_pos(collider_chunk,
				game->level->map_vector.x);
		restrict_move_guard(move, guard, collider, (t_vector_2){0, 1});
	}
}

void	move_guard(t_game *game, t_guard *guard, t_player *player)
{
	t_f_vector_2	move;

	if (guard->guard_pos.x == 0 && guard->guard_pos.y == 0)
		return ;
	move.x = 0;
	move.y = 0;
	move_guard_on_x(game, guard, &move);
	move_guard_on_y(game, guard, &move);
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
	set_guard_pos(game, guard, move);
}
