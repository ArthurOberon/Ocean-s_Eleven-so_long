/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/21 12:00:21 by aoberon          ###   ########.fr       */
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

			// pixel = *(unsigned int *)(img->addr + (j * img->line_len)
				// + (i * 4));
			// pixel = ((pixel >> 16) & 0xFF)
			// 		| (pixel & 0xFF00)
			// 		| ((pixel << 16) & 0xFF0000)
			// 		| (pixel & 0xFF000000);

			// pixel = (img->addr[(j * img->line_len) + (i * 4) + 3] << 24)
			// 	| (img->addr[(j * img->line_len) + (i * 4) + 2] << 16)
			// 	| (img->addr[(j * img->line_len) + (i * 4) + 1] << 8)
			// 	| img->addr[(j * img->line_len) + (i * 4)];

			// pixel = (img->addr[i * 4 + j * img->size.x * 4 + 3] << 24)
			// 	| (img->addr[i * 4 + j * img->size.x * 4 + 2] << 16)
			// 	| (img->addr[i * 4 + j * img->size.x * 4 + 1] << 8)
			// 	| img->addr[i * 4 + j * img->size.x * 4];

			// pixel = img->addr[i * 4 + j * img->size.x * 4]
			// 	| img->addr[i * 4 + j * img->size.x * 4 + 1] << 8
			// 	| img->addr[i * 4 + j * img->size.x * 4 + 2] << 16
			// 	| img->addr[i * 4 + j * img->size.x * 4 + 3] << 24;

			// pixel = img->addr[(j * img->line_len) + (i * 4)]
			// 	| img->addr[(j * img->line_len) + (i * 4) + 1] << 8
			// 	| img->addr[(j * img->line_len) + (i * 4) + 2] << 16
			// 	| img->addr[(j * img->line_len) + (i * 4) + 3] << 24;

			// pixel = *(unsigned int *)(img->addr + (j * img->line_len)
				// + (i * 4));
			// unsigned char red = pixel & 0xFF;
			// unsigned char blue = (pixel >> 8) & 0xFF;
			// unsigned char green = (pixel >> 16) & 0xFF;
			// unsigned char alpha = (pixel >> 24) & 0xFF;
			// pixel = (alpha << 24) | (blue << 16) | (green << 8) | red;

			// pixel = red | (green << 8) | (blue << 16) | (alpha << 24);

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
