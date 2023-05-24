/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:55:49 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/24 19:57:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos_to_chunk(int x, int y, int x_max)
{
	return ((x / CHUNK_SIZE) + ((y / CHUNK_SIZE) * x_max));
}

t_vector_2	chunk_to_pixel_pos(int chunk, int x_max)
{
	t_vector_2	pos;

	pos.x = (chunk % x_max) * CHUNK_SIZE;
	pos.y = (chunk / x_max) * CHUNK_SIZE;
	return (pos);
}

t_f_vector_2	chunk_to_pixel_f_pos(int chunk, int x_max)
{
	t_f_vector_2	pos;

	pos.x = (chunk % x_max) * CHUNK_SIZE;
	pos.y = (chunk / x_max) * CHUNK_SIZE;
	return (pos);
}
