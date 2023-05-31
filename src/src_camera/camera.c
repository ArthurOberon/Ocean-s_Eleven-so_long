/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/31 13:21:26 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_background(t_window *window, t_img *img)
{
	memcpy_img(&window->img, (t_vector_2){0, 0}, img,
		(t_vector_2[2]){{0, 0}, {0, 0}});
}

void	camera(t_game *game, t_camera *camera, t_player *player)
{
	camera->camera_f_pos.x
		= player->player_f_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y
		= player->player_f_pos.y - (camera->camera_f_size.y / 2);
	get_chunks_to_display(game, camera);
	display_background(game->window, &camera->img_background);
}
