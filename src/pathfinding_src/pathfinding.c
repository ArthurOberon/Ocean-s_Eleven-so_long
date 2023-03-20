/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:52:58 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/20 16:31:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**malloc_map_pathfinding(t_level level)
{
	int		i;
	char	**map_2d;

	i = 0;
	map_2d = malloc(sizeof(char *) * level.map_vector.y);
	if (!map_2d)
		return (NULL);
	while (i < level.map_vector.y)
	{
		map_2d[i] = malloc(sizeof(char) * level.map_vector.x);
		if (!map_2d[i])
			return (NULL);
		i++;
	}
	return (map_2d);
}

char	**init_map_pathfinding(t_level level)
{
	int		i;
	int		j;
	int		k;
	char	**map_2d;

	map_2d = malloc_map_pathfinding(level);
	if (map_2d)
	{
		i = 0;
		k = 0;
		while (i < level.map_vector.y)
		{
			j = 0;
			while (j < level.map_vector.x)
			{
				map_2d[i][j] = level.map[k++];
				j++;
			}
			i++;
		}
	}
	return (map_2d);
}

int	pathfinding(t_level level)
{
	char	**map_copy_2d;

	map_copy_2d = init_map_pathfinding(level);
	ft_print_map(map_copy_2d, level.map_vector.x, level.map_vector.y);
	free_2d_char_tab(map_copy_2d, level.map_vector.y);
	return (0);
}
