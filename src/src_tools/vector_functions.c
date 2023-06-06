/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:54:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 11:31:18 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Returns the distance between two vectors.
 * 
 * @param vector vector to calculate distance from.
 * @return t_f_vector_2 distance vector.
 */
t_f_vector_2	normalize(t_vector_2 vector)
{
	float	magn;

	magn = sqrtf((vector.x * vector.x) + (vector.y * vector.y));
	if (magn == 0)
		return ((t_f_vector_2){1, 1});
	return ((t_f_vector_2){vector.x / magn, vector.y / magn});
}

/**
 * @brief Returns the direction vector from src to dest.
 * 
 * @param src source vector.
 * @param dest destination vector.
 * @return t_f_vector_2 normalized direction vector.
 */
t_f_vector_2	direction_normalized(t_vector_2 src, t_vector_2 dest)
{
	t_f_vector_2	dir;

	dir = (t_f_vector_2){dest.x - src.x, dest.y - src.y};
	dir = normalize((t_vector_2){dir.x, dir.y});
	return (dir);
}
