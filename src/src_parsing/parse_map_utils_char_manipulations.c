/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_char_manipulations.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:43:07 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/05 22:09:16 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Create a malloc'd copy of a line.
 * 
 * @param line 
 * @return char* 
 */
char	*line_to_tab(char *line)
{
	int		i;
	int		size;
	char	*tab;

	size = ft_strlen(line);
	tab = ft_calloc(sizeof(char), size + 1);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		tab[i] = line[i];
	}
	tab[i] = 0;
	return (tab);
}

/**
 * @brief Converts a 2 dimensional char array to a 1 dimensional char array.
 * 
 * @param map_2d char array to convert.
 * @param x size of the map on x (width).
 * @param y size of the map on y (height).
 * @return char* converted map.
 */
char	*char_2d_to_1d(char **map_2d, int x, int y)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	*map;

	size = (x * y) + 1;
	map = ft_calloc(sizeof(char), size);
	if (map)
	{
		i = -1;
		j = -1;
		while (++j < y)
		{
			k = -1;
			while (++k < x)
				map[++i] = map_2d[j][k];
		}
		map[++i] = '\0';
	}
	return (map);
}
