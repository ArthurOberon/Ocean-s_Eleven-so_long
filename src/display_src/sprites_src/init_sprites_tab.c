/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:39:40 by arthurobero       #+#    #+#             */
/*   Updated: 2023/04/19 22:11:06 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_xpm_file(void *ptr, char *path, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(ptr, path, &img->size.x, &img->size.y);
	if (!img->mlx_img)
		printf("PANIC ! free and exit.");
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
}

static t_img	resize_img(void *ptr, t_img *src, t_vector_2 dst_size)
{
	int				i;
	int				j;
	t_f_vector_2	quotient;
	t_img			new_img;
	__uint32_t		pixel;

	if (src->size.x == dst_size.x && src->size.y == dst_size.y)
		return (*src);
	new_img.mlx_img = mlx_new_image(ptr, dst_size.x, dst_size.y);
	new_img.addr = mlx_get_data_addr(new_img.mlx_img, &new_img.bpp, &new_img.line_len,
			&new_img.endian);
	new_img.size = dst_size;
	quotient.x = (double)(src->size.x) / (double)(dst_size.x);
	quotient.y = (double)(src->size.y) / (double)(dst_size.y);
	j = 0;
	while (j < dst_size.y)
	{
		i = 0;
		while (i < dst_size.x)
		{
			pixel = src->addr[(int)(i * quotient.x) * 4 + (int)(j * quotient.y) * src->size.x * 4]
				| src->addr[(int)(i * quotient.x) * 4 + (int)(j * quotient.y) * src->size.x * 4 + 1] << 8
				| src->addr[(int)(i * quotient.x) * 4 + (int)(j * quotient.y) * src->size.x * 4 + 2] << 16
				| src->addr[(int)(i * quotient.x) * 4 + (int)(j * quotient.y) * src->size.x * 4 + 3] << 24;
			
			img_pix_put(&new_img, i, j, pixel);
			i++;
		}
		j++;
	}
	return (new_img);
}

			// pixel = *(unsigned int *)(src->addr + ((int)(j * quotient.y) * src->line_len) + ((int)(i * quotient.x) * 4));
			// pixel = ((pixel >> 16) & 0xFF)
			// 		| (pixel & 0xFF00)
			// 		| ((pixel << 16) & 0xFF0000)
			// 		| (pixel & 0xFF000000);

static void get_img_sprite(void *ptr, char *path, t_sprite *sprite)
{
	int		i;
	t_img	raw_img;

	i = 0;
	while (i < sprite->size)
	{
		raw_img.mlx_img = NULL;
		init_xpm_file(ptr, path, &raw_img);
		(sprite->sprite_img)[i] = resize_img(ptr, &raw_img,
			(t_vector_2){CHUNK_SIZE, CHUNK_SIZE});
		i++;
	}
}

void	init_sprites_tab(t_data *data, t_sprite *map_sprites)
{
	int			i;

	i = 0;
	while (i < data->game.level.nb_cases)
	{
		if (data->game.level.map[i] == '0' || data->game.level.map[i] == 'P')
			get_img_sprite(data->mlx_ptr, "sprites/test_32px.xpm", &map_sprites[i]);
		else if (data->game.level.map[i] == '1')
			get_img_sprite(data->mlx_ptr, "sprites/test.xpm", &map_sprites[i]);
		else if (data->game.level.map[i] == 'C')
			get_img_sprite(data->mlx_ptr, "sprites/New-Piskel_1.xpm", &map_sprites[i]);
		else if (data->game.level.map[i] == 'E')
			get_img_sprite(data->mlx_ptr, "sprites/test.xpm", &map_sprites[i]);
		i++;
	}
}

// void	init_sprites_tab(t_data *data, t_sprite *map_sprites)
// {
// 	int			i;

// 	i = 0;
// 	while (i < data->game.level.nb_cases)
// 	{
// 		if (data->game.level.map[i] == '0' || data->game.level.map[i] == 'P')
// 			init_xpm_file(data->mlx_ptr, "sprites/test.xpm",
// 				&map_sprites[i].sprite_img[0]);
// 		else if (data->game.level.map[i] == '1')
// 			init_xpm_file(data->mlx_ptr, "sprites/test_32px.xpm",
// 				&map_sprites[i].sprite_img[0]);
// 		else if (data->game.level.map[i] == 'C')
// 			init_xpm_file(data->mlx_ptr, "sprites/test.xpm",
// 				&map_sprites[i].sprite_img[0]);
// 		else if (data->game.level.map[i] == 'E')
// 			init_xpm_file(data->mlx_ptr, "sprites/test.xpm",
// 				&map_sprites[i].sprite_img[0]);
// 		(map_sprites[i].sprite_img)[0] = resize_img(data->mlx_ptr,
// 			&(map_sprites[i].sprite_img)[0], (t_vector_2){CHUNK_SIZE, CHUNK_SIZE});
// 		i++;
// 	}
// }
