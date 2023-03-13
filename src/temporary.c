/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:52:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/13 15:04:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(char **map, int x, int y)
{
	int	i;
	int	j;

	if (map == NULL)
		return ;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_print_lst_map(t_lst_map *lst_map)
{
	while (lst_map != NULL)
	{
		printf("%s", lst_map->line);
		lst_map = lst_map->next;
	}
}
