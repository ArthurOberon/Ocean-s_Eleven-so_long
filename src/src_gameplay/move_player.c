/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:25:07 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 00:21:32 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Move the player on the x (width) axis.
 * 
 * @param game game struct, used to get the level struct.
 * @param player player struct, used to move.
 * @param move vector of the movement of the player.
 */
static void	move_player_on_x(t_game *game, t_player *player, t_f_vector_2 *move)
{
	int				collider_chunk;
	t_collider		chunks;
	t_vector_2		collider;

	set_move_player(player, move,
		game->gameplay->delta_time, (t_vector_2){1, 0});
	chunks = get_collider_on_move(move, player, game->level->map_vector.x);
	collider_chunk = check_wall_collider(game->level->map, chunks);
	if (collider_chunk != -1)
	{
		collider = chunk_to_pixel_pos(collider_chunk,
				game->level->map_vector.x);
		restrict_move(move, player, collider, (t_vector_2){1, 0});
	}
}

/**
 * @brief Move the player on the y (height) axis.
 * 
 * @param game game struct, used to get the level struct.
 * @param player player struct, used to move.
 * @param move vector of the movement of the player.
 */
static void	move_player_on_y(t_game *game, t_player *player, t_f_vector_2 *move)
{
	int				collider_chunk;
	t_collider		chunks;
	t_vector_2		collider;

	set_move_player(player, move,
		game->gameplay->delta_time, (t_vector_2){0, 1});
	chunks = get_collider_on_move(move, player, game->level->map_vector.x);
	collider_chunk = check_wall_collider(game->level->map, chunks);
	if (collider_chunk != -1)
	{
		collider = chunk_to_pixel_pos(collider_chunk,
				game->level->map_vector.x);
		restrict_move(move, player, collider, (t_vector_2){0, 1});
	}
}

/**
 * @brief Move the player.
 * 
 * @param game game struct, used te get the level and the window struct.
 * @param player player struct to move.
 */
void	move_player(t_game *game, t_player *player)
{
	int				chunk_before;
	t_f_vector_2	move;
	t_sprite		*sprite;

	sprite = game->window->map_sprites[game->level->nb_cases
		+ player->player_character];
	chunk_before = pos_to_chunk(player->player_pos.x, player->player_pos.y,
			game->level->map_vector.x);
	if (player->player_dir.x == 0 && player->player_dir.y == 0)
	{
		sprite->frame = 0;
		sprite->last_time = (struct timeval){0, 0};
		return ;
	}
	move.x = 0;
	move.y = 0;
	move_player_on_x(game, player, &move);
	move_player_on_y(game, player, &move);
	set_player_pos(player, move);
	set_player_look_dir(player);
	move_animation(player->player_look_dir, sprite);
	if (chunk_before != pos_to_chunk(player->player_pos.x, player->player_pos.y,
			game->level->map_vector.x))
		game->gameplay->nb_move++;
}
