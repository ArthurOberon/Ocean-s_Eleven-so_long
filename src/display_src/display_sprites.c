/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/25 22:00:25 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_image(t_data *data, t_vector_2 pos, t_img *img)
{		
	int			i;
	int			j;
	__uint32_t	pixel;

	j = 0;
	while (j < img->size.y)
	{
		i = 0;
		while (i < img->size.x)
		{
			pixel = get_color_pixel(img, i, j);
			if (((pixel >> 24)) != 0xFF)
				img_pix_put(&data->img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}

static void	display_player(t_data *data)
{
	put_image_to_image(data,
		(t_vector_2){data->game.player_pos.x * CHUNK_SIZE,
		data->game.player_pos.y * CHUNK_SIZE},
		&(data->map_sprites[data->game.level.nb_cases].sprite_img)[0]);
}

	// printf("pos player : x : [%d] y : [%d]\n", data->game.player_pos.x,
		// data->game.player_pos.y);

void	display_sprites(t_data *data)
{
	int		i;
	int		j;
	int		y;

	j = 0;
	y = 0;
	while (j < data->game.level.map_vector.y)
	{
		i = 0;
		while (i < data->game.level.map_vector.x)
		{
			put_image_to_image(data,
				(t_vector_2){i * CHUNK_SIZE, j * CHUNK_SIZE},
				&(data->map_sprites[i + y].sprite_img)
			[data->map_sprites[i + j].frame]);
			i++;
		}
		j++;
		y += data->game.level.map_vector.x;
	}
	display_player(data);
}

			// data->map_sprites[i + j].frame++;

// int	k;
// k = 0;
			// while (k < data->map_sprites[i + y].size)
			// {
				// put_image_to_image(data,
					// (t_vector_2){i * CHUNK_SIZE, j * CHUNK_SIZE},
					// &(data->map_sprites[i + y].sprite_img)[k++]);
			// }
