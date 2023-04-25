/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_init_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/25 19:16:35 by aoberon          ###   ########.fr       */
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

static void	init_sprite(void *ptr, t_sprite *sprite, int size, char *path)
{
	sprite->frame = 0;
	sprite->size = size;
	sprite->sprite_img = malloc(sizeof(t_img) * size);
	if (!sprite->sprite_img)
		printf("PANIC ! free and exit.\n");
	sprite->sprite_img[0].mlx_img = NULL;
	init_xpm_file(ptr, path, &(sprite->sprite_img)[0]);
}

void	init_sprites(t_data *data)
{
	int			i;
	t_sprite	*map_sprites;

	i = 0;
	map_sprites = malloc(sizeof(t_sprite) * (data->game.level.nb_cases + 1));
	if (!map_sprites)
		printf("PANIC ! free and exit.\n");
	while (i < data->game.level.nb_cases + 1)
	{
		printf("i : [%d]\n", i);
		init_sprite(data->mlx_ptr, &map_sprites[i], 1,
			"sprites/debug/test.xpm");
		i++;
	}
	data->map_sprites = map_sprites;
}
