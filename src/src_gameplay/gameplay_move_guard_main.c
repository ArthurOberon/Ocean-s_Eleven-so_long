/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_move_guard_main.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:27:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 17:52:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Move the guard on the x (width) axis.
 * 
 * @param game game struct, used to get the level struct.
 * @param guard guard struct, used to move.
 * @param move vector of the movement of the guard.
 */
static void	move_guard_on_x(t_game *game, t_guard *guard, t_f_vector_2 *move)
{
	int			collider_chunk;
	t_collider	chunks;
	t_vector_2	collider;

	set_move_guard(guard, move, game->gameplay->delta_time, (t_vector_2){1, 0});
	chunks = get_collider_guard_on_move(move, guard, game->level->map_vector.x);
	collider_chunk = check_wall_collider(game->level->map, chunks);
	if (collider_chunk != -1)
	{
		collider = chunk_to_pixel_pos(collider_chunk,
				game->level->map_vector.x);
		restrict_move_guard(move, guard, collider, (t_vector_2){1, 0});
	}
}

/**
 * @brief Move the guard on the y (height) axis.
 * 
 * @param game game struct, used to get the level struct.
 * @param guard guard struct, used to move.
 * @param move vector of the movement of the guard.
 */
static void	move_guard_on_y(t_game *game, t_guard *guard, t_f_vector_2 *move)
{
	int			collider_chunk;
	t_collider	chunks;
	t_vector_2	collider;

	set_move_guard(guard, move, game->gameplay->delta_time, (t_vector_2){0, 1});
	chunks = get_collider_guard_on_move(move, guard, game->level->map_vector.x);
	collider_chunk = check_wall_collider(game->level->map, chunks);
	if (collider_chunk != -1)
	{
		collider = chunk_to_pixel_pos(collider_chunk,
				game->level->map_vector.x);
		restrict_move_guard(move, guard, collider, (t_vector_2){0, 1});
	}
}

/**
 * @brief Move the guard.
 * 
 * @param game game struct, used te get the level struct.
 * @param guard guard struct to move.
 * @param player player struct, used to get the player position.
 */
void	move_guard(t_game *game, t_guard *guard, t_player *player)
{
	t_f_vector_2	move;
	t_sprite		*sprite;

	sprite = game->window->map_sprites[game->level->nb_cases
		+ e_guards];
	move.x = 0;
	move.y = 0;
	move_guard_on_x(game, guard, &move);
	move_guard_on_y(game, guard, &move);
	set_guard_look_dir(guard, player, move);
	set_guard_pos(game, guard, move);
}
