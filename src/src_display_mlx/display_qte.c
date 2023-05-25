/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_qte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:30:42 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/25 17:48:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	start_qte(t_game *game, t_qte *qte, t_guard *guard)
{
	static bool		is_win = false;
	t_vector_2		pos_tmp;
	double			delay;

	if (qte->start_time.tv_sec == 0)
		gettimeofday(&qte->start_time, NULL);
	gettimeofday(&qte->time, NULL);
	delay = (((double)(qte->time.tv_usec - qte->start_time.tv_usec)
				/ CLOCKS_PER_SEC) + qte->time.tv_sec
			- qte->start_time.tv_sec);

	pos_tmp.x = guard->guard_pos.x - game->camera->camera_f_pos.x;
	pos_tmp.y = guard->guard_pos.y - game->camera->camera_f_pos.y - CHUNK_SIZE;
	if (delay <= 1)
		put_image_to_image(&game->window->img, pos_tmp,
			&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[0]);
	else if (delay <= DELAY_QTE)
	{
		put_image_to_image(&game->window->img, pos_tmp,
			&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[1]);
		if (qte->pressed == true && delay >= 1)
		{
			put_image_to_image(&game->window->img, pos_tmp,
				&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[4]);
			guard->chasing_player = true;
			qte->time_to_press = false;
			qte->pressed = false;
			qte->is_pickpocketing = false;
			qte->start_time = (struct timeval){0, 0};
		}
	}
	else if (delay <= DELAY_QTE + DELAY_REACTION && is_win == false)
	{
		qte->time_to_press = true;
		put_image_to_image(&game->window->img, pos_tmp,
			&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[2]);
		if (qte->pressed_in_time == true)
		{
			is_win = true;
			return ;
		}
	}
	else if (delay + is_win <= DELAY_QTE + DELAY_REACTION + 1)
	{
		if (is_win == true)
			put_image_to_image(&game->window->img, pos_tmp,
				&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[3]);
		else
		{
			put_image_to_image(&game->window->img, pos_tmp,
				&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[4]);
		}
	}
	else
	{
		if (is_win == true)
		{
			game->gameplay->nb_collect_get += 1;
			game->gameplay->nb_collect_remain -= 1;
			game->gameplay->display_plus_one = true;
			guard->is_pickpocketable = false;
		}
		else
			guard->chasing_player = true;
		qte->time_to_press = false;
		qte->pressed_in_time = false;
		qte->is_pickpocketing = false;
		qte->start_time = (struct timeval){0, 0};
	}
	qte->pressed = false;
}

void	display_qte(t_game *game, t_qte *qte, t_player *player, t_guard *guards)
{
	int	i;

	if (player->player_character != e_thief || qte->is_pickpocketing == false)
	{
		game->gameplay->is_stop = game->gameplay->text_box.is_display;
		return ;
	}
	qte->pickpocket_area.x = player->player_pos.x - CHUNK_SIZE;
	qte->pickpocket_area.y = player->player_pos.y - CHUNK_SIZE;
	i = 0;
	while (i < game->gameplay->nb_guard)
	{
		if (guards[i].is_alive == true && guards[i].is_pickpocketable == true
			&& !guards[i].chasing_player
			&& is_in_chunks_to_display(game->camera->chunks_to_display,
				game->camera->nb_chunks_in_camera_total, guards[i].guard_pos_tab))
		{
			if (is_inside_area(
					guards[i].guard_f_pos, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE},
				(t_f_vector_2){(double)qte->pickpocket_area.x,
				(double)qte->pickpocket_area.y},
				(t_f_vector_2){(double)qte->pickpocket_size.x,
				(double)qte->pickpocket_size.y}))
			{
				game->gameplay->is_stop = true;
				start_qte(game, qte, &guards[i]);
				player->iframes = false;
				return ;
			}
		}
		i++;
	}
	qte->is_pickpocketing = false;
}
