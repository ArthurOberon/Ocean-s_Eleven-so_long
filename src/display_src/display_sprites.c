/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/13 15:00:21 by aoberon          ###   ########.fr       */
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
			img_pix_put(&data->img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}
			// if ((pixel >> 24) != 0xFF)

void	init_img

t_sprite	*init_sprites_tab(t_data *data)
{
	int			i;
	t_sprite	*map_sprites;

	map_sprites = malloc(sizeof(t_sprite) * data->game.level.nb_cases + 1);
	if (!map_sprites)
		printf("PANIC ! free and exit.");
	i = 0;
	while (i < data->game.level.nb_cases)
	{
		init_img();
		if (data->game.level.map[i] == '0' || data->game.level.map[i] == 'P')
			init_xpm_file(data->mlx_ptr, "sprites/test.xpm",
				map_sprites[i].img);
		else if (data->game.level.map[i] == '1')
			init_xpm_file(data->mlx_ptr, "sprites/test.xpm",
				map_sprites[i].img);
		else if (data->game.level.map[i] == 'C')
			init_xpm_file(data->mlx_ptr, "sprites/test.xpm",
				map_sprites[i].img);
		else if (data->game.level.map[i] == 'E')
			init_xpm_file(data->mlx_ptr, "sprites/test.xpm",
				map_sprites[i].img);
		i++;
	}
	init_xpm_file(data->mlx_ptr, "sprites/test.xpm", map_sprites[i].img);
	return (map_sprites);
}

void	display_sprites(t_data *data)
{
	int			i;
	int			j;
	t_sprite	*map_sprites;

	j = 0;
	map_sprites = init_sprites_tab(data);
	while (j < data->game.level.nb_cases)
	{
		i = 0;
		while (i < data->game.level.map_vector.x)
		{
			put_image_to_image(data,
				(t_vector_2){i * data->game.level.map_vector.x, j},
				map_sprites[i + j].img);
			i++;
		}
		j += data->game.level.map_vector.y;
	}
}
