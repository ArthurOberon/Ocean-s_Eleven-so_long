/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:02:17 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/26 14:54:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm_file(void *ptr, char *path, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(ptr, path, &img->size.x, &img->size.y);
	if (!img->mlx_img)
		printf("PANIC ! free and exit.");
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
}

void	init_new_resize_img(void *ptr, t_img *new_img, t_vector_2 new_size)
{
	new_img->mlx_img = mlx_new_image(ptr, new_size.x, new_size.y);
	new_img->addr = mlx_get_data_addr(new_img->mlx_img, &new_img->bpp,
			&new_img->line_len, &new_img->endian);
	new_img->size = new_size;
}

t_img	resize_img(void *ptr, t_img *src, t_vector_2 dst_size)
{
	int				i;
	int				j;
	t_f_vector_2	quotient;
	t_img			new_img;
	__uint32_t		pixel;

	if (src->size.x == dst_size.x && src->size.y == dst_size.y)
		return (*src);
	init_new_resize_img(ptr, &new_img, dst_size);
	quotient.x = (double)(src->size.x) / (double)(dst_size.x);
	quotient.y = (double)(src->size.y) / (double)(dst_size.y);
	j = -1;
	while (++j < dst_size.y)
	{
		i = -1;
		while (++i < dst_size.x)
		{
			pixel = get_color_pixel(src, (int)(i * quotient.x),
					(int)(j * quotient.y));
			img_pix_put(&new_img, i, j, pixel);
		}
	}
	mlx_destroy_image(ptr, src->mlx_img);
	return (new_img);
}
