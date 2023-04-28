/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_char_manipulations.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:43:07 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 14:57:23 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_2d_char_tab(char **tab, int y)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < y)
	{
		if (tab[i])
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
