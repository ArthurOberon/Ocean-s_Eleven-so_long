/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:15:53 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/16 02:53:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_window_ui(t_game *game, t_window *window)
{
	window->ui.size.x = window->img.size.x;
	window->ui.size.y = window->img.size.y;
		window->ui.mlx_img = mlx_new_image(window->mlx_ptr,
			window->ui.size.x, window->ui.size.y);
	if (!window->ui.mlx_img)
		free_game(*game, "Error of mlx_new_image.\n");
	window->ui.addr = mlx_get_data_addr(window->ui.mlx_img,
			&window->ui.bpp, &window->ui.line_len,
			&window->ui.endian);
}

static void	init_window_background(t_game *game, t_window *window)
{
	window->background.size.x = window->img.size.x;
	window->background.size.y = window->img.size.y;
		window->background.mlx_img = mlx_new_image(window->mlx_ptr,
			window->background.size.x, window->background.size.y);
	if (!window->background.mlx_img)
		free_game(*game, "Error of mlx_new_image.\n");
	window->background.addr = mlx_get_data_addr(window->background.mlx_img,
			&window->background.bpp, &window->background.line_len,
			&window->background.endian);
}

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
			WINDOW_WIDTH, WINDOW_HEIGHT, "So_long");
	if (!window->win_ptr)
		free_game(*game, "Error of mlx_new_window().\n");
	window->img.mlx_img = mlx_new_image(window->mlx_ptr,
			window->img.size.x, window->img.size.y);
	if (!window->img.mlx_img)
		free_game(*game, "Error of mlx_new_image.\n");
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &window->img.bpp,
			&window->img.line_len, &window->img.endian);
	init_window_background(game, window);
	init_window_ui(game, window);
}
