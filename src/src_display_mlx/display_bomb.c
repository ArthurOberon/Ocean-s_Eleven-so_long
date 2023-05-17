/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bomb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:05:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/17 15:35:57 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_bomb(t_player *player, t_bomb *bomb, t_game *game,
	t_window *window)
{
	double			delay;
	t_vector_2		pos_tmp;

	if (bomb->bomb_plant <= 0
		|| (player->player_character != e_bomber && bomb->bomb_chunk_pos == -1))
		return ;
	get_bomb_position(bomb, player, game);
	pos_tmp = bomb->bomb_pos;
	bomb->bomb_pos.x = bomb->bomb_pos.x - game->camera->camera_f_pos.x;
	bomb->bomb_pos.y = bomb->bomb_pos.y - game->camera->camera_f_pos.y;
	put_image_to_image(&window->img, bomb->bomb_pos,
		&(window->map_sprites[game->level->nb_cases + e_dynamite]->sprite_img)
	[bomb->bomb_plant - 1]);
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
	bomb->bomb_pos = pos_tmp;
}
