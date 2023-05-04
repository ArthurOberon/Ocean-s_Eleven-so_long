/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_chunks_out_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:06:55 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/04 23:14:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vector_2 get_negative_diff(t_camera *camera, t_vector_2 max)
{
	t_vector_2	negative_diff;
	
	negative_diff.x = pos_to_chunk((int)camera->camera_f_pos.x
			+ WINDOW_WIDTH, 0, max.x);
	negative_diff.y = pos_to_chunk(0, (int)camera->camera_f_pos.y
			+ WINDOW_HEIGHT, max.x) / max.x;
	if (negative_diff.x >= camera->nb_chunks_in_camera.x)
		negative_diff.x = camera->nb_chunks_in_camera.x;
	if (negative_diff.y >= camera->nb_chunks_in_camera.y)
		negative_diff.y = camera->nb_chunks_in_camera.y;
	negative_diff.x++;
	negative_diff.y++;
	// printf("negative_diff : x : [%d] y : [%d]\n", negative_diff.x,
		// negative_diff.y);
}

static void	camera_out_by_negative(t_camera *camera, int chunk_start,
	t_vector_2 max)
{
	int			i;
	int			j;
	int			chunk_tmp;
	t_vector_2	negative_diff;

	j = 0;
	negative_diff = get_negative_diff(camera, max);
	while (j < (negative_diff.y) && j < max.y)
	{
		i = 0;
		chunk_tmp = chunk_start + ((j > 0) * (j * max.x));
		while (i < (negative_diff.x)
			&& i < max.x)
		{
			printf("OUT - display chunk : [%d]\n", chunk_tmp);
			chunk_tmp++;
			i++;
		}
		j++;
	}
	printf("\n");
}

static void	camera_out_by_positive(t_camera *camera, int chunk_start,
	t_vector_2 max)
{
	int			i;
	int			j;
	int			chunk_tmp;

	j = 0;
	while (j < camera->nb_chunks_in_camera.y && j < max.y)
	{
		i = 0;
		chunk_tmp = chunk_start + ((j > 0) * (j * max.x));
		while (i < camera->nb_chunks_in_camera.x && i < max.x)
		{
			printf("OUT + display chunk : [%d]\n", chunk_tmp);
			chunk_tmp++;
			i++;
		}
		j++;
	}
	printf("\n");
}

void	camera_out_of_map(t_game *game, t_camera *camera)
{
	int			chunk_start;
	t_vector_2	max;

	max = game->level->map_vector;
	chunk_start = pos_to_chunk((int)camera->camera_f_pos.x,
			(int)camera->camera_f_pos.y, game->level->map_vector.x);
	// printf("first chunk : [%d]\n", chunk_start);
	if (chunk_start < 0)
	{
		if (camera->camera_f_pos.x < 0 && camera->camera_f_pos.y < 0)
		{
			// printf("chunk : [%d]\n", pos_to_chunk(0, 0, game->level->map_vector.x));
			camera_out_by_negative(camera, 0, max);
		}
		else if (camera->camera_f_pos.x > 0)
		{
			// printf("chunk : [%d]\n", pos_to_chunk(camera->camera_f_pos.x, 0, game->level->map_vector.x));
			camera_out_by_negative(camera, pos_to_chunk(camera->camera_f_pos.x, 0, game->level->map_vector.x), max);
		}
		else if (camera->camera_f_pos.y > 0)
		{
			// printf("chunk : [%d]\n", pos_to_chunk(0, camera->camera_f_pos.y, game->level->map_vector.x));
			camera_out_by_negative(camera, pos_to_chunk(0, camera->camera_f_pos.y, game->level->map_vector.x), max);

		}
	printf("\n");
	}
	else
	{
		camera_out_by_positive(camera, chunk_start, max);
	}
}
