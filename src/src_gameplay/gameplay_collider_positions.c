/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:05:45 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 22:49:09 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Check if a object's position is inside an area.
 * 
 * @param pos position in 2 vectors (x, y), of the object to check.
 * @param pos_size size in 2 vectors (x, y), of the object to check.
 * @param area position in 2 vectors (x, y), of the area to check.
 * @param size_area size in 2 vectors (x, y), of the area to check.
 * @return int 1 if the object is inside the area, 0 if not.
 */
int	is_inside_area(t_f_vector_2 pos, t_f_vector_2 pos_size,
t_f_vector_2 area, t_f_vector_2 size_area)
{
	if ((pos.x >= area.x && pos.x <= area.x + size_area.x)
		&& (pos.y >= area.y && pos.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x + pos_size.x >= area.x
			&& pos.x + pos_size.x <= area.x + size_area.x)
		&& (pos.y >= area.y && pos.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x >= area.x && pos.x <= area.x + size_area.x)
		&& (pos.y + pos_size.y >= area.y
			&& pos.y + pos_size.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x + pos_size.x >= area.x
			&& pos.x + pos_size.x <= area.x + size_area.x)
		&& (pos.y + pos_size.y >= area.y
			&& pos.y + pos_size.y <= area.y + size_area.y))
	{
		return (1);
	}
	return (0);
}

/**
 * @brief Check if the player collides with a guard.
 * And make the player been hit, and make the guard chase the player if so.
 * 
 * @param player player struct, used to get the player's position,
 * and make the player been hit.
 * @param guard guard struct, used to get the guard's position.
 */
static void	check_collider_player_to_guard(t_player *player, t_guard *guard)
{
	if (is_inside_area(player->player_f_pos,
			(t_f_vector_2){(double)player->size.x, (double)player->size.y},
		guard->guard_f_pos, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE}))
	{
		guard->is_in_player = true;
		if (player->iframes == false)
		{
			player->hp -= 1;
			player->has_been_hit = true;
			player->iframes = true;
		}
		if (guard->chasing_player == true)
			guard->chasing_player = false;
		else
			guard->chasing_player = true;
	}
	else
	{
		guard->is_in_player = false;
	}
}

/**
 * @brief Checks if the player collides with a guard's fov.
 * And make the guard chase the player if so.
 * 
 * @param game game struct, used te get the level struct.
 * @param player player struct, used to get the player's position.
 * @param guard guard struct, used to get the guard's fov's position.
 */
static void	check_collider_player_to_guard_fov(t_game *game, t_player *player,
	t_guard *guard)
{
	if (is_inside_area(player->player_f_pos,
			(t_f_vector_2){(double)player->size.x, (double)player->size.y},
		guard->guard_fov_f_pos_1, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE}))
	{
		guard->chasing_player = true;
	}
	else if (player->player_character != e_eater
		&& is_inside_area(player->player_f_pos,
			(t_f_vector_2){(double)player->size.x, (double)player->size.y},
		guard->guard_fov_f_pos_2,
		(t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE}))
	{
		if (game->level->map[pos_to_chunk(guard->guard_fov_pos_1.x,
					guard->guard_fov_pos_1.y, game->level->map_vector.x)]
			!= '2')
			guard->chasing_player = true;
	}
	else
	{
		if (guard->chasing_player == false)
		{
			guard->guard_f_dir.x = 0;
			guard->guard_f_dir.y = 0;
		}
	}
}

/**
 * @brief Checks if the player collides with a guard or a guard's fov
 * using there positions.
 * And changes the guard's state if it does.
 * 
 * @param game game struct, used te get the level struct.
 * @param player player struct, used to get the player's position.
 * @param guards guards struct, used to get the guards and fov's positions.
 */
void	check_collider_positions(t_game *game,
	t_player *player, t_guard *guards)
{
	int	i;

	i = 0;
	while (i < game->gameplay->nb_guard)
	{
		if (guards[i].is_alive == true
			&& is_in_chunks_to_display(game->camera->chunks_to_display,
				game->camera->nb_chunks_in_camera_total,
				guards[i].guard_pos_tab))
		{
			check_collider_player_to_guard(player, &guards[i]);
			check_collider_player_to_guard_fov(game, player, &guards[i]);
		}
		i++;
	}
}
