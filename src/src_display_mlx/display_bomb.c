/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bomb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:05:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/15 15:06:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_bomb(t_player *player, t_bomb *bomb, t_game *game,
	t_window *window)
{
	double			delay;

	if (bomb->bomb_plant <= 0
		|| (player->player_character != e_bomber && bomb->bomb_chunk_pos == -1))
		return ;
	get_bomb_position(bomb, player, game);
	put_image_to_image(window, bomb->bomb_pos,
		&(window->map_sprites[game->level->nb_cases]->sprite_img)[0]);
	gettimeofday(&bomb->time, NULL);
	delay = (((double)(bomb->time.tv_usec - bomb->last_time.tv_usec)
				/ CLOCKS_PER_SEC) + bomb->time.tv_sec
			- bomb->last_time.tv_sec);
	if (delay >= BOMB_TIMING)
	{
		make_bomb_explode(game, *bomb);
		bomb->bomb_total -= bomb->bomb_plant;
		bomb->bomb_plant = 0;
		bomb->bomb_chunk_pos = -1;
		bomb->bomb_pos.x = -1;
		bomb->bomb_pos.y = -1;
	}
}
