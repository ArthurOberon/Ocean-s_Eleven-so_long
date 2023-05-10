/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:08:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/10 18:10:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_chunks_to_display(int *chunks_to_display, int size, int chunk)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (chunks_to_display[i] == -1)
			break ;
		if (chunks_to_display[i] == chunk)
			return (1);
		i++;
	}
	return (0);
}

static t_vector_2	define_limit_of_camera(t_f_vector_2 camera_f_pos,
t_f_vector_2 camera_f_size, t_vector_2 nb_chunks_in_camera, t_window *window)
{
	t_vector_2	limit;

	limit = nb_chunks_in_camera;
	if (camera_f_pos.x < 0)
		limit.x = (int)(camera_f_pos.x + camera_f_size.x) / CHUNK_SIZE;
	if (camera_f_pos.y < 0)
		limit.y = (int)(camera_f_pos.y + camera_f_size.y) / CHUNK_SIZE;
	if ((camera_f_pos.x + camera_f_size.x) > window->img.size.x)
		limit.x = ((int)(window->img.size.x - camera_f_pos.x)) / CHUNK_SIZE;
	if ((camera_f_pos.y + camera_f_size.y) > window->img.size.y)
		limit.y = ((int)(window->img.size.y - camera_f_pos.y)) / CHUNK_SIZE;
	limit.x += 1;
	limit.y += 1;
	return (limit);
}

static void	get_chunks_in_int_tab(int *chunks_to_display, int chunk_start,
	t_vector_2 limit, t_vector_2 max)
{
	int			i;
	int			j;
	int			chunk_max;
	int			chunk_tmp;

	chunk_max = max.x * max.y;
	j = -1;
	while (++j < limit.y && j < max.y)
	{
		i = -1;
		chunk_tmp = chunk_start + j * max.x;
		while (++i < limit.x && i < max.x)
		{
			if (chunk_tmp >= chunk_max)
				break ;
			chunks_to_display[i + (j * limit.x)] = chunk_tmp;
			chunk_tmp++;
		}
	}
}

void	get_chunks_to_display(t_game *game, t_camera *camera)
{
	int			chunk_start;
	t_vector_2	limit;
	t_vector_2	max;

	max = game->level->map_vector;
	limit = define_limit_of_camera(camera->camera_f_pos, camera->camera_f_size,
			camera->nb_chunks_in_camera, game->window);
	chunk_start = pos_to_chunk(
			((int)camera->camera_f_pos.x * ((int)camera->camera_f_pos.x > 0)),
			((int)camera->camera_f_pos.y * ((int)camera->camera_f_pos.y > 0)),
			game->level->map_vector.x);
	get_chunks_in_int_tab(camera->chunks_to_display, chunk_start, limit,
		game->level->map_vector);
}
