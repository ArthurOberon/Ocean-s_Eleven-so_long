/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:10:48 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/02 12:16:40 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	text_box_events(t_game *game, t_gameplay *gameplay)
{
	if (gameplay->nb_collect_remain == 1 && game->level->nb_collect != 1)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_remain_one_collectible], true);
	}
	if (gameplay->nb_collect_remain == 0)
	{
		add_text(game, &gameplay->texts_box_list,
			&gameplay->texts[e_text_remain_zero_collectible], true);
	}
}
