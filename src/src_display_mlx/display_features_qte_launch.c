/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_qte_launch.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:48:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 20:18:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Launches the qte loading part,
 * meaning the part where the player has to not press the button.
 * 
 * @param game game struct, used to get the window and level structs.
 * @param qte qte struct, used to manage the qte process.
 * @param pos_tmp position to display the qte.
 * @param guard guard struct, used to set up depending on the course of the qte.
 */
static void	launch_qte_loading_part(t_game *game, t_qte *qte,
	t_vector_2 pos_tmp, t_guard *guard)
{
	put_image_to_image(&game->window->img, pos_tmp,
		&(game->window->map_sprites
		[game->level->nb_cases + e_qte]->sprite_img)[1]);
	if (qte->pressed == true)
	{
		put_image_to_image(&game->window->img, pos_tmp,
			&(game->window->map_sprites
			[game->level->nb_cases + e_qte]->sprite_img)[4]);
		guard->chasing_player = true;
		qte->time_to_press = false;
		qte->pressed = false;
		qte->is_pickpocketing = false;
		qte->start_time = (struct timeval){0, 0};
	}
}

/**
 * @brief Launches the qte reaction time part,
 * meaning the part where the player has to press the button.
 * 
 * @param game game struct, used to get the window and level structs.
 * @param qte qte struct, used to manage the qte process.
 * @param pos_tmp position to display the qte.
 * @param is_win bool, used to save if the player won (by pressing) or not.
 */
static void	launch_qte_reaction_time(t_game *game, t_qte *qte,
	t_vector_2 pos_tmp, bool *is_win)
{
	qte->time_to_press = true;
	put_image_to_image(&game->window->img, pos_tmp,
		&(game->window->map_sprites
		[game->level->nb_cases + e_qte]->sprite_img)[2]);
	if (qte->pressed_in_time == true)
	{
		*is_win = true;
		return ;
	}
}

/**
 * @brief Launches the qte display win or lose part,
 * meaning the part where is displayed if the player win or lose the qte.
 * 
 * @param game game struct, used to get the window and level structs.
 * @param pos_tmp position to display the qte.
 * @param is_win bool, used to know if the player won (by pressing) or not.
 */
static void	launch_qte_display_win_or_lose(t_game *game, t_vector_2 pos_tmp,
	bool is_win)
{
	if (is_win == true)
		put_image_to_image(&game->window->img, pos_tmp,
			&(game->window->map_sprites
			[game->level->nb_cases + e_qte]->sprite_img)[3]);
	else
	{
		put_image_to_image(&game->window->img, pos_tmp,
			&(game->window->map_sprites
			[game->level->nb_cases + e_qte]->sprite_img)[4]);
	}
}

/**
 * @brief Launches the qte ending part,
 * meaning the part where the game is set up
 * depending on the course of the qte (win or lose).
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param qte qte struct, used to set up the end of the qte.
 * @param guard guard struct, used to set up guard
 * depending on the course of the qte.
 * @param is_win bool, used to know if the player won (by pressing) or not.
 */
static void	launch_qte_ending(t_game *game, t_qte *qte, t_guard *guard,
	bool is_win)
{
	if (is_win == true)
	{
		collected_one_collectible(game, game->gameplay, -1, COLLECTED_ON_GUARD);
		guard->is_pickpocketable = false;
	}
	else
		guard->chasing_player = true;
	qte->time_to_press = false;
	qte->pressed_in_time = false;
	qte->is_pickpocketing = false;
	qte->start_time = (struct timeval){0, 0};
}




void	launch_qte_(t_game *game, t_qte *qte, t_guard *guard);

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
	// static bool		is_win = false;
	// t_vector_2		pos_tmp;
	// double			delay;

	launch_qte_(game, qte, guard);
	// if (qte->start_time.tv_sec == 0)
	// 	gettimeofday(&qte->start_time, NULL);
	// gettimeofday(&qte->time, NULL);
	// delay = (((double)(qte->time.tv_usec - qte->start_time.tv_usec)
	// 			/ CLOCKS_PER_SEC) + qte->time.tv_sec
	// 		- qte->start_time.tv_sec);
	// pos_tmp.x = guard->guard_pos.x - game->camera->camera_f_pos.x;
	// pos_tmp.y = guard->guard_pos.y - game->camera->camera_f_pos.y - CHUNK_SIZE;
	// if (delay <= 1)
	// 	put_image_to_image(&game->window->img, pos_tmp,
	// 		&(game->window->map_sprites
	// 		[game->level->nb_cases + e_qte]->sprite_img)[0]);
	// else if (delay <= DELAY_QTE)
	// 	launch_qte_loading_part(game, qte, pos_tmp, guard);
	// else if (delay <= DELAY_QTE + DELAY_REACTION && is_win == false)
	// 	launch_qte_reaction_time(game, qte, pos_tmp, &is_win);
	// else if (delay + is_win <= DELAY_QTE + DELAY_REACTION + 1)
	// 	launch_qte_display_win_or_lose(game, pos_tmp, is_win);
	// else
	// 	launch_qte_ending(game, qte, guard, 1);
	// qte->pressed = false;
}


static void	put_image_to_image_with_limit(t_img *window_img, t_vector_2 pos,
	t_img *img, t_vector_2 *limit)
{
	int			i;
	int			j;
	__uint32_t	pixel;

	j = limit[0].y;
	while (j < img->size.y - limit[1].y)
	{
		i = limit[0].x;
		while (i < img->size.x - limit[1].x)
		{
			pixel = get_color_pixel(img, i, j);
			if ((pixel >> 24) != 0xFF)
				img_pix_put(window_img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}


static void	qte_part_1(t_game *game, t_qte *qte,
	t_vector_2 pos_tmp, t_guard *guard)
{
	// int			i;
	// int			j;
	// __uint32_t	pixel;

	// i = 0;
	// printf("size.x = %d\n", game->assets->qte->sprite_img->size.x);
	// while (i < game->assets->qte->sprite_img->size.x)
	// {
	// 	pixel = get_color_pixel(
	// 		&(game->assets->qte->sprite_img)[qte->loading_frame], i, 0);
	// 	if (pixel >> 24 == 0xFF)
	// 	{
	// 		// printf("pixel transparent i = %d\n", i);
	// 		i++;
	// 	}
	// 	else
	// 		break ;
		// printf("i = %d pixel = %d\n", i, (pixel >> 24));
		// i++;
	// }
	// exit (0);
	// j = qte->loading_value;
	// while (j > 0)
	// {
	// 	pixel = get_color_pixel(
	// 		&(game->assets->qte->sprite_img)[qte->loading_frame], j, 0);
	// 	if (pixel >> 24 == 0xFF)
	// 	{
	// 		printf("pixel transparent j = %d\n", i);
	// 	}
	// 	printf("j = %d pixel = %d\n", i, (pixel >> 24));
	// 	i--;
	// }
	// exit(0);
	
	// 	printf("pixel = %d\n", (pixel >> 24));
	// 	if ((pixel >> 24) == 0xFF)
	// 	{
	// 		printf("----------------------- pixel transparent i = %d\n", i);
	// 		// return ;
	// 		i--;
	// 	}
	// 	else
	// 		break ;
	// }
	// printf("i = %d | qte->loading_value = %d\n", i, qte->loading_value);
	// qte->loading_value = i;
	// if (qte->loading_value == 0)
	// 	return ;



	// --------------- get_start_pixel ---------------
	int	start_pixel;
	__uint32_t	pixel;
	
	start_pixel = 0;
	while (start_pixel < game->assets->qte->sprite_img->size.x)
	{
		pixel = get_color_pixel(
			&(game->assets->qte->sprite_img)[qte->loading_frame], start_pixel, 0);
		if (pixel >> 24 == 0xFF)
		{
			// printf("pixel transparent start_pixel = %d\n", start_pixel);
			start_pixel++;
		}
		else
			break ;
	}
	// printf("start_pixel = %d\n", start_pixel);
	if (start_pixel != 0 && qte->loading_value > start_pixel)
		qte->loading_value = game->assets->qte->sprite_img->size.x - start_pixel;
	// --------------- get_start_pixel ---------------


	// --------------- get_end_pixel ---------------
	
	int	end_pixel;

	end_pixel = game->assets->qte->sprite_img->size.x - 1;
	while (end_pixel > 0)
	{
		pixel = get_color_pixel(
			&(game->assets->qte->sprite_img)[qte->loading_frame], end_pixel, 0);
		// printf("%d pixel = %d\n", end_pixel, (pixel >> 24));
		if (pixel >> 24 == 0xFF)
		{
			// printf("pixel transparent end_pixel = %d\n", end_pixel);
			end_pixel--;
		}
		else
			break ;
	}
	end_pixel = game->assets->qte->sprite_img->size.x - end_pixel;
	printf("end_pixel = %d\n", end_pixel);
	if (end_pixel != game->assets->qte->sprite_img->size.x
		&& qte->loading_value < end_pixel)
	{
		qte->loading_value = 0;
		return ;
	}
	// --------------- get_end_pixel ---------------




	if (qte->loading_frame == 1 && qte->start_time.tv_sec == 0)
		put_image_to_image(&game->window->img, pos_tmp,
			&(game->assets->qte->sprite_img)[0]);
	put_image_to_image_with_limit(&game->window->img, pos_tmp,
		&(game->assets->qte->sprite_img)[qte->loading_frame],
		(t_vector_2[2]){{start_pixel, 0}, {qte->loading_value, 0}});
	// printf("DISPLAY BAR -----------------------\n");
}

void	launch_qte_(t_game *game, t_qte *qte, t_guard *guard)
{
	static bool		is_win = false;
	t_vector_2		pos_tmp;
	double			delay;

	if (qte->loading_frame == 4)
	{
		return ;
	}
	if (qte->start_time.tv_sec == 0)
		gettimeofday(&qte->start_time, NULL);
	gettimeofday(&qte->time, NULL);
	delay = (((double)(qte->time.tv_usec - qte->start_time.tv_usec)
				/ CLOCKS_PER_SEC) + qte->time.tv_sec
			- qte->start_time.tv_sec);
	pos_tmp.x = guard->guard_pos.x - game->camera->camera_f_pos.x;
	pos_tmp.y = guard->guard_pos.y - game->camera->camera_f_pos.y
		- CHUNK_SIZE;
	printf("delay = %f\n", delay);
	if (delay >= 0.05)
	{
		printf("qte->loading_value -= 1\n");
		qte->loading_value -= 1;
		qte->start_time = (struct timeval){0, 0};
	}

	qte_part_1(game, qte, pos_tmp, guard);
	if (qte->loading_value == 0)
	{
		printf("NEW FRAME!\n");
		qte->loading_frame += 1;
		qte->loading_value = (CHUNK_SIZE * 2);
	}
	printf("qte->loading_value = %d\n", qte->loading_value);
	printf("qte->loading_frame = %d\n\n", qte->loading_frame);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->window->img.mlx_img, 0, 0);
	qte->pressed = false;
	printf("=====================================================\n\n");
}
