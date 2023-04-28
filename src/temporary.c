/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:52:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 22:19:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*\*/

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
			ft_printf("%c ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_print_lst_map(t_lst_map *lst_map)
{
	while (lst_map != NULL)
	{
		ft_printf("%s", lst_map->line);
		lst_map = lst_map->next;
	}
}

void	ft_print_path_map(t_level level, int end_pos)
{
	int	i;

	i = 0;
	while (i < level.nb_cases)
	{
		if (i == end_pos && level.map[i] == 'E')
			ft_printf("E!");
		else if (i == end_pos && level.map[i] == 'C')
			ft_printf("C!");
		else if (level.path_map[i].has_been_check == 1 && level.map[i] == 'C')
			ft_printf("CK");
		else if (level.path_map[i].has_been_check == 1 && level.map[i] == 'E')
			ft_printf("EK");
		else if (level.map[i] == 'P')
			ft_printf("P_");
		else if (level.map[i] == 'E')
			ft_printf("E_");
		else if (level.map[i] == 'C')
			ft_printf("C_");
		else if (level.path_map[i].f == -1)
			ft_printf("##");
		else if (level.path_map[i].has_been_check == 1)
			ft_printf("OK");
		else if (level.path_map[i].f != 0)
			ft_printf("??");
		else
			ft_printf("__");
		ft_printf(" ");
		i++;
		if (i % level.map_vector.x == 0)
			ft_printf("\n");
	}
	ft_printf("\n");
}

void	ft_print_path_map_status(t_level level)
{
	int	i;

	i = 0;
	while (i < level.nb_cases)
	{
		if (level.path_map[i].has_been_check == 0
			&& level.path_map[i].dst_to_start == 0)
			ft_printf("Box [%d] is empty\n", i);
		else
		{
			ft_printf("\n");
			ft_printf("Box number : [%d]\n", i);
			ft_printf("	has been check : [%d]\n",
				level.path_map[i].has_been_check);
			ft_printf("	dst_to_start :[%d]\n", level.path_map[i].dst_to_start);
			ft_printf("	dst_to_end : [%d]\n", level.path_map[i].dst_to_end);
			ft_printf("	f : [%d]\n", level.path_map[i].f);
			ft_printf("	parent : [%d]\n", level.path_map[i].parent);
			ft_printf("\n");
		}
		i++;
	}
}

void	ft_print_collectibles_pos(t_vector_2 *c_pos, int c_count)
{
	int	i;

	i = 0;
	while (i < c_count)
	{
		ft_printf("collectibles %d : x : [%d]  y : [%d]\n", i + 1,
			c_pos[i].x, c_pos[i].y);
		i++;
	}
}

/**/
