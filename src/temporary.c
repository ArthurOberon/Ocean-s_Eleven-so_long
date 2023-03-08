/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:52:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/08 15:29:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(char **map)
{
	int	i;
	int	j;
	int	length;

	if (map == NULL)
		return ;
	i = 0;
	length = ft_strlen(map[0]);
	while (map[i])
	{
		j = 0;
		while (j < length)
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
