/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/07 14:47:17 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image_to_image(t_window *window, t_vector_2 pos, t_img *img)
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

	// t_vector_2	player_shift;

	// player_shift.x = player->player_pos.x
	// 	- ((CHUNK_SIZE * (1 - RATIO_PLAYER_SIZE_X)) / 2);
	// player_shift.y = player->player_pos.y
	// 	- ((CHUNK_SIZE * (1 - RATIO_PLAYER_SIZE_Y)) / 2);
	// put_image_to_image(window, player_shift,
	// 	&(sprite->sprite_img)[sprite->frame]);

static void	display_player(t_window *window, t_player *player, t_sprite *sprite)
{
	put_image_to_image(window, player->player_pos,
		&(sprite->sprite_img)[sprite->frame]);
}

static void	update_frame(t_sprite *sprite)
{
	double			time;

	if (sprite->size == 1)
		return ;
	time = clock() / CLOCKS_PER_SEC;
	if (IS_DEBUG_TIME)
		printf("time per second : [%f]\n", time);
	if ((time - sprite->last_time) >= DELAY_ANIMATION)
	{
		sprite->last_time = time;
		sprite->frame = (sprite->frame + 1) % sprite->size;
	}
}

	// printf("last_time : [%f]\n", sprite->last_time);

static void	display_one_sprite(t_window *window, t_sprite *sprite,
	t_f_vector_2 pos)
{
	update_frame(sprite);
	put_image_to_image(window, (t_vector_2){pos.x, pos.y},
		&sprite->sprite_img[sprite->frame]);
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
	if (game->gameplay->nb_collect == 0)
		window->map_sprites[game->level->exit_pos] = game->assets->collect;
}
