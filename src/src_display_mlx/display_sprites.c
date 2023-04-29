/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 17:09:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	display_player(t_game *game)
{
	put_image_to_image(game->window,
		(t_vector_2){game->player_pos.x * CHUNK_SIZE,
		game->player_pos.y * CHUNK_SIZE},
		&(game->window->map_sprites[game->level->nb_cases].sprite_img)
	[game->window->map_sprites[game->level->nb_cases].frame]);
}

	// printf("pos player : x : [%d] y : [%d]\n", game->player_pos.x,
		// game->player_pos.y);

static void	update_frame(t_sprite *sprite)
{
	double			time;

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

void	display_sprites(t_game *game)
{
	int		i;
	int		j;
	int		y;

	j = 0;
	y = 0;
	while (j < game->level->map_vector.y)
	{
		i = 0;
		while (i < game->level->map_vector.x)
		{
			update_frame(&game->window->map_sprites[i + y]);
			put_image_to_image(game->window,
				(t_vector_2){i * CHUNK_SIZE, j * CHUNK_SIZE},
				&(game->window->map_sprites[i + y].sprite_img)
			[game->window->map_sprites[i + y].frame]);
			i++;
		}
		j++;
		y += game->level->map_vector.x;
	}
	display_player(game);
}
