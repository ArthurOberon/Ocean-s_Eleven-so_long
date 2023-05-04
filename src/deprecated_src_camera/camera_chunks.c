/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:02:48 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/05 00:42:09 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	camera_in_of_map(t_game *game, t_camera *camera, int *chunks)
{
	int	i;
	int	j;
	int	chunk_start;
	int	chunk_tmp;

	j = 0;
	chunk_start = pos_to_chunk((int)camera->camera_f_pos.x,
			(int)camera->camera_f_pos.y, game->level->map_vector.x);
	while (j < camera->nb_chunks_in_camera.y)
	{
		i = 0;
		chunk_tmp = chunk_start
			+ ((j > 0) * (j * game->level->map_vector.x));
		while (i < camera->nb_chunks_in_camera.x)
		{
			chunks[i + (j * camera->nb_chunks_in_camera.x)] = chunk_tmp;
			chunk_tmp++;
			i++;
		}
		j++;
	}
	chunks[i + (j * camera->nb_chunks_in_camera.x)] = -1;
}

static int	is_camera_out_of_map(t_game *game, t_camera *camera)
{
	t_vector_2	last_chunk_pos;

	if (camera->camera_f_pos.x < 0 || camera->camera_f_pos.y < 0)
	{
		return (1);
	}
	last_chunk_pos = chunk_to_pixel_pos(game->level->nb_cases - 1,
			game->level->map_vector.x);
	if (camera->camera_f_pos.x + camera->camera_f_size.x
		> last_chunk_pos.x + CHUNK_SIZE)
	{
		return (1);
	}
	if (camera->camera_f_pos.y + camera->camera_f_size.y
		> last_chunk_pos.y + CHUNK_SIZE)
	{
		return (1);
	}
	return (0);
}

void	get_chunks_to_display(t_game *game, t_camera *camera)
{
	if (is_camera_out_of_map(game, camera))
	{
		camera_out_of_map(game, camera);
	}
	else
	{
		camera_in_of_map(game, camera, camera->chunks_to_display);
	}
	// int	i = 0;
	// while (i < camera->nb_chunks_in_camera_total)
	// {
	// 	if (camera->chunks_to_display[i] == -1)
	// 	{
	// 		printf("STOP ===> -1 !\n");
	// 		break ;
	// 	}
	// 	printf("%d : [%d]\n", i, camera->chunks_to_display[i]);
	// 	i++;
	// }
	// printf("\n");
}

// printf("totale  : [%d]\n", camera->nb_chunks_in_camera_total);
