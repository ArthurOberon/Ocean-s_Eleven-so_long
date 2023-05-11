/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_guard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:27:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 16:17:32 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// move_guard_utils.c

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
		move->x = (double)guard->guard_dir.x * SPEED_GUARD * delta_time;
		if (move->x > CHUNK_SIZE || move->x < -CHUNK_SIZE)
			move->x = (CHUNK_SIZE - 1) * guard->guard_dir.x;
	}
	if (axe.y == 1)
	{
		move->y = (double)guard->guard_dir.y * SPEED_GUARD * delta_time;
		if (move->y > CHUNK_SIZE || move->y < -CHUNK_SIZE)
			move->y = (CHUNK_SIZE - 1) * guard->guard_dir.y;
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

// && player->iframes -> not good !
// ADD t_vector_2 axe !
// void	reached_player(t_player *player, t_guard *guard, t_f_vector_2 *move)
// {
// 	if (guard->guard_dir.x == -1 && guard->guard_pos.x > player->player_pos.x
// 		&& player->iframes)
// 	{
// 		move->x = (player->player_pos.x + player->size.x) - guard->guard_pos.x;
// 	}
// 	if (guard->guard_dir.x == 1 && guard->guard_pos.x < player->player_pos.x
// 		&& player->iframes)
// 	{
// 		move->x = player->player_pos.x
// 			- (guard->guard_pos.x + player->size.x) - 1;
// 	}
// 	if (guard->guard_dir.y == -1 && guard->guard_pos.y > player->player_pos.y
// 		&& player->iframes)
// 	{
// 		move->y = (player->player_pos.y + player->size.y) - guard->guard_pos.y;
// 	}
// 	if (guard->guard_dir.y == 1 && guard->guard_pos.y < player->player_pos.y
// 		&& player->iframes)
// 	{
// 		move->y = player->player_pos.y
// 			- (guard->guard_pos.y + player->size.y) - 1;
// 	}
// }

// move_guard.c

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
	// reached_player(game->gameplay->player, guard, move);
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
	// reached_player(game->gameplay->player, guard, move);
}

void	move_guard(t_game *game, t_guard *guard)
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
	// if (guard->guard_dir.x != 0 && guard->guard_dir.y != 0)
	// {
	// 	if (rand() % 101 > 50) // replace by biggest between player.x -guard.x & player.y - guard.x
	// 		guard->guard_look_dir.x = -1 + (2 * (guard->guard_dir.x > 0));
	// 	else
	// 		guard->guard_look_dir.y = -1 + (2 * (guard->guard_dir.y > 0));
	// }
	// else
	// {
		if (guard->guard_dir.x != 0)
			guard->guard_look_dir.x = -1 + (2 * (guard->guard_dir.x > 0));
		if (guard->guard_dir.y != 0)
			guard->guard_look_dir.y = -1 + (2 * (guard->guard_dir.y > 0));
	// }
	set_guard_pos(game, guard, move);
}
