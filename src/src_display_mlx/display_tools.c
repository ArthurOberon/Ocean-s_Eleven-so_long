/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:17:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/31 14:33:23 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

__uint32_t	get_color_pixel(t_img *img, int i, int j)
{
	__uint32_t	pixel;

	pixel = (unsigned char)(img->addr[i * 4 + j * img->size.x * 4])
		| (unsigned char)(img->addr[i * 4 + j * img->size.x * 4 + 1]) << 8
		| (unsigned char)(img->addr[i * 4 + j * img->size.x * 4 + 2]) << 16
		| (unsigned char)(img->addr[i * 4 + j * img->size.x * 4 + 3]) << 24;
	return (pixel);
}

	// pixel = (img->addr[i * 4 + j * img->size.x * 4] & 0xFF)
	// 	| (img->addr[i * 4 + j * img->size.x * 4 + 1] << 8 & 0xFF00)
	// 	| (img->addr[i * 4 + j * img->size.x * 4 + 2] << 16 & 0xFF0000)
	// 	| (img->addr[i * 4 + j * img->size.x * 4 + 3] << 24
	// 		& 0xFF000000);

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * 4);
	*(unsigned int *)pixel = color;
}

// not use ?
void	background(t_img *img, int color)
{
	ft_memset(img->addr, color, img->size.x * img->size.y * 4);
}

void	memcpy_img(t_img *img_dst, t_vector_2 pos_dst,
	t_img *img_src, t_vector_2 *pos_src)
{
	int	j;

	j = 0;
	while (j < img_src->size.y - pos_src[1].y)
	{
		ft_memcpy(img_dst->addr + (pos_dst.y + j) * img_dst->line_len
			+ pos_dst.x * 4,
			img_src->addr + (pos_src[0].y + j)
			* img_src->line_len + pos_src[0].x * 4,
			img_src->line_len - pos_src[1].x * 4);
		j++;
	}
}

void	put_image_to_image(t_img *window_img, t_vector_2 pos, t_img *img)
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
				img_pix_put(window_img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}