/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:10:14 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 14:12:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_debug(t_game *game)
{
	if (IS_DEBUG)
	{
		ft_print_chunk_pos(game->chunks_pos, game->level.nb_cases);
		ft_print_1d_to_2d(game->level);
	}
}
