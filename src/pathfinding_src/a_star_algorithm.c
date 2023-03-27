/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:53:34 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/27 17:01:03 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_path_map	*init_path_map(t_level level)
// {
// 	int			i;
// 	int			j;
// 	t_path_map	*path_map;

// 	path_map = malloc(sizeof(t_path_map)
// 			* (level.map_vector.x * level.map_vector.y));
// 	if (!path_map)
// 		return (NULL);
// 	j = 0;
// 	while (j < level.nb_cases)
// 	{
// 		i = 0;
// 		while (i < level.map_vector.x)
// 		{
// 			i++;
// 		}
// 		j += level.map_vector.x;
// 	}
// }

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

int	a_star(t_level level)
{
	t_path_map	*path_map;
	int			pos;

	path_map = init_path_map(level);
	if (!path_map)
		return (0);
	pos = find_character(level, 'P');
	path_map[pos].has_been_check = 1;
	find_character(level, 'E');
	return (1);
}
