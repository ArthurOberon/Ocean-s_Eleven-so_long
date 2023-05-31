/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/31 14:47:55 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	t_vector_2	pos_src[2];

	pos_src[0] = (t_vector_2){0, 0};
	pos_src[1] = (t_vector_2){0, 0};
	if ((int)pos.x < 0)
	{
		pos_src[0].x = -pos.x;
		pos.x = 0;
	}
	if ((int)pos.y < 0)
	{
		pos_src[0].y = -pos.y;
		pos.y = 0;
	}
	if ((int)pos.x + sprite->sprite_img->size.x > window->img.size.x)
		pos_src[1].x = (pos.x + sprite->sprite_img->size.x)
			- window->img.size.x;
	if ((int)pos.y + sprite->sprite_img->size.y > window->img.size.y)
		pos_src[1].y = (pos.y + sprite->sprite_img->size.y)
			- window->img.size.y;
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

// 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
// 100C000000000000000000000000000000000000000000000000000000000000C00C0000000000000000001
// 100000000000111111111111111110000000000000000000000000000000000000000000000000000000001
// 1E0000000000111111111111111110000000000000000000000000000000000000000000000000000000001
// 100000000000111111111111111110000000000000000000000000000000000000000011110000000000001
// 1000000000001111111111111111100000CCCCCCCCCCCCCCCCCCCCCCCCC0000000000001110000000000001
// 100000000000111111111111111110000000000000000000000000000000000000000001110000000000001
// 1010000000000000000000000000000000000000000000000000000001P10000001CG0010C0000000000001
// 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
