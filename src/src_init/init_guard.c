/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_guard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:39:49 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/10 19:09:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	set_guard_direction(guard);
	guard->following_player = false;
	guard->is_alive = true;
	guard->time = 0;
	guard->last_time = 0;
}

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
			}
			else
				number_find++;
		}
		i++;
	}
}

void	set_guard_direction(t_guard *guard)
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

void	init_guards(t_game *game, t_guard *guards)
{
	int		i;
	int		count_guard;

	ft_print_1d_to_2d(game->level);
	count_guard = count_number_guard(game->level->map, game->level->nb_cases);
	if (count_guard == 0)
		return ;
	guards = ft_calloc(sizeof(t_guard), count_guard);
	if (!guards)
		free_game(*game, "Error of malloc.\n");
	game->gameplay->guards = guards;
	game->gameplay->nb_guard = count_guard;
	i = 0;
	while (i < count_guard)
	{
		init_one_guard(game, &guards[i], i, game->level->map);
		i++;
	}
}
