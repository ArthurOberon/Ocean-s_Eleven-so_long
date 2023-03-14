/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_char_manipulations.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:43:07 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/14 15:58:49 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*line_to_tab(char *line)
{
	int		i;
	int		size;
	char	*tab;

	size = ft_strlen(line);
	tab = malloc(sizeof(char) * size);
	i = -1;
	while (++i < size - 1)
	{
		tab[i] = line[i];
	}
	tab[i] = 0;
	return (tab);
}

void	free_2d_char_tab(char **tab, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*char_2d_to_1d(char **map_2d, int x, int y)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	*map;

	size = (x * y) + 1;
	map = malloc(sizeof(char) * size);
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
