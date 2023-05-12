/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/12 12:03:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// memcpy_img(&game->window->background, &camera->img_background,
		// (t_vector_2){0, 0});
void	display_background(t_window *window, t_camera *camera, t_img *img)
{
	int	i;
	int	limit;
	int	start;
	int	end;

	i = 0;
	if (camera->camera_f_pos.x < 0 && camera->camera_f_pos.y < 0)
	{
		start = 0;
		end = (int)-camera->camera_f_pos.y * img->size.x;
		memcpy_img(&window->background, &camera->img_background, (t_vector_2){0, 0});

		// ft_memset(img->addr + start, color, end * 4);
	}
	// if (camera->camera_f_pos.x < 0)
	// {
	// 	end = (int)-camera->camera_f_pos.x;
	// 	limit = WINDOW_HEIGHT - (int)camera->camera_f_pos.y;
	// 	start = WINDOW_WIDTH * camera->camera_f_pos.y;
	// 	if (camera->camera_f_pos.y < 0)
	// 	{
	// 		start = WINDOW_WIDTH * -camera->camera_f_pos.y;
	// 		limit = WINDOW_HEIGHT - -(int)camera->camera_f_pos.y;
	// 	}
	// 	ft_memset(img->addr + (start * 4), color, end * 4);
	// 	while (i < limit)
	// 	{
	// 		printf("limit : [%d]\n", limit);
	// 		printf("start : [%d]\n", start);
	// 		printf("end : [%d]\n", end);
	// 		start += WINDOW_WIDTH;
	// 		i++;
	// 	}
	// }
}

void	camera(t_game *game, t_camera *camera, t_player *player)
{
	camera->camera_f_pos.x
		= player->player_f_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y
		= player->player_f_pos.y - (camera->camera_f_size.y / 2);
	get_chunks_to_display(game, camera);
	display_background(game->window, camera, &camera->img_background);
}
