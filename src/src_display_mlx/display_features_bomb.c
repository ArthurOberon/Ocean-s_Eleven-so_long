/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_bomb.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:05:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 14:24:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief display the explosion of the bomb with a pos shift (pos_tmp)
 * based on the camera position.
 * 
 * @param camera camera struct, used to get the camera position.
 * @param window window struct, used to display the explosion in.
 * @param bomb bomb struct, used to get the explosion position.
 * @param sprite sprite struct, used to get the explosion sprite.
 */
static void	display_explosition(t_camera *camera, t_window *window, t_bomb bomb,
	t_sprite *sprite)
{
	int			i;
	t_vector_2	pos_tmp;

	i = 0;
	while (bomb.explosion_pos[i].x != -1)
	{
		pos_tmp.x = bomb.explosion_pos[i].x - camera->camera_f_pos.x;
		pos_tmp.y = bomb.explosion_pos[i].y - camera->camera_f_pos.y;
		display_one_sprite_with_transparency(window, sprite, pos_tmp);
		i++;
	}
}

/**
 * @brief wait for the bomb to explode, then display the explosion.
 * 
 * @param bomb bomb struct, used to get the bomb info.
 * @param game game struct, used to get the camera and the explosion sprite.
 * @param window window struct, used to display the explosion in.
 */
static void	get_bomb_explosion(t_bomb *bomb, t_game *game, t_window *window)
{
	double		delay;

	if (bomb->explosion_pos[0].x == -1)
		return ;
	if (bomb->start_time_explosion.tv_sec == 0)
		gettimeofday(&bomb->start_time_explosion, NULL);
	gettimeofday(&bomb->time_explosion, NULL);
	delay = (((double)(bomb->time_explosion.tv_usec
					- bomb->start_time_explosion.tv_usec)
				/ CLOCKS_PER_SEC) + bomb->time_explosion.tv_sec
			- bomb->start_time_explosion.tv_sec);
	if (delay <= DELAY_BOMB_EXPLOSION)
	{
		display_explosition(game->camera, window, *bomb,
			game->assets->explosion);
	}
	else
	{
		init_explosion_pos(game, bomb, false);
		bomb->start_time_explosion = (struct timeval){0, 0};
	}
}

/**
 * @brief display the bomb sprite.
 * 
 * @param bomb bomb struct, used for the bomb position.
 * @param game game struct, used for the camera position.
 * @param window window struct, used to display the bomb in.
 */
static void	display_bomb_sprite(t_bomb *bomb, t_game *game, t_window *window)
{
	t_sprite		*sprite;
	t_vector_2		pos_tmp;

	pos_tmp = bomb->bomb_pos;
	sprite = game->assets->dynamite;
	bomb->bomb_pos.x = bomb->bomb_pos.x - game->camera->camera_f_pos.x;
	bomb->bomb_pos.y = bomb->bomb_pos.y - game->camera->camera_f_pos.y;
	sprite->frame = bomb->bomb_plant - 1;
	display_one_sprite_with_transparency(window, sprite, bomb->bomb_pos);
	sprite->frame = 0;
	bomb->bomb_pos = pos_tmp;
}

/**
 * @brief display bomb and their explosion.
 * 
 * @param player player struct, used to get the player position.
 * @param bomb bomb struct, contain all the info of the bomb.
 * @param game game struct, contain all the info of the all game.
 * @param window window struct, used to display the bomb in.
 */
void	display_bomb(t_player *player, t_bomb *bomb, t_game *game,
	t_window *window)
{
	double			delay;

	get_bomb_explosion(bomb, game, window);
	if (bomb->bomb_plant <= 0
		|| (player->player_character != e_bomber && bomb->bomb_chunk_pos == -1))
		return ;
	set_bomb_position(bomb, player, game);
	display_bomb_sprite(bomb, game, window);
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
