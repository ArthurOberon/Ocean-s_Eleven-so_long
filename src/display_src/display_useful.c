/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_useful.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:17:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/21 14:21:03 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

__uint32_t	get_color_pixel(t_img *img, int i, int j)
{
	__uint32_t	pixel;

	pixel = (img->addr[i * 4 + j * img->size.x * 4] & 0xFF)
		| (img->addr[i * 4 + j * img->size.x * 4 + 1] << 8 & 0xFF00)
		| (img->addr[i * 4 + j * img->size.x * 4 + 2] << 16 & 0xFF0000)
		| (img->addr[i * 4 + j * img->size.x * 4 + 3] << 24
			& 0xFF000000);
	return (pixel);
}

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
