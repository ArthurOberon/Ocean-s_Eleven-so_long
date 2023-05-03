/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/03 14:42:10 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_inside_area(t_f_vector_2 pos, t_f_vector_2 pos_size,
t_f_vector_2 area, t_f_vector_2 size_area)
{
	printf("camera : x : [%f] y : [%f]\n", area.x, area.y);
	if ((pos.x >= area.x && pos.x <= area.x + size_area.x)
		&& (pos.y >= area.y && pos.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x + pos_size.x >= area.x
			&& pos.x + pos_size.x <= area.x + size_area.x)
		&& (pos.y >= area.y && pos.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x >= area.x && pos.x <= area.x + size_area.x)
		&& (pos.y + pos_size.y >= area.y
			&& pos.y + pos_size.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x + pos_size.x >= area.x
			&& pos.x + pos_size.x <= area.x + size_area.x)
		&& (pos.y + pos_size.y >= area.y
			&& pos.y + pos_size.y <= area.y + size_area.y))
	{
		return (1);
	}
	return (0);
}

void	camera(t_game *game)
{
	t_f_vector_2	zero;
	t_f_vector_2	size;

	zero.x = 0;
	zero.y = 0;
	size.x = CHUNK_SIZE * 2;
	size.y = CHUNK_SIZE * 2;
	// printf("player : x : [%d] y : [%d]\n", game->gameplay->player->player_pos.x, game->gameplay->player->player_pos.y);
	// printf("area : x : [%d] y : [%d]\n", zero.x, zero.y);
	// printf("size : x : [%d] y : [%d]\n", size.x, size.y);
	// check_inside_area(game->gameplay->player->player_f_pos, zero, zero, size);
	// printf("\n\n");
}
