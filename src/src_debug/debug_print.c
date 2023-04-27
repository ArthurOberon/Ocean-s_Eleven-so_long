/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:10:14 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 17:14:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
