/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_features_qte.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:47:58 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 14:40:02 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief End the qte, set all the qte struct values to default.
 * 
 * @param qte qte struct, to set the values to default.
 * @param guard guard struct,
 * to set the chasing_player value to true when the qte is lost.
 * @param not_pressed_flag int, 1 if the qte is lost, 0 otherwise.
 */
void	end_qte(t_qte *qte, t_guard *guard, int not_pressed_flag)
{
	if (not_pressed_flag)
	{
		guard->chasing_player = true;
	}
	gettimeofday(&guard->last_time, NULL);
	qte->pressed = false;
	qte->pressed_within_qte = false;
	qte->is_pickpocketing = false;
	qte->loading_frame = 1;
	qte->loading_value = QTE_CHUNK_SIZE;
	qte->start_time = (struct timeval){0, 0};
}

/**
 * @brief Process the end of the qte, if the player pressed during the qte.
 * Depending on the loading_frame value, the qte is won or lost.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param qte qte struct, used to get the loading_frame value.
 * @param guard guard struct.
 * @return int 0 if the player didn't pressed during the qte, 1 otherwise.
 */
int	get_pressed(t_game *game, t_qte *qte, t_guard *guard)
{
	if (!qte->pressed_within_qte)
		return (0);
	if ((qte->loading_frame == 1 && !QTE_EASY) || qte->loading_frame == 3)
	{
		end_qte(qte, guard, 1);
	}
	else if (qte->loading_frame == 2)
	{
		if (!STRICT_CORRECTION)
			collected_one_collectible(game, game->gameplay,
				-1, COLLECTED_ON_GUARD);
		guard->is_pickpocketable = false;
	}
	end_qte(qte, guard, 0);
	return (1);
}
