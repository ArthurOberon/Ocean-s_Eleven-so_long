/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:25:07 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 13:49:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player_on_x(t_game *game, t_player *player, t_f_vector_2 *move)
{
	int				collider_chunk;
	t_collider		chunks;
	t_vector_2		collider;

	get_move_player(player, move,
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

static void	move_player_on_y(t_game *game, t_player *player, t_f_vector_2 *move)
{
	int				collider_chunk;
	t_collider		chunks;
	t_vector_2		collider;

	get_move_player(player, move,
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

void	move_player(t_game *game, t_player *player)
{
	int				chunk_before;
	t_f_vector_2	move;

	chunk_before = pos_to_chunk(player->player_pos.x, player->player_pos.y,
			game->level->map_vector.x);
	if (player->player_dir.x == 0 && player->player_dir.y == 0)
		return ;
	// mlx_clear_window(game->window->mlx_ptr, game->window->win_ptr);
	move.x = 0;
	move.y = 0;
	move_player_on_x(game, player, &move);
	move_player_on_y(game, player, &move);
	player->player_look_dir.x = 0;
	player->player_look_dir.y = 0;
	if (player->player_dir.x != 0)
		player->player_look_dir.x = -1 + (2 * (player->player_dir.x > 0));
	if (player->player_dir.y != 0)
		player->player_look_dir.y = -1 + (2 * (player->player_dir.y > 0));
	set_player_pos(player, move);
	if (chunk_before != pos_to_chunk(player->player_pos.x, player->player_pos.y,
			game->level->map_vector.x))
		game->gameplay->nb_move++;
}
