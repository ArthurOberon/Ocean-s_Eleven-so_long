/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:08:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/16 20:02:58 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief check if a chunks is in the tab chunks_to_display.
 * 
 * @param chunks_to_display tab to check int.
 * @param size the size of the tab.
 * @param chunk the chunk to check.
 * @return int 1 if the chunk is in the tab, 0 if not.
 */
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

/**
 * @brief define the limit of the camera, compared to the position of the camera.
 * 
 * @param camera_f_pos camrea position in double.
 * @param camera_f_size camera size in double.
 * @param nb_chunks_in_camera number max of chunks in the camera on x and y.
 * @param level_size size of the level in chunks, on x and y.
 * @return t_vector_2 limit of chunks in the camera, on x and y.
 */
static t_vector_2	define_limit_of_camera(t_f_vector_2 camera_f_pos,
t_f_vector_2 camera_f_size, t_vector_2 nb_chunks_in_camera,
	t_vector_2 level_size)
{
	t_vector_2	limit;

	limit = nb_chunks_in_camera;
	if (camera_f_pos.x < 0)
		limit.x = (int)(camera_f_pos.x + camera_f_size.x) / CHUNK_SIZE;
	if (camera_f_pos.y < 0)
		limit.y = (int)(camera_f_pos.y + camera_f_size.y) / CHUNK_SIZE;
	if ((camera_f_pos.x + camera_f_size.x + CHUNK_SIZE) > level_size.x)
		limit.x = ((int)(level_size.x - camera_f_pos.x)) / CHUNK_SIZE;
	if ((camera_f_pos.y + camera_f_size.y + CHUNK_SIZE) > level_size.y)
		limit.y = ((int)(level_size.y - camera_f_pos.y)) / CHUNK_SIZE;
	limit.x += 1;
	limit.y += 1;
	return (limit);
}

/**
 * @brief Get the displayable chunks in a tab of int.
 * 
 * @param chunks_to_display int tab to fill.
 * @param chunk_start the first chunk, on the top left of the camera.
 * @param limit the limit of the camera, created by define_limit_of_camera().
 * @param max size max of the level, on x and y.
 */
static void	get_chunks_in_int_tab(int *chunks_to_display, int chunk_start,
	t_vector_2 limit, t_vector_2 max)
{
	int			i;
	int			j;
	int			k;
	int			chunk_max;
	int			chunk_tmp;

	k = 0;
	chunk_max = max.x * max.y;
	j = -1;
	while (++j < limit.y && j < max.y)
	{
		i = -1;
		chunk_tmp = chunk_start + j * max.x;
		while (++i < limit.x && i < max.x)
		{
			if (chunk_tmp > chunk_max)
				break ;
			chunks_to_display[k] = chunk_tmp;
			chunk_tmp++;
			k++;
		}
	}
	chunks_to_display[k] = -1;
}

/**
 * @brief set the tab camera->chunks_to_display
 * to only the chunks that are in the camera.
 * 
 * @param game all the info of the game.
 * @param camera contains the tab of chunks to display.
 */
void	get_chunks_to_display(t_game *game, t_camera *camera)
{
	int			chunk_start;
	t_vector_2	level_size;
	t_vector_2	limit;
	t_vector_2	max;

	max = game->level->map_vector;
	level_size = (t_vector_2){max.x * CHUNK_SIZE, max.y * CHUNK_SIZE};
	limit = define_limit_of_camera(camera->camera_f_pos, camera->camera_f_size,
			camera->nb_chunks_in_camera, level_size);
	chunk_start = pos_to_chunk(
			((int)camera->camera_f_pos.x * ((int)camera->camera_f_pos.x > 0)),
			((int)camera->camera_f_pos.y * ((int)camera->camera_f_pos.y > 0)),
			game->level->map_vector.x);
	ft_bzero(camera->chunks_to_display,
		(camera->nb_chunks_in_camera_total * 4));
	get_chunks_in_int_tab(camera->chunks_to_display, chunk_start, limit,
		game->level->map_vector);
}
