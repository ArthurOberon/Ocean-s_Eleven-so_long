/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:55:49 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 23:10:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Convert a pixel position to a chunk position.
 * 
 * @param x x (width) position to convert.
 * @param y y (height) position to convert.
 * @param x_max size max of the map on x (width) in chunk.
 * @return int position converted.
 */
int	pos_to_chunk(int x, int y, int x_max)
{
	return ((x / CHUNK_SIZE) + ((y / CHUNK_SIZE) * x_max));
}

/**
 * @brief Convert a chunk position to a pixel position.
 * 
 * @param chunk chunk position to convert.
 * @param x_max size max of the map on x (width) in chunk.
 * @return t_vector_2 converted position.
 */
t_vector_2	chunk_to_pixel_pos(int chunk, int x_max)
{
	t_vector_2	pos;

	pos.x = (chunk % x_max) * CHUNK_SIZE;
	pos.y = (chunk / x_max) * CHUNK_SIZE;
	return (pos);
}

/**
 * @brief Convert a chunk position to a pixel position in double.
 * 
 * @param chunk chunk position to convert.
 * @param x_max size max of the map on x (width) in chunk.
 * @return t_f_vector_2 converted position.
 */
t_f_vector_2	chunk_to_pixel_f_pos(int chunk, int x_max)
{
	t_f_vector_2	pos;

	pos.x = (chunk % x_max) * CHUNK_SIZE;
	pos.y = (chunk / x_max) * CHUNK_SIZE;
	return (pos);
}
