/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_check_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/05 22:05:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Check if the file is a .ber file.
 * 
 * @param file_name file name to check.
 * @return int 1 if the file is a .ber file, 0 otherwise.
 */
int	is_ber(char *file_name)
{
	size_t	size;

	size = ft_strlen(file_name);
	if (size <= 3)
		return (0);
	return (is_equals(file_name + size - 4, ".ber"));
}

/**
 * @brief Check if the map is a rectangle,
 * meaning that all the lines have the same size.
 * 
 * @param lst list to check.
 * @param size size of the first line of the map.
 * @return int 1 if the map is a rectangle, 0 otherwise.
 */
int	is_rectangle(t_lst_map *lst, int size)
{
	while (lst)
	{
		if ((int)ft_strlen(lst->line) != size)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/**
 * @brief Check if the map is closed, meaning that the map is surrounded by '1'.
 * 
 * @param map map to check.
 * @param x size of the map in x (width).
 * @param y size of the map in y (height).
 * @return int 1 if the map is closed, 0 otherwise.
 */
int	is_closed(char **map, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < y)
	{
		if (i == 0 || i == y - 1)
		{
			j = 0;
			while (j < x)
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][x - 1] != '1')
				return (0);
		}
	}
	return (1);
}

/**
 * @brief Save the character c of the map in the flag struct.
 * 
 * @param flag flag struct, to fill with c.
 * @param c character to save.
 */
static void	save_characters(t_map_flag *flag, char c)
{
	if (c == 'P')
		flag->bool_p += 1;
	else if (c == 'E')
		flag->bool_e += 1;
	else if (c == 'C')
		flag->number_c += 1;
	else if (c != '0' && c != '1' && c != 'G')
		flag->bool_error += 1;
}

/**
 * @brief Check if the map has all the characters needed.
 * flag.bool_p is for the number of 'P' in the map (Player), it should be 1.
 * flag.bool_e is for the number of 'E' in the map (Exit), it should be 1.
 * flag.number_c is for the number of 'C' in the map (Collectible),
 * it should be at least 1.
 * flag.bool_error is for the number of characters
 * that are not '0', '1', 'P', 'E', 'C' or 'G' (Guard/Enemy).
 * 
 * @param map map to check.
 * @param x size of the map in x (width).
 * @param y size of the map in y (height).
 * @return int 1 if the map has all the characters needed, 0 otherwise.
 */
int	has_all_characters(char **map, int x, int y)
{
	int			i;
	int			j;
	t_map_flag	flag;

	flag.bool_p = 0;
	flag.bool_e = 0;
	flag.number_c = 0;
	flag.bool_error = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			save_characters(&flag, map[i][j]);
			j++;
		}
		i++;
	}
	if (flag.bool_p != 1 || flag.bool_e != 1
		|| flag.number_c == 0 || flag.bool_error != 0)
		return (0);
	return (1);
}
