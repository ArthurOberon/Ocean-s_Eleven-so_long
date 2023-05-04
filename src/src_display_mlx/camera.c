/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/04 22:51:11 by aoberon          ###   ########.fr       */
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

static void	camera_out_by_negative(t_camera *camera, int chunk_start,
	t_vector_2 max)
{
	int			i;
	int			j;
	int			chunk_tmp;
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
	j = 0;
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

static void	camera_out_of_map(t_game *game, t_camera *camera)
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

static void	camera_in_of_map(t_game *game, t_camera *camera)
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
			printf("IN display chunk : [%d]\n", chunk_tmp);
			chunk_tmp++;
			i++;
		}
		j++;
	}
	printf("\n");
}

static void	get_chunks_in_camera(t_game *game, t_camera *camera)
{
	if (is_camera_out_of_map(game, camera))
	{
		camera_out_of_map(game, camera);
	}
	else
	{
		camera_in_of_map(game, camera);
	}
}

void	camera(t_game *game, t_camera *camera, t_player *player)
{
	camera->camera_f_pos.x
		= player->player_f_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y
		= player->player_f_pos.y - (camera->camera_f_size.y / 2);
	get_chunks_in_camera(game, camera);
}
