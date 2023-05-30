/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:17:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/30 13:55:01 by aoberon          ###   ########.fr       */
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

void	background(t_img *img, int color)
{
	ft_memset(img->addr, color, img->size.x * img->size.y * 4);
}

void	memcpy_img(t_img *img_dst, t_vector_2 pos_dst,
	t_img *img_src, t_vector_2 pos_src)
{
	int	j;

	j = 0;
	printf("img size : y : [%d]\n", img_src->size.y);
	printf("pos_src : y : [%d]\n", pos_src.y);
	printf("img - pos : [%d]\n", img_src->size.y - pos_src.y);
	printf("img - (pos / CHUNK_SIZE) : [%d]\n", img_src->size.y - (pos_src.y / CHUNK_SIZE));
	printf("pos - img : [%d]\n", pos_src.y - img_src->size.y);
	while (j < img_src->size.y - pos_src.y)
	{
		ft_memcpy(img_dst->addr + (pos_dst.y + j) * img_dst->line_len
			+ pos_dst.x * 4,
			img_src->addr + (pos_src.y + j) * img_src->line_len + pos_src.x * 4,
			img_src->line_len - pos_src.x * 4);
		j++;
	}
}
