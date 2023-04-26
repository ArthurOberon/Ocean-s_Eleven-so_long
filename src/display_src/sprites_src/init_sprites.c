/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/26 15:39:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*find_sprite_path(char *start_path, int frame)
{
	char	*file_path;
	char	*str_itoa;
	char	*frame_path;
	char	*complet_path;

	file_path = SPRITES_PATH;
	file_path = ft_strjoin(file_path, start_path);
	if (!file_path)
		printf("PANIC ! free and exit.\n");
	str_itoa = ft_itoa(frame);
	if (!str_itoa)
		printf("PANIC ! free and exit.\n");
	frame_path = ft_strjoin(file_path, str_itoa);
	if (!frame_path)
		printf("PANIC ! free and exit.\n");
	free(file_path);
	free(str_itoa);
	complet_path = ft_strjoin(frame_path, ".xpm");
	if (!complet_path)
		printf("PANIC ! free and exit.\n");
	free(frame_path);
	return (complet_path);
}

void	init_sprite(void *ptr, t_sprite *sprite, int size, char *path)
{
	int		i;
	char	*complet_path;

	sprite->frame = 0;
	sprite->size = size;
	sprite->sprite_img = malloc(sizeof(t_img) * size);
	if (!sprite->sprite_img)
		printf("PANIC ! free and exit.\n");
	i = 0;
	while (i < size)
	{
		complet_path = find_sprite_path(path, i);
		init_xpm_file(ptr, complet_path, &(sprite->sprite_img)[i]);
		(sprite->sprite_img)[i] = resize_img(ptr, &(sprite->sprite_img)[i],
				(t_vector_2){CHUNK_SIZE, CHUNK_SIZE});
		free(complet_path);
		i++;
	}
}

void	get_sprite(t_data *data, t_sprite *sprite, int i)
{
	if (data->game.level.map[i] == '0' || data->game.level.map[i] == 'P')
		init_sprite(data->mlx_ptr, sprite, 2, "ground/carpet_64px");
	else if (data->game.level.map[i] == '1')
		get_wall_image(data, sprite, i);
	else if (data->game.level.map[i] == 'C')
		init_sprite(data->mlx_ptr, sprite, 1, "debug/test_32px");
	else if (data->game.level.map[i] == 'E')
		init_sprite(data->mlx_ptr, sprite, 1, "debug/test");
}

void	init_sprites(t_data *data)
{
	int			i;
	t_sprite	*map_sprites;

	i = 0;
	map_sprites = malloc(sizeof(t_sprite) * (data->game.level.nb_cases + 1));
	if (!map_sprites)
		printf("PANIC ! free and exit.\n");
	while (i < data->game.level.nb_cases)
	{
		get_sprite(data, &map_sprites[i], i);
		i++;
	}
	init_sprite(data->mlx_ptr, &map_sprites[i], 1,
		"player/player_64px");
	data->map_sprites = map_sprites;
}
