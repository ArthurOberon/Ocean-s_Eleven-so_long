/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:34:37 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 17:55:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_fps(int *fps, double *delta_time)
{
	static double	last_time = 0;
	double			now;

	if (last_time == 0)
		last_time = clock();
	now = clock();
	*delta_time = (now - last_time) / CLOCKS_PER_SEC;
	while (*delta_time < (1 / FPS_CAP))
	{
		now = clock();
		*delta_time = (now - last_time) / CLOCKS_PER_SEC;
	}
	*fps = (int)(1.0 / *delta_time);
	last_time = now;
}
