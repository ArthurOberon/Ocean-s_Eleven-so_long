/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/12 11:30:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <string.h>

void	put_image_to_image(t_window *window, t_vector_2 pos, t_img *img)
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
				img_pix_put(&window->img, i + pos.x, j + pos.y, pixel);
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

static void	display_player(t_window *window, t_player *player, t_sprite *sprite)
{
	t_vector_2	bomb_pos;

	if (player->iframes == true)
	{
		if (player->iframes_flashing == 2)
		{
			put_image_to_image(window, player->player_pos,
				&(sprite->sprite_img)[sprite->frame]);
			player->iframes_flashing = 0;
		}
		else
			player->iframes_flashing++;
	}
	else
		put_image_to_image(window, player->player_pos,
			&(sprite->sprite_img)[sprite->frame]);
	if (player->player_character == e_bomber)
	{
		bomb_pos.x = player->player_pos.x
			+ (CHUNK_SIZE * player->player_look_dir.x);
		bomb_pos.y = player->player_pos.y
			+ (CHUNK_SIZE * player->player_look_dir.y);
		put_image_to_image(window, bomb_pos,
			&(sprite->sprite_img)[sprite->frame]);
	}
}

static void	display_one_sprite(t_window *window, t_sprite *sprite,
	t_f_vector_2 pos)
{
	update_frame(sprite);
	memcpy_img(&window->img, &sprite->sprite_img[sprite->frame],
		(t_vector_2){pos.x, pos.y});
}

void	display_sprites(t_game *game, t_camera *camera, t_window *window)
{
	int				i;
	t_f_vector_2	tmp;

	i = 0;
	while (i < camera->nb_chunks_in_camera_total)
	{
		if (camera->chunks_to_display[i] == -1)
			break ;
		tmp = chunk_to_pixel_f_pos(camera->chunks_to_display[i],
				game->level->map_vector.x);
		display_one_sprite(window,
			window->map_sprites[camera->chunks_to_display[i]], tmp);
		i++;
	}
	display_player(window, game->gameplay->player,
		window->map_sprites[game->level->nb_cases]);
	display_gameplay_elements(game, game->gameplay, window);
}
