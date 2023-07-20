/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:53:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 13:04:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Calculate the distance between two positions
 * for the four directions from the current position.
 * 
 * @param level level struct, used to get the map to check
 * if there a wall or a guard/ennemy.
 * @param path_map struct of the current path to set.
 * @param pos position to check in the four directions.
 * @param end_pos end position to calculate the distance.
 * @return int 1 if the end position was found, 0 otherwise.
 */
static int	calculate_four_dir(t_level *level, t_path_map *path_map,
	int pos, int end_pos)
{
	int	dir;
	int	dir_pos;

	dir = 0;
	while (++dir <= 4)
	{
		dir_pos = calculate_dir_pos(dir, pos, level->map_vector.x);
		if (level->map[dir_pos] == '1' || level->map[dir_pos] == 'G')
		{
			path_map[dir_pos].has_been_check = 1;
			path_map[dir_pos].f = -1;
		}
		else
		{
			path_map[dir_pos].dst_to_start = path_map[pos].dst_to_start + 1;
			path_map[dir_pos].dst_to_end
				= dst_to_end(dir_pos, end_pos, level->map_vector.x);
			path_map[dir_pos].f = path_map[dir_pos].dst_to_start
				+ path_map[dir_pos].dst_to_end;
			path_map[dir_pos].parent = pos;
			if (path_map[dir_pos].dst_to_end == 0)
				return (1);
		}
	}
	return (0);
}

/**
 * @brief Find the lower f value (addition of dst_to_start and dst_to_end)
 * in the path_map, return the position of it.
 * 
 * @param path_map map of the current path to check.
 * @param nb_cases number of cases in the map.
 * @return int position of the lower f value.
 * Return -1 if every case was checked.
 */
static int	find_lower_f(t_path_map *path_map, int nb_cases)
{
	int	i;
	int	lower_f_value;
	int	lower_f_pos;

	i = 0;
	lower_f_value = INT_MAX;
	lower_f_pos = -1;
	while (i < nb_cases)
	{
		if (path_map[i].f > 0 && path_map[i].f < lower_f_value
			&& !path_map[i].has_been_check)
		{
			lower_f_value = path_map[i].f;
			lower_f_pos = i;
		}
		i++;
	}
	if (lower_f_pos > -1)
		path_map[lower_f_pos].has_been_check = 1;
	return (lower_f_pos);
}

/**
 * @brief A* algorithm, return 1 if end is found a path
 * between the start and the end, 0 if not.
 * 
 * @param level level struct, used to get the map and the path_map.
 * @param pos position of the start.
 * @param end_pos end position.
 * @return int 1 if end is found a path between the start and the end, 0 if not.
 */
int	a_star(t_level *level, int pos, int end_pos)
{
	int			bool_end;

	bool_end = 0;
	level->path_map[pos].dst_to_end = dst_to_end(pos,
			end_pos, level->map_vector.x);
	level->path_map[pos].f = level->path_map[pos].dst_to_end;
	while (!bool_end)
	{
		pos = find_lower_f(level->path_map, level->nb_cases);
		if (pos == -1)
			break ;
		bool_end = calculate_four_dir(level, level->path_map, pos, end_pos);
	}
	return (bool_end);
}
