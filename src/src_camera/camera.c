/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/04 23:05:25 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_inside_area(t_f_vector_2 pos, t_f_vector_2 pos_size,
t_f_vector_2 area, t_f_vector_2 size_area)
{
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

void	camera(t_game *game, t_camera *camera, t_player *player)
{
	camera->camera_f_pos.x
		= player->player_f_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y
		= player->player_f_pos.y - (camera->camera_f_size.y / 2);
	get_chunks_in_camera(game, camera);
}
