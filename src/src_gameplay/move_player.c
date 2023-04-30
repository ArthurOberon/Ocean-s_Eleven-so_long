/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:30:47 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/30 22:53:16 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	check_collider(t_game *game, t_vector_2 player_pos,
// 	t_vector_2 *chunks_pos)
// {
// 	if (game->level->map[(player_pos.x / CHUNK_SIZE)
// 			+ ((player_pos.y / CHUNK_SIZE) * game->level->map_vector.x)]
// 		== '1')
// 	{
// 		printf("WALL : x : [%d] y : [%d]\n", player_pos.x / CHUNK_SIZE,
// 			player_pos.y / CHUNK_SIZE);
// 	}
// 	if (game->level->map[(player_pos.x / CHUNK_SIZE + 1)
// 			+ ((player_pos.y / CHUNK_SIZE) * game->level->map_vector.x)]
// 		== '1')
// 	{
// 		printf("WALL : x : [%d] y : [%d]\n", player_pos.x / CHUNK_SIZE + 1,
// 			player_pos.y / CHUNK_SIZE);
// 	}
// 	if (game->level->map[(player_pos.x / CHUNK_SIZE)
// 			+ ((player_pos.y / CHUNK_SIZE + 1) * game->level->map_vector.x)]
// 		== '1')
// 	{
// 		printf("WALL : x : [%d] y : [%d]\n", player_pos.x / CHUNK_SIZE,
// 			player_pos.y / CHUNK_SIZE + 1);
// 	}
// 	if (game->level->map[(player_pos.x / CHUNK_SIZE + 1)
// 			+ ((player_pos.y / CHUNK_SIZE + 1) * game->level->map_vector.x)]
// 		== '1')
// 	{
// 		printf("WALL : x : [%d] y : [%d]\n", player_pos.x / CHUNK_SIZE + 1,
// 			player_pos.y / CHUNK_SIZE + 1);
// 	}
// 	return (1);
// }

static void	calculate_ideal_move(t_vector_2 *move, t_vector_2 dir_player,
	double delta_time)
{
	if (dir_player.y == -1)
		move->y -= SPEED * delta_time;
	if (dir_player.y == 1)
		move->y += SPEED * delta_time;
	if (dir_player.x == -1)
		move->x -= SPEED * delta_time;
	if (dir_player.x == 1)
		move->x += SPEED * delta_time;
	// printf("move : X : [%d] Y : [%d]\n", move->x, move->y);
}

static void	limit_move_at_chunk_size(t_vector_2 *move)
{
	if (move->x > CHUNK_SIZE)
		move->x = CHUNK_SIZE;
	if (move->y > CHUNK_SIZE)
		move->y = CHUNK_SIZE;
	if (move->x < -CHUNK_SIZE)
		move->x = -CHUNK_SIZE;
	if (move->y < -CHUNK_SIZE)
		move->y = -CHUNK_SIZE;
}

static void	check_collider(t_vector_2 *move, t_vector_2 player_pos,
	char *map, int x_max)
{
	t_vector_2	hypothetical_pos;
	int			recenter;
	
	recenter = 3;
	hypothetical_pos.x = player_pos.x + move->x;
	hypothetical_pos.y = player_pos.y + move->y;
	// printf("HYPO : X : [%d] Y : [%d]\n\n", hypothetical_pos.x,
		// hypothetical_pos.y);
	if (move->y < 0)	// direction NORD
	{
		if ((map[((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max)] == '1')
			|| (map[((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max)] == '1'))
		{
			move->y = move->y - (move->y % CHUNK_SIZE);
		}
	}
	if (move->y > 0)	// direction SUD
	{
		if ((map[((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max)] == '1')
			|| (map[((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max)] == '1'))
		{
			move->y = move->y - (move->y % CHUNK_SIZE);
		}
	}
	if (move->x < 0)	// direction OUEST
	{
		if ((map[((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max)] == '1')
			|| (map[((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max)] == '1'))
		{
			move->x = move->x - (move->x % CHUNK_SIZE);
		}
	}
	if (move->x > 0)	// direction EST
	{
		if ((map[((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max)] == '1')
			|| (map[((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max)] == '1'))
		{
			move->x = move->x - (move->x % CHUNK_SIZE);
		}
	}
	// printf("N_E : [%d]\n", ((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max));
	// printf("N_O : [%d]\n", ((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max));
	// printf("S_O : [%d]\n", ((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max));
	// printf("S_E : [%d]\n\n\n", ((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max));

	printf("N_E : [%c]\n", map[((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max)]);
	printf("N_O : [%c]\n", map[((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y + recenter) / CHUNK_SIZE) * x_max)]);
	printf("S_O : [%c]\n", map[((hypothetical_pos.x + recenter) / CHUNK_SIZE) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max)]);
	printf("S_E : [%c]\n\n\n", map[((hypothetical_pos.x - recenter) / CHUNK_SIZE + 1) + (((hypothetical_pos.y - recenter) / CHUNK_SIZE + 1) * x_max)]);
	// printf("NEW move : X : [%d] Y : [%d]\n\n", move->x, move->y);
}

// move->x = move->x - (move->x % CHUNK_SIZE);
// move->y = move->y - (move->y % CHUNK_SIZE);

void	check_move_player(t_game *game)
{
	t_vector_2	move;

	move.x = 0;
	move.y = 0;
	calculate_ideal_move(&move, game->gameplay->dir_player,
		game->gameplay->delta_time);
	limit_move_at_chunk_size(&move);
	// printf("player : X : [%d] Y : [%d]\n", game->gameplay->player_pos.x,
		// game->gameplay->player_pos.y);
	check_collider(&move, game->gameplay->player_pos, game->level->map,
		game->level->map_vector.x);
	game->gameplay->player_pos.x += move.x;
	game->gameplay->player_pos.y += move.y;
}

	// move = calculate_ideal_move(); 				init_move;
	// move = check_collider(); 					modifie move;
