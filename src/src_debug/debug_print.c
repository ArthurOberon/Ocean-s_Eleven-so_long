/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:10:14 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 22:38:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			printf("%c ", level.map[i + j]);
			i++;
		}
		j += level.map_vector.x;
		printf("\n");
	}
	printf("\n");
}

void	debug_chunk_pos(t_game *game)
{
	ft_print_chunk_pos(game->chunks_pos, game->level.nb_cases);
	ft_print_1d_to_2d(game->level);
}

void	debug_stat_tiles(t_stat_tiles stat)
{
	printf("Number of :\nexit :[%d]\nwall :[%d]\n", stat.exit, stat.wall);
	printf("ground : [%d] \nplayer : [%d]\n", stat.ground, stat.player);
	printf("collectibles : [%d]\n", stat.player);
	printf("TOTAL : [%d]\n", stat.exit + stat.wall + stat.ground + stat.player
		+ stat.collect);
}
