/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_qte_launch.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:48:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 10:56:07 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get the pixel to start the loading bar
 * (the first pixel of the bar that is not transparent).
 * 
 * @param qte qte struct, used to get the pixel_start value.
 * @param sprite sprite struct, used to get the size of the sprite_img.
 */
static void	get_pixel_start(t_qte *qte, t_sprite *sprite)
{
	__uint32_t	pixel;

	qte->pixel_start = 0;
	while (qte->pixel_start < sprite->sprite_img->size.x)
	{
		pixel = get_color_pixel(
				&(sprite->sprite_img)[qte->loading_frame], qte->pixel_start, 0);
		if (pixel >> 24 == 0xFF)
		{
			qte->pixel_start++;
		}
		else
			break ;
	}
	if (qte->pixel_start != 0 && qte->loading_value > qte->pixel_start)
	{
		qte->loading_value = sprite->sprite_img->size.x - qte->pixel_start;
	}
}

/**
 * @brief Get the pixel to end the loading bar
 * (the last pixel of the bar that is not transparent).
 * 
 * @param qte qte struct, used to get the loading_value value.
 * @param sprite sprite struct, used to get the size of the sprite_img.
 */
static void	get_pixel_end(t_qte *qte, t_sprite *sprite)
{
	int			end_pixel;
	__uint32_t	pixel;

	end_pixel = sprite->sprite_img->size.x - 1;
	while (end_pixel > 0)
	{
		pixel = get_color_pixel(
				&(sprite->sprite_img)[qte->loading_frame], end_pixel, 0);
		if (pixel >> 24 == 0xFF)
		{
			end_pixel--;
		}
		else
			break ;
	}
	end_pixel = sprite->sprite_img->size.x - end_pixel;
	if (qte->loading_value < end_pixel)
	{
		qte->loading_value = 0;
	}
}

/**
 * @brief Display the loading bar.
 * 
 * @param game game struct, used to get the window and assets structs.
 * @param qte qte struct, used to get the loading_frame and loading_value values.
 * @param pos position of the display.
 */
static void	display_bar(t_game *game, t_qte *qte,
	t_vector_2 pos)
{
	if (qte->loading_frame == 1 && qte->start_time.tv_sec == 0)
		put_image_to_image(&game->window->img, pos,
			&(game->assets->qte->sprite_img)[0]);
	put_image_to_image_with_limit(&game->window->img, pos,
		&(game->assets->qte->sprite_img)[qte->loading_frame],
		(t_vector_2[2]){{qte->pixel_start, 0}, {qte->loading_value, 0}});
}

/**
 * @brief Display the qte.
 * 
 * @param game game struct, used to get the window and assets structs.
 * @param qte qte struct.
 * @param pos position of the display.
 */
static void	display_qte_(t_game *game, t_qte *qte, t_vector_2 pos)
{
	double	delay;

	if (qte->start_time.tv_sec == 0)
		gettimeofday(&qte->start_time, NULL);
	gettimeofday(&qte->time, NULL);
	delay = (((double)(qte->time.tv_usec - qte->start_time.tv_usec)
				/ CLOCKS_PER_SEC) + qte->time.tv_sec
			- qte->start_time.tv_sec);
	get_pixel_start(qte, game->assets->qte);
	get_pixel_end(qte, game->assets->qte);
	if (delay >= DELAY_QTE)
	{
		if (qte->loading_value > 0)
			qte->loading_value -= 1;
		qte->start_time = (struct timeval){0, 0};
	}
	display_bar(game, qte, pos);
	if (qte->loading_value == 0)
	{
		qte->loading_frame += 1;
		qte->loading_value = QTE_CHUNK_SIZE;
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, 0, 0);
}

/**
 * @brief Launch the qte.
 * 
 * @param game game struct, used to get the camera, window and level structs.
 * @param qte qte struct, used to launch the qte.
 * @param guard guard struct,
 * used to set up guard depending on the course of the qte.
 */
void	launch_qte(t_game *game, t_qte *qte, t_guard *guard)
{
	t_vector_2		pos;

	if (qte->loading_frame == FRAME_QTE)
	{
		end_qte(qte, guard, 1);
		return ;
	}
	if (get_pressed(game, qte, guard))
		return ;
	pos.x = guard->guard_pos.x - game->camera->camera_f_pos.x;
	pos.y = guard->guard_pos.y - game->camera->camera_f_pos.y
		- CHUNK_SIZE;
	display_qte_(game, qte, pos);
	qte->pressed = false;
}
