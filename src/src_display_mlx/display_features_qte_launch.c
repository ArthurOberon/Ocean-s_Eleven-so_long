/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_qte_launch.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:48:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/12 17:51:53 by aoberon          ###   ########.fr       */
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
			&(game->window->map_sprites
			[game->level->nb_cases + e_qte]->sprite_img)[0]);
	else if (delay <= DELAY_QTE)
		launch_qte_loading_part(game, qte, pos_tmp, guard);
	else if (delay <= DELAY_QTE + DELAY_REACTION && is_win == false)
		launch_qte_reaction_time(game, qte, pos_tmp, &is_win);
	else if (delay + is_win <= DELAY_QTE + DELAY_REACTION + 1)
		launch_qte_display_win_or_lose(game, pos_tmp, is_win);
	else
		launch_qte_ending(game, qte, guard, 1);
	qte->pressed = false;
}
