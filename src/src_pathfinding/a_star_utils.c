/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:26:47 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 11:38:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Returns the absolute value of a number.
 * 
 * @param n number to calculate absolute value.
 * @return long unsigned int absolute value of the number.
 */
static long unsigned int	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}	

/**
 * @brief Calculate the distance between two positions.
 * 
 * @param pos start position.
 * @param end end position.
 * @param x size of the map in x (width).
 * @return int 
 */
int	dst_to_end(int pos, int end, int x)
{
	return ((int)ft_abs((end % x) - (pos % x))
		+ (int)ft_abs((end / x) - (pos / x)));
}

/**
 * @brief Initialize the path_map struct.
 * 
 * @param level level struct, used to get the number of cases.
 * @return t_path_map* initialized path_map struct.
 */
t_path_map	*init_path_map(t_level *level)
{
	int			i;
	t_path_map	*path_map;

	path_map = ft_calloc(sizeof(t_path_map), level->nb_cases);
	if (!path_map)
		return (NULL);
	i = 0;
	while (i < level->nb_cases)
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

/**
 * @brief Find the position of a character in the level map.
 * 
 * @param level level struct, used to get the map and map_vector.
 * @param searched_char character to find in the map.
 * @return int 
 */
int	find_character(t_level *level, char searched_char)
{
	int	i;
	int	j;

	j = 0;
	while (j < level->nb_cases)
	{
		i = 0;
		while (i < level->map_vector.x)
		{
			if (level->map[i + j] == searched_char)
				return (i + j);
			i++;
		}
		j += level->map_vector.x;
	}
	return (-1);
}

/**
 * @brief Calculate the position of the next case in the four directions.
 * 
 * @param dir direction to calculate the position.
 * @param pos position of the current case.
 * @param x size of the map in x (width).
 * @return int 
 */
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
