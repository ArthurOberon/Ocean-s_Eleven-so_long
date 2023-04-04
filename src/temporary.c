/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:52:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/04 20:26:04 by aoberon          ###   ########.fr       */
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

void	ft_print_path_map(t_level level, int end_pos)
{
	int	i;

	i = 0;
	while (i < level.nb_cases)
	{
		if (i == end_pos && level.map[i] == 'E')
			ft_putstr("E!");
		else if (i == end_pos && level.map[i] == 'C')
			ft_putstr("C!");
		else if (level.path_map[i].has_been_check == 1 && level.map[i] == 'C')
			ft_putstr("CK");
		else if (level.path_map[i].has_been_check == 1 && level.map[i] == 'E')
			ft_putstr("EK");
		else if (level.map[i] == 'P')
			ft_putstr("P_");
		else if (level.map[i] == 'E')
			ft_putstr("E_");
		else if (level.map[i] == 'C')
			ft_putstr("C_");
		else if (level.path_map[i].f == -1)
			ft_putstr("##");
		else if (level.path_map[i].has_been_check == 1)
			ft_putstr("OK");
		else if (level.path_map[i].f != 0)
			ft_putstr("??");
		else
			ft_putstr("__");
		ft_putstr(" ");
		i++;
		if (i % level.map_vector.x == 0)
			ft_putstr("\n");
	}
	ft_putstr("\n");
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

void	ft_print_collectibles_pos(t_vector_2 *c_pos, int c_count)
{
	int	i;

	i = 0;
	while (i < c_count)
	{
		printf("collectibles %d : x : [%d]  y : [%d]\n", i + 1,
			c_pos[i].x, c_pos[i].y);
		i++;
	}
}

void	ft_print_chunk_pos(t_vector_2 *chunk_pos, int c_count)
{
	int	i;

	i = 0;
	while (i < c_count)
	{
		printf("chunk %d : x : [%d]  y : [%d]\n", i + 1,
			chunk_pos[i].x, chunk_pos[i].y);
		i++;
	}
	printf("\n");
}

void	ft_print_1d_to_2d(t_level level)
{
	int	i;
	int	j;

	j = 0;
	while (j < level.map_vector.y * level.map_vector.x)
	{
		i = 0;
		while (i < level.map_vector.x)
		{
			ft_putchar(level.map[i + j]);
			ft_putchar(' ');
			i++;
		}
		j += level.map_vector.x;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

/**/
