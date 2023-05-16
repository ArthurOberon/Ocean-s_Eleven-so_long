/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_qte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:30:42 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/16 02:52:37 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_qte(t_game *game, t_qte *qte, t_guard *guard)
{
	static bool		is_win = false;
	double			delay;

	if (qte->start_time.tv_sec == 0)
		gettimeofday(&qte->start_time, NULL);
	gettimeofday(&qte->time, NULL);
	delay = (((double)(qte->time.tv_usec - qte->start_time.tv_usec)
				/ CLOCKS_PER_SEC) + qte->time.tv_sec
			- qte->start_time.tv_sec);
	if (delay <= DELAY_QTE)
	{
		put_image_to_image(&game->window->img,
			(t_vector_2){guard->guard_f_pos.x, guard->guard_f_pos.y - CHUNK_SIZE},
		&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[0]);
	}
	else if (delay <= DELAY_QTE + DELAY_REACTION && is_win == false)
	{
		qte->time_to_press = true;
		put_image_to_image(&game->window->img,
			(t_vector_2){guard->guard_f_pos.x, guard->guard_f_pos.y - CHUNK_SIZE},
			&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[1]);
		if (qte->pressed_in_time == true)
		{
			is_win = true;
			return ;
		}
	}
	else if (delay + is_win <= DELAY_QTE + DELAY_REACTION + 1)
	{
		if (is_win == true)
			put_image_to_image(&game->window->img,
			(t_vector_2){guard->guard_f_pos.x, guard->guard_f_pos.y - CHUNK_SIZE},
			&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[2]);
		else
			put_image_to_image(&game->window->img,
				(t_vector_2){guard->guard_f_pos.x, guard->guard_f_pos.y - CHUNK_SIZE},
			&(game->window->map_sprites[game->level->nb_cases + e_qte]->sprite_img)[3]);
	}
	else
	{
		if (is_win == true)
		{
			game->gameplay->nb_collect_remain -= 1;
			guard->is_pickpocketable = false;
		}
		else
			guard->chasing_player = true;
		qte->time_to_press = false;
		qte->pressed_in_time = false;
		qte->is_pickpokecting = false;
		qte->start_time = (struct timeval){0, 0};
	}
}

void	display_qte(t_game *game, t_qte *qte, t_player *player, t_guard *guards)
{
	int	i;

	if (player->player_character != e_thief || qte->is_pickpokecting == false)
	{
		game->gameplay->is_stop = false;
		return ;
	}
	qte->pockpocket_area.x = player->player_pos.x - CHUNK_SIZE;
	qte->pockpocket_area.y = player->player_pos.y - CHUNK_SIZE;
	i = 0;
	if (guards[i].is_alive == true && guards[i].is_pickpocketable == true
		&& is_in_chunks_to_display(game->camera->chunks_to_display,
			game->camera->nb_chunks_in_camera_total, guards[i].guard_pos_tab))
	{
		if (is_inside_area(
				guards[i].guard_f_pos, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE},
			(t_f_vector_2){(double)qte->pockpocket_area.x,
			(double)qte->pockpocket_area.y},
			(t_f_vector_2){(double)qte->pockpocket_size.x,
			(double)qte->pockpocket_size.y}))
		{
			start_qte(game, qte, &guards[i]);
			player->iframes = false;
			game->gameplay->is_stop = true;
		}
		else
			qte->is_pickpokecting = false;
	}
}
