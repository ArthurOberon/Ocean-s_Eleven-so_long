/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:34:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 00:28:50 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get the move player, based on the player direction.
 * 
 * @param player player struct, used to get player direction.
 * @param move movement of the player to set.
 * @param delta_time delta time, used to get a move depending on the time.
 * @param axe axe of the movement to set.
 */
void	set_move_player(t_player *player, t_f_vector_2 *move,
double delta_time, t_vector_2 axe)
{
	if (axe.x == 1)
	{
		move->x = (double)player->player_dir.x * SPEED * delta_time;
		if (move->x > CHUNK_SIZE || move->x < -CHUNK_SIZE)
			move->x = (CHUNK_SIZE - 1) * player->player_dir.x;
	}
	if (axe.y == 1)
	{
		move->y = (double)player->player_dir.y * SPEED * delta_time;
		if (move->y > CHUNK_SIZE || move->y < -CHUNK_SIZE)
			move->y = (CHUNK_SIZE - 1) * player->player_dir.y;
	}
}

/**
 * @brief Set the player look direction, based on the player direction.
 * 
 * @param player player struct, to set the look direction.
 */
void	set_player_look_dir(t_player *player)
{
	player->player_look_dir.x = 0;
	player->player_look_dir.y = 0;
	if (player->player_dir.x != 0)
		player->player_look_dir.x = -1 + (2 * (player->player_dir.x > 0));
	if (player->player_dir.y != 0)
		player->player_look_dir.y = -1 + (2 * (player->player_dir.y > 0));
}

/**
 * @brief Set the player position, based on the move.
 * 
 * @param player player struct, to move.
 * @param move vector of the movement of the player.
 */
void	set_player_pos(t_player *player, t_f_vector_2 move)
{
	player->player_f_pos.x += move.x;
	player->player_pos.x = (int)player->player_f_pos.x;
	player->player_f_pos.y += move.y;

	player->player_pos.y = (int)player->player_f_pos.y;
	player->player_chunk_pos.x = player->player_pos.x / CHUNK_SIZE;
	player->player_chunk_pos.y = player->player_pos.y / CHUNK_SIZE;
}

/**
 * @brief Restrict the movement of the player, based on the collider.
 * 
 * @param move movement of the player to restrict.
 * @param player player struct, used to get player position.
 * @param collider collider position, used to restrict the movement.
 * @param axe axe of the movement to restrict.
 */
void	restrict_move(t_f_vector_2 *move, t_player *player, t_vector_2 collider,
t_vector_2 axe)
{
	if (axe.x == 1)
	{
		if (move->x < 0)
		{
			move->x = (collider.x + CHUNK_SIZE) - player->player_pos.x;
		}
		else
		{
			move->x = collider.x - (player->player_pos.x + player->size.x) - 1;
		}
	}
	if (axe.y == 1)
	{
		if (move->y < 0)
		{
			move->y = (collider.y + CHUNK_SIZE) - player->player_pos.y;
		}
		else
		{
			move->y = collider.y - (player->player_pos.y + player->size.y) - 1;
		}
	}
}
