/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:18:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/11 15:04:51 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_chunk_positions(t_vector_2 **chunk_pos, t_vector_2 size, int nb)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(*chunk_pos) = malloc(sizeof(t_vector_2) * (nb));
	if (!*chunk_pos)
		printf("PANIC ! free and exit !\n");
	i = 0;
	y = 0;
	while (i < size.y)
	{
		j = 0;
		x = 0;
		while (j < size.x)
		{
			(*chunk_pos)[(i * size.x) + j] = (t_vector_2){x, y};
			j++;
			x += CHUNK_SIZE;
		}
		i++;
		y += CHUNK_SIZE;
	}
}

int	on_update(t_data *data)
{
	t_img	sprite_test;

	if (!data->win_ptr)
		return (0);
	background(&data->img, 0xE0E0E0);
	display_map(&data->img, data->game);
	if (IS_DEBUG)
		display_debug(&data->img, BLACK, data->game.chunks_pos,
			data->game.level.nb_cases);
	display_test(data, &sprite_test);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite_test.mlx_img,
		WINDOW_WIDTH / 2, 0);
	return (0);
}

t_data	data_init(t_game *game)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		printf("PANIC ! free and exit.");
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"So_long");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		exit(EXIT_FAILURE);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	data.game = *game;
	get_chunk_positions(&data.game.chunks_pos, data.game.level.map_vector,
		data.game.level.nb_cases);
	if (IS_DEBUG)
	{
		ft_print_chunk_pos(data.game.chunks_pos, data.game.level.nb_cases);
		ft_print_1d_to_2d(game->level);
	}
	return (data);
}

void	display(t_game *game)
{
	t_data	data;

	data = data_init(game);
	mlx_hook(data.win_ptr, DestroyNotify, KeyPressMask, close_window, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &on_update, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free(data.game.chunks_pos);
}
