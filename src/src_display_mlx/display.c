/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/26 21:56:37 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	on_update(t_data *data)
{
	if (!data->win_ptr)
		return (0);
	background(&data->img, 0xE0E0E0);
	display_sprites(data);
	if (IS_DEBUG)
		display_debug(&data->img, GREEN, data->game.chunks_pos,
			data->game.level.nb_cases);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}

void	display(t_game *game)
{
	t_data	data;

	data = init_data(game);
	init_sprites(&data);
	mlx_hook(data.win_ptr, DestroyNotify, KeyPressMask, close_window, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &on_update, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	free_data(data);
}

	// mlx_destroy_display(data.mlx_ptr);
