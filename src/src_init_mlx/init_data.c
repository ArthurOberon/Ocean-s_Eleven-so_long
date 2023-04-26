/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:55:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/26 21:56:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player_pos(t_data *data)
{
	data->game.player_pos.x = data->game.level.player_pos_tab
		- data->game.level.map_vector.x;
	data->game.player_pos.y = data->game.level.player_pos_tab
		/ data->game.level.map_vector.y;
}

static void	get_chunk_positions(t_vector_2 **chunk_pos, t_vector_2 size, int nb)
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

t_data	init_data(t_game *game)
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
	init_player_pos(&data);
	if (IS_DEBUG)
	{
		ft_print_chunk_pos(data.game.chunks_pos, data.game.level.nb_cases);
		ft_print_1d_to_2d(game->level);
	}
	return (data);
}
