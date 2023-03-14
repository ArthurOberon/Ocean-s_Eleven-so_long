/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_check_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/14 17:24:39 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *file_name)
{
	size_t	size;

	size = ft_strlen(file_name);
	if (size <= 3)
		return (0);
	return (is_equals(file_name + size - 4, ".ber"));
}

int	is_rectangle(t_lst_map *lst, int size)
{
	while (lst)
	{
		if ((int)ft_strlen(lst->line) - 1 != size)
			return (0);
		lst = lst->next;
	}
	return (1);
}

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

static void	save_characters(t_map_flag *flag, char c)
{
	if (c == 'P')
		flag->bool_p += 1;
	else if (c == 'E')
		flag->bool_e += 1;
	else if (c == 'C')
		flag->bool_c += 1;
	else if (c != '0' && c != '1')
		flag->bool_error += 1;
}

int	has_all_characters(char **map, int x, int y)
{
	int			i;
	int			j;
	t_map_flag	flag;

	flag.bool_p = 0;
	flag.bool_e = 0;
	flag.bool_c = 0;
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
		|| flag.bool_c == 0 || flag.bool_error != 0)
		return (0);
	return (1);
}
