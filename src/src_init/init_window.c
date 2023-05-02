/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:15:53 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/02 12:14:01 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	t_window	*window;

	window = ft_calloc(sizeof(t_window), 1);
	if (!window)
		free_game(*game, "Error of malloc.\n");
	game->window = window;
	window->img.size.x = game->level->map_vector.x * CHUNK_SIZE;
	window->img.size.y = game->level->map_vector.y * CHUNK_SIZE;
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		free_game(*game, "Error of mlx_init().\n");
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			window->img.size.x, window->img.size.y, "So_long");
	if (!window->win_ptr)
		free_game(*game, "Error of mlx_new_window().\n");
	window->img.mlx_img = mlx_new_image(window->mlx_ptr,
			window->img.size.x, window->img.size.y);
	if (!window->img.mlx_img)
		free_game(*game, "Error of mlx_new_image on the window.\n");
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &window->img.bpp,
			&window->img.line_len, &window->img.endian);
}
