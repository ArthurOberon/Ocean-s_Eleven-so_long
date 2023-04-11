/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/11 15:37:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_test(t_data *data, t_img *img)
{
	t_vector_2	pos;
	t_sprite	sprite;
	char		*addr;

	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "sprites/test.xpm",
			&pos.x, &pos.y);
	sprite.img = img;
	sprite.bpp = img->bpp;
	sprite.endian = img->endian;
	sprite.line_len = img->line_len;
	addr = mlx_get_data_addr(img, &sprite.bpp, &sprite.line_len,
			&sprite.endian);
	printf("bpp = %d\n", sprite.bpp);
	printf("line_len = %d\n", sprite.line_len);
	printf("pixel = %s\n", data->img.addr);
	printf("addr = %s\n", addr);
}
	// int		i;
	// int		j;
	// char	*pixel;
// 
	// i = pos.x - CHUNK_SIZE;
	// while (i < pos.x)
	// {
		// j = pos.y - CHUNK_SIZE;
		// while (j < pos.y)
		// {
			// pixel = data->img.addr + (j * data->img.line_len + i * 4);
			// *(unsigned int *)pixel = WHITE;
			// *pixel = *addr + (j * sprite.line_len + i * 4);
			// printf("OSKOUR = [%d]\n", (j * sprite.line_len + i * 4));
			// j++;
		// }
		// i++;
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
