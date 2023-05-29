/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:01:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/29 19:35:34 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_camera_nb_chunks(t_game *game, t_vector_2 *nb_chunks)
{
	nb_chunks->x = WINDOW_WIDTH / CHUNK_SIZE;
	nb_chunks->y = WINDOW_HEIGHT / CHUNK_SIZE;
	if (nb_chunks->x > game->level->map_vector.x)
		nb_chunks->x = game->level->map_vector.x;
	if (nb_chunks->y > game->level->map_vector.y)
		nb_chunks->y = game->level->map_vector.y;
	nb_chunks->x++;
	nb_chunks->y++;
}

t_img	new_resize_img(t_game *game, void *ptr, t_img *src,
	t_vector_2 dst_size)
{
	int				i;
	int				j;
	t_f_vector_2	quotient;
	t_img			dst;
	__uint32_t		pixel;

	// dst.mlx_img = mlx_new_image(ptr, dst_size.x, dst_size.y);
	// if (!dst.mlx_img)
		// free_game(*game, "Error of mlx_xpm_file_to_image.\n");
	init_new_resize_img(game, ptr, &dst, dst_size);
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
			img_pix_put(&dst, i, j, pixel);
		}
	}
	return (dst);
}

static void	init_background_image(t_game *game, t_camera *camera)
{
	char		*complet_path;
	t_img		src;

	camera->img_background.size.x = WINDOW_WIDTH;
	camera->img_background.size.y = WINDOW_HEIGHT;
	complet_path = find_sprite_path(game, PATH_BACKGROUND, 0);
	init_xpm_file(game, game->window->mlx_ptr, complet_path, &src);
	free(complet_path);
	if (src.size.x == camera->img_background.size.x && src.size.y == camera->img_background.size.y)
	{
		camera->img_background = src;
		return ;
	}
	camera->img_background  = new_resize_img(game, game->window->mlx_ptr, &src, camera->img_background.size);
	mlx_destroy_image(game->window->mlx_ptr, src.mlx_img);
}
	// init_xpm_file(game, game->window->mlx_ptr,
	// camera->img_background = new_resize_img(game, game->window->mlx_ptr,
	// 		&src, (t_vector_2){WINDOW_WIDTH, WINDOW_HEIGHT});
		// complet_path, &camera->img_background);
	// free(complet_path);

void	init_camera(t_game *game)
{
	t_camera		*camera;
	t_f_vector_2	player_pos;

	camera = ft_calloc(sizeof(t_camera), 1);
	if (!camera)
		free_game(*game, "Error of malloc.\n");
	game->camera = camera;
	player_pos = game->gameplay->player->player_f_pos;
	camera->camera_f_size.x = WINDOW_WIDTH;
	camera->camera_f_size.y = WINDOW_HEIGHT;
	camera->camera_f_pos.x = player_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y = player_pos.y - (camera->camera_f_size.y / 2);
	init_camera_nb_chunks(game, &camera->nb_chunks_in_camera);
	camera->nb_chunks_in_camera_total = (camera->nb_chunks_in_camera.x + 1)
		* (camera->nb_chunks_in_camera.y + 1);
	camera->chunks_to_display = ft_calloc(sizeof(int),
			camera->nb_chunks_in_camera_total + 1);
	if (!camera->chunks_to_display)
		free_game(*game, "Error of malloc.\n");
	init_background_image(game, camera);
}
