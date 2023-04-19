/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:01:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/19 19:40:52 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_frame_size(t_data *data, t_sprite *map_sprites)
{
	int	i;

	i = 0;
	while (i < data->game.level.nb_cases)
	{
		if (data->game.level.map[i] == '0')
			map_sprites[i].size = 1;
		else if (data->game.level.map[i] == '1')
			map_sprites[i].size = 1;
		else if (data->game.level.map[i] == 'C')
			map_sprites[i].size = 1;
		else if (data->game.level.map[i] == 'P')
			map_sprites[i].size = 1;
		else if (data->game.level.map[i] == 'E')
			map_sprites[i].size = 1;
		i++;
	}
}

void	init_img_tab(t_sprite *map_sprites, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		map_sprites[i].sprite_img = malloc(sizeof(t_img) * map_sprites[i].size);
		if (!map_sprites)
			printf("PANIC ! free and exit.");
		map_sprites[i].sprite_img->mlx_img = NULL;
		i++;
	}
}

void	init_sprite(t_data *data)
{
	t_sprite	*map_sprites;

	map_sprites = malloc(sizeof(t_sprite) * data->game.level.nb_cases + 1);
	if (!map_sprites)
		printf("PANIC ! free and exit.");
	init_frame_size(data, map_sprites);
	init_img_tab(map_sprites, data->game.level.nb_cases);
	init_sprites_tab(data, map_sprites);
	data->map_sprites = map_sprites;
}
