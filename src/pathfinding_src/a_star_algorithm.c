/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:53:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/28 18:51:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dst_to_end(int pos, int end, int x)
{
	return ((int)ft_abs((end / x) - (pos / x))
		+ (int)ft_abs((end % x) - (pos % x)));
}

t_path_map	*init_path_map(t_level level)
{
	int			i;
	t_path_map	*path_map;

	path_map = malloc(sizeof(t_path_map) * level.nb_cases);
	if (!path_map)
		return (NULL);
	i = 0;
	while (i < level.nb_cases)
	{
		path_map[i].has_been_check = 0;
		path_map[i].dst_to_start = 0;
		path_map[i].dst_to_end = 0;
		path_map[i].f = 0;
		path_map[i].parent = 0;
		i++;
	}
	return (path_map);
}

int	find_character(t_level level, char searched_char)
{
	int	i;
	int	j;

	j = 0;
	while (j < level.nb_cases)
	{
		i = 0;
		while (i < level.map_vector.x)
		{
			if (level.map[i + j] == searched_char)
			{
				printf("I = %d & J = %d & return = %d\n", i, j, i + j);
				return (i + j);
			}
			i++;
		}
		j += level.map_vector.x;
	}
	return (-1);
}

int	calculate_dir_pos(int dir, int pos, int x)
{
	if (dir == 1)
		return (pos + x);
	if (dir == 2)
		return (pos + 1);
	if (dir == 3)
		return (pos - x);
	if (dir == 4)
		return (pos - 1);
	return (0);
}

int	calculate_four_dir(t_level level, t_path_map *path_map, int pos)
{
	int	dir;
	int	dir_pos;

	dir = 1;
	while (dir <= 4)
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
				= dst_to_end(dir_pos, level.exit_pos, level.map_vector.x);
			path_map[dir_pos].f = path_map[dir_pos].dst_to_start
				+ path_map[dir_pos].dst_to_end;
			path_map[dir_pos].parent = pos;
			if (path_map[dir_pos].dst_to_end == 0)
				return (1);
		}
		dir++;
	}
	return (0);
}

int	find_lower_f(t_path_map *path_map, int nb_cases, int pos)
{
	int	i;
	int	lower_f_value;
	int	lower_f_pos;

	i = 0;
	lower_f_value = INT_MAX;
	lower_f_pos = pos;
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
	return (lower_f_pos);
}

int	a_star(t_level level)
{
	int			pos;
	int			bool_end;

	level.path_map = init_path_map(level);
	if (!level.path_map)
		return (0);
	bool_end = 0;
	level.exit_pos = find_character(level, 'E');
	pos = find_character(level, 'P');
	level.player_pos = pos;
	level.path_map[pos].dst_to_end = dst_to_end(pos,
			level.exit_pos, level.map_vector.x);
	level.path_map[pos].f = INT_MIN;
	while (!bool_end)
	{
		pos = find_lower_f(level.path_map, level.nb_cases, pos);
		level.path_map[pos].has_been_check = 1;
		printf("NEW POS : [%d]\n", pos);
		bool_end = calculate_four_dir(level, level.path_map, pos);
		ft_print_path_map(level);
		// ft_print_path_map_status(level);
		printf("##################################################\n\n");
	}
	return (1);
}
