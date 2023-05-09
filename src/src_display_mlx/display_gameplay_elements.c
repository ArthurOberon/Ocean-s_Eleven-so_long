/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gameplay_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/09 13:28:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_gameplay_elements(t_game *game, t_gameplay *gameplay,
	t_window *window)
{
	if (gameplay->nb_collect == 0)
		window->map_sprites[game->level->exit_pos] = game->assets->collect;
	display_bomb(gameplay->player, &gameplay->player->bomb, game, window);
}
