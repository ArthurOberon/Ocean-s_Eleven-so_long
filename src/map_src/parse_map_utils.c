/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:55:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/08 18:30:58 by aoberon          ###   ########.fr       */
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
