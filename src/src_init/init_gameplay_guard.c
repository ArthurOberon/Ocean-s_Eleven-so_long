/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_guard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:39:49 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 17:38:50 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Count the number of guard in the map.
 * 
 * @param map map of the level to check.
 * @param size size of the map.
 * @return int number of guard in the map.
 */
static int	count_number_guard(char *map, int size)
{
	int	i;
	int	count_guard;

	i = 0;
	count_guard = 0;
	while (i < size)
	{
		if (map[i] == 'G')
			count_guard++;
		i++;
	}
	return (count_guard);
}

/**
 * @brief Initialize all variables of the guard struct.
 * 
 * @param game game struct, used to get the level struct.
 * @param guard guard struct, where all variables will be initialized.
 * @param number number of the guard in the map.
 */
static void	init_one_guard_variables(t_game *game, t_guard *guard, int number)
{
	guard->guard_pos_tab = number;
	guard->guard_chunk_pos.x = number % game->level->map_vector.x;
	guard->guard_chunk_pos.y = number / game->level->map_vector.x;
	guard->guard_pos.x = guard->guard_chunk_pos.x * CHUNK_SIZE;
	guard->guard_pos.y = guard->guard_chunk_pos.y * CHUNK_SIZE;
	guard->guard_f_pos.x = guard->guard_pos.x;
	guard->guard_f_pos.y = guard->guard_pos.y;
	guard->guard_look_dir.x = -1;
	guard->guard_look_dir.y = 0;
	guard->guard_f_dir.x = 0;
	guard->guard_f_dir.y = 0;
	guard->size.x = (CHUNK_SIZE * RATIO_PLAYER_SIZE_X);
	guard->size.y = (CHUNK_SIZE * (RATIO_PLAYER_SIZE_Y));
	set_guard_fov_direction(guard);
	guard->chasing_player = false;
	guard->is_alive = true;
	guard->is_pickpocketable = true;
	guard->is_in_player = false;
	guard->guard_sprite = game->assets->guard_idle;
	guard->time = (struct timeval){0, 0};
	guard->last_time = (struct timeval){0, 0};
	guard->chase_start_time = (struct timeval){0, 0};
	guard->chase_time = (struct timeval){0, 0};
}

/**
 * @brief Initialize one guard struct.
 * 
 * @param game game struct, used to get the level struct.
 * @param guard guard struct to initialize.
 * @param number number of the guard to initialize.
 * @param map map of the level in a string.
 */
static void	init_one_guard(t_game *game, t_guard *guard, int number, char *map)
{
	int	i;
	int	number_find;

	i = 0;
	number_find = 0;
	while (i < game->level->nb_cases)
	{
		if (map[i] == 'G')
		{
			if (number_find == number)
			{
				init_one_guard_variables(game, guard, i);
				return ;
			}
			else
				number_find++;
		}
		i++;
	}
}

/**
 * @brief Set the guard fov direction depending on the guard look direction.
 * 
 * @param guard guard struct to set the fov direction.
 */
void	set_guard_fov_direction(t_guard *guard)
{
	guard->guard_fov_pos_1.x = guard->guard_pos.x
		+ (guard->guard_look_dir.x * CHUNK_SIZE);
	guard->guard_fov_pos_1.y = guard->guard_pos.y
		+ (guard->guard_look_dir.y * CHUNK_SIZE);
	guard->guard_fov_f_pos_1.x = guard->guard_fov_pos_1.x;
	guard->guard_fov_f_pos_1.y = guard->guard_fov_pos_1.y;
	guard->guard_fov_pos_2.x = guard->guard_pos.x
		+ (guard->guard_look_dir.x * (CHUNK_SIZE * 2));
	guard->guard_fov_pos_2.y = guard->guard_pos.y
		+ (guard->guard_look_dir.y * (CHUNK_SIZE * 2));
	guard->guard_fov_f_pos_2.x = guard->guard_fov_pos_2.x;
	guard->guard_fov_f_pos_2.y = guard->guard_fov_pos_2.y;
}

/**
 * @brief Initialize the array of guards struct.
 * 
 * @param game game struct, used to get the level struct.
 * @param guards array of guards struct to initialize.
 */
void	init_guards(t_game *game, t_guard *guards)
{
	int		i;
	int		count_guard;

	count_guard = count_number_guard(game->level->map, game->level->nb_cases);
	if (count_guard == 0)
		return ;
	guards = ft_calloc(sizeof(t_guard), count_guard);
	if (!guards)
		exit_game(*game, "Error of malloc.\n");
	game->gameplay->guards = guards;
	game->gameplay->nb_guard = count_guard;
	i = 0;
	while (i < count_guard)
	{
		init_one_guard(game, &guards[i], i, game->level->map);
		i++;
	}
}
