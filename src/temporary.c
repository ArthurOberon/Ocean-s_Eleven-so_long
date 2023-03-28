/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:52:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/28 18:45:41 by aoberon          ###   ########.fr       */
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

void	ft_print_path_map(t_level level)
{
	int	i;

	i = 0;
	while (i < level.nb_cases)
	{
		if (level.map[i] == 'P')
			printf("P_");
		else if (level.map[i] == 'E')
			printf("E_");
		else if (level.path_map[i].f == -1)
			printf("##");
		else if (level.path_map[i].has_been_check == 1)
			printf("OK");
		else if (level.path_map[i].f != 0)
			printf("??");
		else
			printf("__");
		printf(" ");
		i++;
		if (i % level.map_vector.x == 0)
			printf("\n");
	}
}

void	ft_print_path_map_status(t_level level)
{
	int	i;

	i = 0;
	while (i < level.nb_cases)
	{
		if (level.path_map[i].has_been_check == 0
			&& level.path_map[i].dst_to_start == 0)
			printf("Box [%d] is empty\n", i);
		else
		{
			printf("\n");
			printf("Box number : [%d]\n", i);
			printf("	has been check : [%d]\n",
				level.path_map[i].has_been_check);
			printf("	dst_to_start :[%d]\n", level.path_map[i].dst_to_start);
			printf("	dst_to_end : [%d]\n", level.path_map[i].dst_to_end);
			printf("	f : [%d]\n", level.path_map[i].f);
			printf("	parent : [%d]\n", level.path_map[i].parent);
			printf("\n");
		}
		i++;
	}
}
