/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/02 13:55:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_inside_area(t_vector_2 pos, t_vector_2 area,
	t_vector_2 size_area)
{
	if (pos.x > area.x && pos.x < area.x + size_area.x)
		printf("X in !\n");
	if (pos.y > area.y && pos.y < area.y + size_area.y)
		printf("Y in !\n");
	return (0);
}

void	camera(t_game *game)
{
	// check_inside_area(game->gameplay->player->player_pos);
}
