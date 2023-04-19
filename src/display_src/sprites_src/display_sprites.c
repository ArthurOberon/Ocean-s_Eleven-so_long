/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/19 20:30:22 by arthurobero      ###   ########.fr       */
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
			pixel = img->addr[i * 4 + j * img->size.x * 4]
				| img->addr[i * 4 + j * img->size.x * 4 + 1] << 8
				| img->addr[i * 4 + j * img->size.x * 4 + 2] << 16
				| img->addr[i * 4 + j * img->size.x * 4 + 3] << 24;
			img_pix_put(&data->img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}
			// if ((pixel >> 24) != 0xFF)

void	display_sprites(t_data *data)
{
	int			i;
	int			j;
	int			k;
	int			y;

	j = 0;
	y = 0;
	while (j < data->game.level.map_vector.y)
	{
		i = 0;
		while (i < data->game.level.map_vector.x)
		{
			k = 0;
			while (k < data->map_sprites[i + y].size)
			{
				put_image_to_image(data,
					(t_vector_2){i * CHUNK_SIZE, j * CHUNK_SIZE},
					&(data->map_sprites[i + y].sprite_img)[k]);
				k++;
			}
			i++;
		}
		j++;
		y += data->game.level.map_vector.x;
	}
}
