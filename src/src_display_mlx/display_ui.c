/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:08:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/16 18:36:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_heart(t_window *window, t_player *player, t_sprite *sprite)
{
	int	i;

	i = 0;
	while (i < player->hp)
	{
		if (i == 2)
			break ;
		put_image_to_image(&window->img,
			(t_vector_2){WINDOW_WIDTH - CHUNK_SIZE - ((20 - (i * 45))),
			44 - CHUNK_SIZE},
			&(sprite->sprite_img)[sprite->frame]);
		i++;
	}
}

void	display_ui(t_game *game, t_window *window, t_gameplay *gameplay)
{
	display_heart(window, gameplay->player,
		game->window->map_sprites[game->level->nb_cases + e_heart]);
}
