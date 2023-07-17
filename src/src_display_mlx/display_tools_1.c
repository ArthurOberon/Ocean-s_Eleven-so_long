/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:17:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 18:56:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get the color pixel of a img on a specific position.
 * 
 * @param img img to get the pixel from.
 * @param i position x of the pixel.
 * @param j position y of the pixel.
 * @return __uint32_t the color pixel.
 */
__uint32_t	get_color_pixel(t_img *img, int i, int j)
{
	__uint32_t	pixel;

	pixel = (unsigned char)(img->addr[i * 4 + j * img->size.x * 4])
		| (unsigned char)(img->addr[i * 4 + j * img->size.x * 4 + 1]) << 8
		| (unsigned char)(img->addr[i * 4 + j * img->size.x * 4 + 2]) << 16
		| (unsigned char)(img->addr[i * 4 + j * img->size.x * 4 + 3]) << 24;
	return (pixel);
}
/* Other way to get color pixel :
	pixel = (img->addr[i * 4 + j * img->size.x * 4] & 0xFF)
		| (img->addr[i * 4 + j * img->size.x * 4 + 1] << 8 & 0xFF00)
		| (img->addr[i * 4 + j * img->size.x * 4 + 2] << 16 & 0xFF0000)
		| (img->addr[i * 4 + j * img->size.x * 4 + 3] << 24
			& 0xFF000000);
*/

/**
 * @brief Put a pixel on a img on a specific position.
 * 
 * @param img img to put the pixel on.
 * @param x position x to put the pixel.
 * @param y position y to put the pixel.
 * @param color color of the pixel to put.
 */
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * 4);
	*(unsigned int *)pixel = color;
}

/**
 * @brief Copy a img on a specific position
 * to another img on a specific position.
 * 
 * @param img_dst img to copy on.
 * @param pos_dst position to copy on.
 * @param img_src img to copy.
 * @param pos_src position to copy from.
 */
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

/**
 * @brief Put a img on a specific position on another img.
 * 
 * @param window_img image of the window to put the img on.
 * @param pos position to put the img on.
 * @param img img to put.
 */
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
			if ((pixel >> 24) != 0xFF)
				img_pix_put(window_img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}
