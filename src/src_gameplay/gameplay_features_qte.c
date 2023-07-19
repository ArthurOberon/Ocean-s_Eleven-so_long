/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_features_qte.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:47:58 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 19:22:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// not commented ALL

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
		collected_one_collectible(game, game->gameplay, -1, COLLECTED_ON_GUARD);
		guard->is_pickpocketable = false;
	}
	end_qte(qte, guard, 0);
	return (1);
}
