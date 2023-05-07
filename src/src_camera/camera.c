/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/07 17:07:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_background(t_camera *camera, t_img *img, int color)
{
	if (camera->camera_f_pos.x < 0)
	{
		// memset de camera.x a 0
		// WINDOW_WIDTH - (camera_f_pos.x + camera_f_size.x)
		;
	}
	if (camera->camera_f_pos.y < 0)
	{
		// memset de camera.y a 0
		// WINDOW_HEIGHT - (camera_f_pos.y + camera_f_size.y)
		;
	}
	if ((camera->camera_f_pos.x + camera->camera_f_size.x) > img->size.x)
	{
		// memset de camera.x_max a WINDOW_WIDTH
		// WINDOW_WIDHT - (window->img.size.x - camera_f_pos.x)
		;
	}
	if ((camera->camera_f_pos.y + camera->camera_f_size.y) > img->size.y)
	{
		// memset de camera.y_max a WINDOW_HEIGHT
		// WINDOW_HEIGHT - (window->img.size.y - camera_f_pos.y)
		;
	}
}

void	camera(t_game *game, t_camera *camera, t_player *player)
{
	camera->camera_f_pos.x
		= player->player_f_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y
		= player->player_f_pos.y - (camera->camera_f_size.y / 2);
	get_chunks_to_display(game, camera);
	display_background(camera, &game->window->img, 0xC6BF92);
}
