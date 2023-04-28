/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:53:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 22:38:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	calculate_four_dir(t_level level, t_path_map *path_map,
	int pos, int end_pos)
{
	int	dir;
	int	dir_pos;

	dir = 0;
	while (++dir <= 4)
	{
		dir_pos = calculate_dir_pos(dir, pos, level.map_vector.x);
		if (level.map[dir_pos] == '1')
		{
			path_map[dir_pos].has_been_check = 1;
			path_map[dir_pos].f = -1;
		}
		else
		{
			path_map[dir_pos].dst_to_start = path_map[pos].dst_to_start + 1;
			path_map[dir_pos].dst_to_end
				= dst_to_end(dir_pos, end_pos, level.map_vector.x);
			path_map[dir_pos].f = path_map[dir_pos].dst_to_start
				+ path_map[dir_pos].dst_to_end;
			path_map[dir_pos].parent = pos;
			if (path_map[dir_pos].dst_to_end == 0)
				return (1);
		}
	}
	return (0);
}

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

int	a_star(t_level level, int pos, int end_pos)
{
	int			bool_end;

	bool_end = 0;
	level.path_map[pos].dst_to_end = dst_to_end(pos,
			end_pos, level.map_vector.x);
	level.path_map[pos].f = level.path_map[pos].dst_to_end;
	while (!bool_end)
	{
		pos = find_lower_f(level.path_map, level.nb_cases);
		if (pos == -1)
			break ;
		bool_end = calculate_four_dir(level, level.path_map, pos, end_pos);
		if (IS_DEBUG)
			ft_print_path_map(level, end_pos);
	}
	return (bool_end);
}
		// ft_print_path_map_status(level);
		// printf("##################################################\n\n");
