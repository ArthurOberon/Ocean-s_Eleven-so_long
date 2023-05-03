/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:01:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/03 15:35:28 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_camera(t_game *game)
{
	t_camera		*camera;
	t_f_vector_2	player_pos;

	camera = ft_calloc(sizeof(t_camera), 1);
	if (!camera)
		free_game(*game, "Error of malloc.\n");
	game->camera = camera;
	player_pos = game->gameplay->player->player_f_pos;
	camera->camera_f_size.x = WINDOW_WIDTH;
	camera->camera_f_size.y = WINDOW_HEIGHT;
	camera->camera_f_pos.x = player_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y = player_pos.y - (camera->camera_f_size.y / 2);
	printf("player : x : [%f] y : [%f]\n", player_pos.x, player_pos.y);
	printf("camera : x : [%f] y : [%f]\n", camera->camera_f_pos.x,
		camera->camera_f_pos.y);
}
