/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:34:37 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/03 23:36:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_nb_move(t_game *game)
{
	char	*string_nb;

	string_nb = ft_itoa(game->gameplay->nb_move);
	if (!string_nb)
		free_game(*game, "Error of malloc.\n");
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 10, 44, BLUE,
		string_nb);
	free(string_nb);
}

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
