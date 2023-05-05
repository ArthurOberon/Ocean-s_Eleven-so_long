/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:01:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/05 17:14:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_camera_nb_chunks(t_game *game, t_vector_2 *nb_chunks)
{
	nb_chunks->x = WINDOW_WIDTH / CHUNK_SIZE;
	nb_chunks->y = WINDOW_HEIGHT / CHUNK_SIZE;
	if (nb_chunks->x > game->level->map_vector.x)
		nb_chunks->x = game->level->map_vector.x;
	if (nb_chunks->y > game->level->map_vector.y)
		nb_chunks->y = game->level->map_vector.y;
}

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
	init_camera_nb_chunks(game, &camera->nb_chunks_in_camera);
	camera->nb_chunks_in_camera_total = (camera->nb_chunks_in_camera.x + 1)
		* (camera->nb_chunks_in_camera.y + 1);
	camera->chunks_to_display = ft_calloc(sizeof(int),
			camera->nb_chunks_in_camera_total + 1);
	if (!camera->chunks_to_display)
		free_game(*game, "Error of malloc.\n");
}
