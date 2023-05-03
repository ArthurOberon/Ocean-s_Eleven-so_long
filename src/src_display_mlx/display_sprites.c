/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/03 20:37:32 by aoberon          ###   ########.fr       */
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

static void	display_player(t_window *window, t_player *player, t_sprite *sprite)
{
	put_image_to_image(window, player->player_pos,
		&(sprite->sprite_img)[sprite->frame]);
}

static void	update_frame(t_sprite *sprite)
{
	double			time;

	if (sprite->frame == 1)
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

static void	display_one_sprite(t_window *window, t_camera *camera,
t_sprite *sprite, t_f_vector_2 pos)
{
	// if (check_inside_area(pos, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE},
		// camera->camera_f_pos, (t_f_vector_2){WINDOW_WIDTH, WINDOW_HEIGHT}))
	// {
		// printf("pos : x : [%f] y : [%f]\n", pos.x, pos.y);
		// printf("camera : x : [%f] y : [%f]\n\n", camera->camera_f_pos.x, camera->camera_f_pos.y);
		update_frame(sprite);
		put_image_to_image(window, (t_vector_2){pos.x, pos.y},
			&sprite->sprite_img[sprite->frame]);
	// }
}

void	display_sprites(t_game *game)
{
	int			i;
	int			j;
	int			y;

	j = 0;
	y = 0;
	while (j < game->level->map_vector.y)
	{
		i = 0;
		while (i < game->level->map_vector.x)
		{
			display_one_sprite(game->window, game->camera,
				game->window->map_sprites[i + y],
				(t_f_vector_2){i * CHUNK_SIZE, j * CHUNK_SIZE});
			i++;
		}
		j++;
		y += game->level->map_vector.x;
	}
	display_player(game->window, game->gameplay->player,
		game->window->map_sprites[y]);
	if (game->gameplay->nb_collect == 0)
		game->window->map_sprites[game->level->exit_pos]
			= game->assets->collect;
	// printf("player : x : [%f] y : [%f]\n\n", game->gameplay->player->player_f_pos.x, game->gameplay->player->player_f_pos.y);
	// printf("camera : x : [%f] y : [%f]\n\n", game->camera->camera_f_pos.x, game->camera->camera_f_pos.y);
}
