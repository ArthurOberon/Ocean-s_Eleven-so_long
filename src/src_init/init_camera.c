/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:01:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/03 14:08:09 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_camera_pos(t_camera *camera, t_game *game)
{
	t_f_vector_2	player_pos;

	player_pos = game->gameplay->player->player_f_pos;
	// camera->camera_f_pos.x = player_pos.x - (WINDOW_WIDTH / 2);
	// camera->camera_f_pos.y = player_pos.y - (WINDOW_HEIGHT / 2);
	camera->camera_f_pos.x = player_pos.x - (CHUNK_SIZE);
	camera->camera_f_pos.x = player_pos.y - (CHUNK_SIZE);
	printf("player : x : [%f] y : [%f]\n", player_pos.x, player_pos.y);
	printf("camera : x : [%f] y : [%f]\n", camera->camera_f_pos.x, camera->camera_f_pos.y);
}

void	init_camera(t_game *game)
{
	t_camera	*camera;

	camera = ft_calloc(sizeof(t_camera), 1);
	if (!camera)
		free_game(*game, "Error of malloc.\n");
	game->camera = camera;
	camera->mlx_ptr = mlx_init();
	if (!camera->mlx_ptr)
		free_game(*game, "Error of mlx_init().\n");
	camera->win_ptr = mlx_new_window(camera->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "So_long");
	if (!camera->win_ptr)
		free_game(*game, "Error of mlx_new_window().\n");
	camera->img.mlx_img = mlx_new_image(camera->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	camera->img.size.x = WINDOW_WIDTH;
	camera->img.size.y = WINDOW_HEIGHT;
	if (!camera->img.mlx_img)
		free_game(*game, "Error of mlx_new_image on the window.\n");
	camera->img.addr = mlx_get_data_addr(camera->img.mlx_img, &camera->img.bpp,
			&camera->img.line_len, &camera->img.endian);
	init_camera_pos(camera, game);
}
