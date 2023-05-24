/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/24 19:57:32 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_image(t_img *window_img, t_vector_2 pos, t_img *img)
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
			pixel = get_color_pixel(img, i, j);
			if (((pixel >> 24)) != 0xFF)
				img_pix_put(window_img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}

void	update_frame(t_sprite *sprite)
{
	struct timeval	time;
	double			delay;

	if (sprite->size == 1)
		return ;
	gettimeofday(&time, NULL);
	delay = (((double)(time.tv_usec - sprite->last_time.tv_usec)
				/ CLOCKS_PER_SEC) + time.tv_sec - sprite->last_time.tv_sec);
	if (delay >= DELAY_ANIMATION)
	{
		sprite->last_time = time;
		sprite->frame = (sprite->frame + 1) % sprite->size;
	}
}

static void	display_one_sprite(t_window *window, t_sprite *sprite,
	t_f_vector_2 pos)
{
	t_vector_2	pos_src;

	pos_src = (t_vector_2){0, 0};
	if ((int)pos.x < 0)
	{
		pos_src.x = -pos.x;
		pos.x = 0;
	}
	if ((int)pos.y < 0)
	{
		pos_src.y = -pos.y;
		pos.y = 0;
	}
	update_frame(sprite);
	memcpy_img(&window->img, (t_vector_2){pos.x, pos.y},
		&sprite->sprite_img[sprite->frame], pos_src);
}

void	display_sprites(t_game *game, t_camera *camera, t_window *window)
{
	int				i;
	t_f_vector_2	pos_tmp;

	i = 0;
	while (i < camera->nb_chunks_in_camera_total)
	{
		if (camera->chunks_to_display[i] == -1)
			break ;
		pos_tmp = chunk_to_pixel_f_pos(camera->chunks_to_display[i],
				game->level->map_vector.x);
		pos_tmp.x = pos_tmp.x - camera->camera_f_pos.x;
		pos_tmp.y = pos_tmp.y - camera->camera_f_pos.y;
		if (pos_tmp.x > camera->camera_f_size.x)
			pos_tmp.x = camera->camera_f_size.x - 1;
		if (pos_tmp.y > camera->camera_f_size.y)
			pos_tmp.y = camera->camera_f_size.y - 1;
		display_one_sprite(window,
			window->map_sprites[camera->chunks_to_display[i]], pos_tmp);
		i++;
	}
	display_player(game, window, game->gameplay->player,
		window->map_sprites[game->level->nb_cases
		+ game->gameplay->player->player_character]);
	display_gameplay_elements(game, game->gameplay, window);
}
