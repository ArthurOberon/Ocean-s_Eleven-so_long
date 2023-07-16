/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:06:15 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 00:16:36 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set the move player animation on x (width) axis.
 * 
 * @param player player struct, used to get the player_look_dir.
 * @param sprite sprite to animate.
 */
static void	set_move_player_animation_on_x(t_player *player, t_sprite *sprite)
{
	if (player->player_look_dir.x == 1
		&& !(sprite->frame == FRAME_MOVEMENT
			|| sprite->frame == FRAME_MOVEMENT + 1))
	{
		sprite->frame = FRAME_MOVEMENT;
	}
	if (player->player_look_dir.x == -1
		&& !(sprite->frame == (FRAME_MOVEMENT * 2)
			|| sprite->frame == (FRAME_MOVEMENT * 2) + 1))
	{
		sprite->frame = (FRAME_MOVEMENT * 2);
	}
}

/**
 * @brief Set the move player animation on y (height) axis.
 * 
 * @param player player struct, used to get the player_look_dir.
 * @param sprite sprite to animate.
 */
static void	set_move_player_animation_on_y(t_player *player, t_sprite *sprite)
{
	if (player->player_look_dir.x == 0 && player->player_look_dir.y != 0)
	{
		if (player->player_look_dir.y == 1
			&& !(sprite->frame == (FRAME_MOVEMENT * 3)
				|| sprite->frame == (FRAME_MOVEMENT * 3) + 1))
		{
			sprite->frame = (FRAME_MOVEMENT * 3);
		}
		if (player->player_look_dir.y == -1
			&& !(sprite->frame == (FRAME_MOVEMENT * 4)
				|| sprite->frame == (FRAME_MOVEMENT * 4) + 1))
		{
			sprite->frame = (FRAME_MOVEMENT * 4);
		}
	}
}

/**
 * @brief Get the animation of the player movement.
 * 
 * @param player player struct, used to get the player_look_dir.
 * @param sprite sprite to animate.
 */
void	move_player_animation(t_player *player, t_sprite *sprite)
{
	struct timeval	time;
	double			delay;

	if (FRAME_MOVEMENT == 1)
		return ;
	set_move_player_animation_on_x(player, sprite);
	set_move_player_animation_on_y(player, sprite);
	if (sprite->last_time.tv_sec == 0)
		gettimeofday(&sprite->last_time, NULL);
	gettimeofday(&time, NULL);
	delay = (((double)(time.tv_usec - sprite->last_time.tv_usec)
				/ CLOCKS_PER_SEC) + time.tv_sec - sprite->last_time.tv_sec);
	if (delay >= 1)
	{
		sprite->last_time = time;
		sprite->frame = (sprite->frame + 1)
			- (FRAME_MOVEMENT * ((sprite->frame) % FRAME_MOVEMENT));
	}
}
