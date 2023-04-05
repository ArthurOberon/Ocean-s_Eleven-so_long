/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:17:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/05 13:45:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * 4);
	*(unsigned int *)pixel = color;
}

void	background(t_img *img, int color)
{
	ft_memset(img->addr, WINDOW_HEIGHT * WINDOW_WIDTH * 4, color);
}

void	display_debug(t_img *img, int color,
	t_vector_2 *chunk_pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		img_pix_put(img, chunk_pos[i].x, chunk_pos[i].y, color);
		img_pix_put(img, chunk_pos[i].x + CHUNK_SIZE,
			chunk_pos[i].y + CHUNK_SIZE, color);
		i++;
	}
}

void	display_square(t_img *img, t_vector_2 pos, int color)
{
	int	i;
	int	j;

	i = pos.x;
	while (i < pos.x + CHUNK_SIZE)
	{
		j = pos.y;
		while (j < pos.y + CHUNK_SIZE)
		{
			img_pix_put(img, i, j, color);
			j++;
		}
		i++;
	}
}

void	display_map(t_img *img, t_game game)
{
	int	i;

	i = 0;
	while (i < game.level.nb_cases)
	{
		if (game.level.map[i] == '0')
			display_square(img, game.chunks_pos[i], WHITE);
		else if (game.level.map[i] == '1')
			display_square(img, game.chunks_pos[i], RED);
		else if (game.level.map[i] == 'C')
			display_square(img, game.chunks_pos[i], GREEN);
		else if (game.level.map[i] == 'E')
			display_square(img, game.chunks_pos[i], BLACK);
		else if (game.level.map[i] == 'P')
			display_square(img, game.chunks_pos[i], BLUE);
		i ++;
	}
}
