/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:34:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/26 20:11:02 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_move_player(t_player *player, t_f_vector_2 *move,
double delta_time, t_vector_2 axe)
{
	if (axe.x == 1)
	{
		move->x = (double)player->player_dir.x * SPEED * delta_time;
		if (move->x > CHUNK_SIZE || move->x < -CHUNK_SIZE)
			move->x = (CHUNK_SIZE - 1) * player->player_dir.x;
	}
	if (axe.y)
	{
		move->y = (double)player->player_dir.y * SPEED * delta_time;
		if (move->y > CHUNK_SIZE || move->y < -CHUNK_SIZE)
			move->y = (CHUNK_SIZE - 1) * player->player_dir.y;
	}
}

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

void	set_player_pos(t_player *player, t_f_vector_2 move)
{
	player->player_f_pos.x += move.x;
	player->player_f_pos.y += move.y;
	player->player_pos.x = (int)player->player_f_pos.x;
	player->player_pos.y = (int)player->player_f_pos.y;
	player->player_chunk_pos.x = player->player_pos.x / CHUNK_SIZE;
	player->player_chunk_pos.y = player->player_pos.y / CHUNK_SIZE;
}

void	set_player_look_dir(t_player *player)
{
	player->player_look_dir.x = 0;
	player->player_look_dir.y = 0;
	if (player->player_dir.x != 0)
		player->player_look_dir.x = -1 + (2 * (player->player_dir.x > 0));
	if (player->player_dir.y != 0)
		player->player_look_dir.y = -1 + (2 * (player->player_dir.y > 0));
}

void	move_animation(t_player *player, t_sprite *sprite)
{
	if (player->player_look_dir.x == -1)
		sprite->frame = 2;
	if (player->player_look_dir.x == 1)
		sprite->frame = 1;
	if (player->player_look_dir.y == -1)
		sprite->frame = 4;
	if (player->player_look_dir.y == 1)
		sprite->frame = 3;
}
