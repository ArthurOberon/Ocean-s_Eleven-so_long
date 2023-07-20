/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_qte_main.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:30:42 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 09:16:39 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief check if the qte can be launched for one guard.
 * 
 * @param game game struct, used te get the camera and the gameplay struct.
 * @param qte qte struct, used to launch the qte.
 * @param player player struct, used to set up his iframes variable.
 * @param guard guard struct,
 * used to check if the guard complete the conditions to launch the qte.
 * @return int 1 when the qte is in progress, 0 otherwise.
 */
static int	check_qte_compared_to_one_guard(t_game *game, t_qte *qte,
	t_player *player, t_guard *guard)
{
	if (guard->is_alive == true && guard->is_pickpocketable == true
		&& !guard->chasing_player
		&& is_in_chunks_to_display(game->camera->chunks_to_display,
			game->camera->nb_chunks_in_camera_total, guard->guard_pos_tab))
	{
		if (is_inside_area(
				guard->guard_f_pos, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE},
			(t_f_vector_2){(double)qte->pickpocket_area.x,
			(double)qte->pickpocket_area.y},
			(t_f_vector_2){(double)qte->pickpocket_size.x,
			(double)qte->pickpocket_size.y}))
		{
			game->gameplay->is_stop = true;
			launch_qte(game, qte, guard);
			player->iframes = false;
			return (1);
		}
	}
	return (0);
}

/**
 * @brief Display the qte if the player character is thief and if a guard
 * is in the qte_area.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param qte qte struct, used to launch the qte.
 * @param player player struct, used to check if the player character is thief
 * and to get the position of the qte.
 * @param guards guards struct,
 * tab of guards used to check if one of them is in the qte_area.
 * @return int 1 when the qte is in progress, 0 otherwise.
 */
int	display_qte(t_game *game, t_qte *qte, t_player *player, t_guard *guards)
{
	int	i;

	if (player->player_character != e_thief || qte->is_pickpocketing == false)
	{
		if (game->gameplay->dialogue == NULL)
			game->gameplay->is_stop = false;
		else
			game->gameplay->is_stop
				= game->gameplay->dialogue->text_box->is_display;
		return (0);
	}
	qte->pickpocket_area.x = player->player_pos.x - CHUNK_SIZE;
	qte->pickpocket_area.y = player->player_pos.y - CHUNK_SIZE;
	i = 0;
	while (i < game->gameplay->nb_guard)
	{
		if (check_qte_compared_to_one_guard(game, qte, player, &guards[i]))
			return (1);
		i++;
	}
	qte->is_pickpocketing = false;
	return (0);
}
