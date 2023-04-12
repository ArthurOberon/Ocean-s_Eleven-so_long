/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/12 14:13:19 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	init_xpm_file(void *ptr, char *path, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(ptr, path, &img->size.x, &img->size.y);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
}

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
			// if ((pixel >> 24) != 0xFF)
			img_pix_put(&data->img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}

void	display_test(t_data *data, t_img *img)
{
	init_xpm_file(data->mlx_ptr, "sprites/test.xpm", img);
	put_image_to_image(data, (t_vector_2){300, 16}, img);
}

	// sprite.img = img;
	// sprite.bpp = img->bpp;
	// sprite.endian = img->endian;
	// sprite.line_len = img->line_len;
	// printf("bpp = %d\n", sprite.bpp);
	// printf("line_len = %d\n", sprite.line_len);
	// printf("pixel = %s\n", data->img.addr);
	// printf("addr = %s\n", addr);
	// int		i;
	// int		j;
	// char	*pixel;

	// i = pos.x - CHUNK_SIZE;
	// while (i < pos.x)
	// {
	// 	j = pos.y - CHUNK_SIZE;
	// 	while (j < pos.y)
	// 	{
	// 		pixel = data->img.addr + (j * data->img.line_len + i * 4);
	// 		// *(unsigned int *)pixel = WHITE;
	// 		*pixel = *addr + (j * sprite.line_len + i * 4);
	// 		printf("OSKOUR = [%d]\n", (j * sprite.line_len + i * 4));
	// 		j++;
	// 	}
	// 	i++;
	// }

//

	// int			y;
	// y = 0;
	// while (y < 64 * 64)
	// {
	// 	ft_memcpy(data->img.addr + y, addr + y, data->img.bpp);
	// 	y++;
	// }

			// ft_memcpy(data->img.addr + (j * img->line_len + i * 4),
			// 	addr + (j * img->line_len + i * 4), data->img.bpp);
