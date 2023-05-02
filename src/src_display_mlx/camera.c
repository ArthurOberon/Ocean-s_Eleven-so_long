/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/02 19:14:39 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_inside_area(t_vector_2 pos, t_vector_2 area,
	t_vector_2 size_area)
{
	if ((pos.x >= area.x && pos.x <= area.x + size_area.x)
		&& (pos.y >= area.y && pos.y <= area.y + size_area.y))
	{
		// printf("IN\n");
		return (1);
	}
	// printf("OUT\n");
	return (0);
}

void	camera(t_game *game)
{
	t_vector_2	zero;
	t_vector_2	size;

	zero.x = 0;
	zero.y = 0;
	size.x = CHUNK_SIZE * 2;
	size.y = CHUNK_SIZE * 2;
	// printf("player : x : [%d] y : [%d]\n", game->gameplay->player->player_pos.x, game->gameplay->player->player_pos.y);
	// printf("area : x : [%d] y : [%d]\n", zero.x, zero.y);
	// printf("size : x : [%d] y : [%d]\n", size.x, size.y);
	check_inside_area(game->gameplay->player->player_pos, zero, size);
	// printf("\n\n");
}
