/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:33:16 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 23:07:08 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Check if a one of the chunks of the t_collider struct is in a wall.
 * 
 * @param map map in a string.
 * @param chunks chunks struct, to check.
 * @return int index of the chunk that is in a wall, -1 if none.
 */
int	check_wall_collider(char *map, t_collider chunks)
{
	if (map[chunks.n_w] == '1' || map[chunks.n_w] == '2')
		return (chunks.n_w);
	if (map[chunks.n_e] == '1' || map[chunks.n_e] == '2')
		return (chunks.n_e);
	if (map[chunks.s_w] == '1' || map[chunks.s_w] == '2')
		return (chunks.s_w);
	if (map[chunks.s_e] == '1' || map[chunks.s_e] == '2')
		return (chunks.s_e);
	return (-1);
}

/**
 * @brief Get the collider struct (4 corners chunks) of the player
 * with a hypothetical move.
 * 
 * @param move movement of the player, used to get the hypothetical position.
 * @param player player struct, used to get player position and size.
 * @param x_max size max of the map in x (width).
 * @return t_collider collider struct,
 * containing the 4 corners chunks of the hypothetical player position.
 */
t_collider	get_collider_on_move(t_f_vector_2 *move, t_player *player,
	int x_max)
{
	t_f_vector_2	hypothetical_pos;
	t_collider		chunks;

	hypothetical_pos.x = player->player_f_pos.x + move->x;
	hypothetical_pos.y = player->player_f_pos.y + move->y;
	chunks.n_w = pos_to_chunk((int)hypothetical_pos.x,
			(int)hypothetical_pos.y, x_max);
	chunks.n_e = pos_to_chunk((int)hypothetical_pos.x + player->size.x,
			(int)hypothetical_pos.y, x_max);
	chunks.s_w = pos_to_chunk((int)hypothetical_pos.x,
			(int)hypothetical_pos.y + player->size.y, x_max);
	chunks.s_e = pos_to_chunk((int)hypothetical_pos.x + player->size.x,
			(int)hypothetical_pos.y + player->size.y, x_max);
	return (chunks);
}

/**
 * @brief Get the collider struct (4 corners chunks) of the player.
 * 
 * @param player player struct, used to get the player position.
 * @param x_max size max of the map in x (width).
 * @return t_collider collider struct,
 * containing the 4 corners chunks of the player.
 */
static t_collider	get_collider(t_player *player, int x_max)
{
	t_collider		chunks;

	chunks.n_w = pos_to_chunk(player->player_f_pos.x,
			player->player_f_pos.y, x_max);
	chunks.n_e = pos_to_chunk(player->player_f_pos.x + player->size.x,
			player->player_f_pos.y, x_max);
	chunks.s_w = pos_to_chunk(player->player_f_pos.x,
			player->player_f_pos.y + player->size.y, x_max);
	chunks.s_e = pos_to_chunk(player->player_f_pos.x + player->size.x,
			player->player_f_pos.y + player->size.y, x_max);
	return (chunks);
}

/**
 * @brief Check if the player position (in chunk and vector) is touching,
 * a collectible, a character, the exit, or a guard.
 * 
 * @param game game struct, used to get the level struct.
 * @param player player struct, used to get the player position.
 * @param guards guards struct, used to get the guards position.
 */
void	check_collider(t_game *game, t_player *player, t_guard *guards)
{
	int			x_max;
	t_collider	chunks;

	x_max = game->level->map_vector.x;
	chunks = get_collider(player, x_max);
	check_tile(game, game->level->map[chunks.n_w], chunks.n_w);
	check_tile(game, game->level->map[chunks.n_e], chunks.n_e);
	check_tile(game, game->level->map[chunks.s_w], chunks.s_w);
	check_tile(game, game->level->map[chunks.s_e], chunks.s_e);
	check_collider_positions(game, player, guards);
}
