/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:34:37 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 23:15:32 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Calculate the fps of the game, and cap it to FPS_CAP.
 * 
 * @param fps fps of the game.
 * @param delta_time time difference between the last frame and the current one.
 */
void	calculate_fps(int *fps, double *delta_time)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			now;

	if (!last_time.tv_sec)
		gettimeofday(&last_time, NULL);
	gettimeofday(&now, NULL);
	*delta_time = (((double)(now.tv_usec - last_time.tv_usec) / CLOCKS_PER_SEC)
			+ now.tv_sec - last_time.tv_sec);
	while (*delta_time <= (1.f / FPS_CAP) * 0)
	{
		gettimeofday(&now, NULL);
		*delta_time = (((double)(now.tv_usec - last_time.tv_usec)
					/ CLOCKS_PER_SEC) + now.tv_sec - last_time.tv_sec);
	}
	*fps = (int)(1.f / *delta_time);
	last_time = now;
}
