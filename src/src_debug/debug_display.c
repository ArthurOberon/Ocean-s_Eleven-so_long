/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:09:46 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 22:09:26 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_debug(t_img *img, int color,
	t_vector_2 *chunk_pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		img_pix_put(img, chunk_pos[i].x, chunk_pos[i].y, color);
		img_pix_put(img, chunk_pos[i].x + CHUNK_SIZE - 1, chunk_pos[i].y,
			color);
		img_pix_put(img, chunk_pos[i].x, chunk_pos[i].y + CHUNK_SIZE - 1,
			color);
		img_pix_put(img, chunk_pos[i].x + CHUNK_SIZE - 1,
			chunk_pos[i].y + CHUNK_SIZE - 1, color);
		i++;
	}
}

static void	display_square(t_img *img, t_vector_2 pos, int color)
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
	while (i < game.level->nb_cases)
	{
		if (game.level->map[i] == '0')
			display_square(img, game.gameplay->chunks_pos[i], WHITE);
		else if (game.level->map[i] == '1')
			display_square(img, game.gameplay->chunks_pos[i], RED);
		else if (game.level->map[i] == 'C')
			display_square(img, game.gameplay->chunks_pos[i], GREEN);
		else if (game.level->map[i] == 'E')
			display_square(img, game.gameplay->chunks_pos[i], BLACK);
		else if (game.level->map[i] == 'P')
			display_square(img, game.gameplay->chunks_pos[i], BLUE);
		i ++;
	}
}

static void	display_pixel_four(t_img *img, int x, int y, int color)
{
	img_pix_put(img, x, y, color);
	img_pix_put(img, x + 1, y, color);
	img_pix_put(img, x, y + 1, color);
	img_pix_put(img, x + 1, y + 1, color);
}

void	display_player_box_collider(t_img *img, t_player *player, int color)
{
	display_pixel_four(img, player->player_f_pos.x,
		player->player_f_pos.y, color);
	display_pixel_four(img, player->player_f_pos.x + player->size.x,
		player->player_f_pos.y, color);
	display_pixel_four(img, player->player_f_pos.x,
		player->player_f_pos.y + player->size.y, color);
	display_pixel_four(img, player->player_f_pos.x + player->size.x,
		player->player_f_pos.y + player->size.y, color);
}
