/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:15:53 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 17:11:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player_pos(t_game *game)
{
	game->player_pos.x = game->level->player_pos_tab
		- game->level->map_vector.x;
	game->player_pos.y = game->level->player_pos_tab
		/ game->level->map_vector.y;
}

static void	get_chunk_positions(t_game *game, t_vector_2 **chunk_pos,
	t_vector_2 size, int nb)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(*chunk_pos) = ft_calloc(sizeof(t_vector_2), nb);
	if (!*chunk_pos)
		free_game(*game, "Error of malloc\n");
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

void	init_window(t_game *game)
{
	t_window	*window;

	window = ft_calloc(sizeof(t_window), 1);
	if (!window)
		free_game(*game, "Error of malloc\n");
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		free_game(*game, "Error of mlx_init()\n");
	window->win_ptr = mlx_new_window(window->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "So_long");
	if (!window->win_ptr)
		free_game(*game, "Error of mlx_new_window()\n");
	window->img.mlx_img = mlx_new_image(window->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!window->img.mlx_img)
		free_game(*game, "Error of mlx_new_image on the window\n");
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &window->img.bpp,
			&window->img.line_len, &window->img.endian);
	get_chunk_positions(game, &game->chunks_pos, game->level->map_vector,
		game->level->nb_cases);
	init_player_pos(game);
	if (IS_DEBUG)
		debug_chunk_pos(game);
	game->window = window;
}
