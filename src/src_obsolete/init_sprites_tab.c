/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:39:40 by arthurobero       #+#    #+#             */
/*   Updated: 2023/04/25 22:00:14 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// static void	init_xpm_file(void *ptr, char *path, t_img *img)
// {
// 	img->mlx_img = mlx_xpm_file_to_image(ptr, path, &img->size.x, &img->size.y);
// 	if (!img->mlx_img)
// 		printf("PANIC ! free and exit.");
// 	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
// 			&img->endian);
// }

// static void	init_new_resize_img(void *ptr, t_img *new_img,
	// t_vector_2 new_size)
// {
// 	new_img->mlx_img = mlx_new_image(ptr, new_size.x, new_size.y);
// 	new_img->addr = mlx_get_data_addr(new_img->mlx_img, &new_img->bpp,
// 			&new_img->line_len, &new_img->endian);
// 	new_img->size = new_size;
// }

// static t_img	resize_img(void *ptr, t_img *src, t_vector_2 dst_size)
// {
// 	int				i;
// 	int				j;
// 	t_f_vector_2	quotient;
// 	t_img			new_img;
// 	__uint32_t		pixel;

// 	if (src->size.x == dst_size.x && src->size.y == dst_size.y)
// 		return (*src);
// 	init_new_resize_img(ptr, &new_img, dst_size);
// 	quotient.x = (double)(src->size.x) / (double)(dst_size.x);
// 	quotient.y = (double)(src->size.y) / (double)(dst_size.y);
// 	j = 0;
// 	while (j < dst_size.y)
// 	{
// 		i = 0;
// 		while (i < dst_size.x)
// 		{
// 			pixel = get_color_pixel(src, (int)(i * quotient.x),
// 					(int)(j * quotient.y));
// 			img_pix_put(&new_img, i, j, pixel);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (new_img);
// }

// void	get_img_sprite(void *ptr, char *path, t_sprite *sprite)
// {
// 	int		i;
// 	t_img	raw_img;

// 	i = 0;
// 	while (i < sprite->size)
// 	{
// 		raw_img.mlx_img = NULL;
// 		init_xpm_file(ptr, path, &raw_img);
// 		(sprite->sprite_img)[i] = resize_img(ptr, &raw_img,
// 				(t_vector_2){CHUNK_SIZE, CHUNK_SIZE});
// 		i++;
// 	}
// }

// void	get_wall_image(t_data *data, t_sprite *map_sprites, int pos)
// {
// 	int	x_max;
// 	int	y_max;
// 	int	x;
// 	int	y;

// 	x_max = data->game.level.map_vector.x;
// 	y_max = data->game.level.map_vector.y;
// 	x = pos % x_max;
// 	y = pos / (y_max - 1);
// 	x_max--;
// 	y_max--;
// 	if (x == 0 && y == 0)
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_N-O_64px.xpm",
// 			&map_sprites[pos]);
// 	else if (x == x_max && y == 0)
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_N-E_64px.xpm",
// 			&map_sprites[pos]);
// 	else if (x == x_max && y == y_max)
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_S-E_64px.xpm",
// 			&map_sprites[pos]);
// 	else if (x == 0 && y == y_max)
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_corner_S-O_64px.xpm",
// 			&map_sprites[pos]);
// 	else if ((x >= 1 && x < x_max) && y == 0)
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_up_64px.xpm",
// 			&map_sprites[pos]);
// 	else if ((x >= 1 && x < x_max) && y == y_max)
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_down_64px.xpm",
// 			&map_sprites[pos]);
// 	else if (x == 0 && (y >= 1 && y < y_max))
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_left_64px.xpm",
// 			&map_sprites[pos]);
// 	else if (x == x_max && (y >= 1 && y < y_max))
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/column_side_right_64px.xpm",
// 			&map_sprites[pos]);
// 	else
// 		get_img_sprite(data->mlx_ptr, "sprites/wall/roulette_table_64px.xpm",
// 			&map_sprites[pos]);
// }

// void	init_sprites_tab(t_data *data, t_sprite *map_sprites)
// {
// 	int			i;

// 	i = 0;
// 	while (i < data->game.level.nb_cases)
// 	{
// 		if (data->game.level.map[i] == '0' || data->game.level.map[i] == 'P')
// 			get_img_sprite(data->mlx_ptr, "sprites/ground/carpet_64px.xpm",
// 				&map_sprites[i]);
// 		else if (data->game.level.map[i] == '1')
// 			get_wall_image(data, map_sprites, i);
// 		else if (data->game.level.map[i] == 'C')
// 			get_img_sprite(data->mlx_ptr, "sprites/debug/test_32px.xpm",
// 				&map_sprites[i]);
// 		else if (data->game.level.map[i] == 'E')
// 			get_img_sprite(data->mlx_ptr, "sprites/debug/test.xpm",
// 				&map_sprites[i]);
// 		i++;
// 	}
// 	get_img_sprite(data->mlx_ptr, "sprites/player/player_64px.xpm",
// 		&map_sprites[i]);
// }
