/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_move_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:08:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 16:14:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set the move animation on x (width) axis.
 * 
 * @param look_dir vector_2, representing the direction of the movement.
 * @param sprite sprite to animate.
 */
static void	set_move_animation_on_x(t_vector_2 look_dir, t_sprite *sprite)
{
	if (look_dir.x == 1 && !(sprite->frame == FRAME_MOVEMENT
			|| sprite->frame == FRAME_MOVEMENT + 1))
	{
		sprite->frame = FRAME_MOVEMENT;
	}
	if (look_dir.x == -1 && !(sprite->frame == (FRAME_MOVEMENT * 2)
			|| sprite->frame == (FRAME_MOVEMENT * 2) + 1))
	{
		sprite->frame = (FRAME_MOVEMENT * 2);
	}
}

/**
 * @brief Set the move animation on y (height) axis.
 * 
 * @param look_dir vector_2, representing the direction of the movement.
 * @param sprite sprite to animate.
 */
static void	set_move_animation_on_y(t_vector_2 look_dir, t_sprite *sprite)
{
	if (look_dir.x == 0 && look_dir.y != 0)
	{
		if (look_dir.y == 1 && !(sprite->frame == (FRAME_MOVEMENT * 3)
				|| sprite->frame == (FRAME_MOVEMENT * 3) + 1))
		{
			sprite->frame = (FRAME_MOVEMENT * 3);
		}
		if (look_dir.y == -1 && !(sprite->frame == (FRAME_MOVEMENT * 4)
				|| sprite->frame == (FRAME_MOVEMENT * 4) + 1))
		{
			sprite->frame = (FRAME_MOVEMENT * 4);
		}
	}
}

/**
 * @brief Get the animation of a sprite movement.
 * 
 * @param look_dir vector_2, representing the direction of the movement.
 * @param sprite sprite to animate.
 */
void	move_animation(t_vector_2 look_dir, t_sprite *sprite)
{
	struct timeval	time;
	double			delay;

	if (FRAME_MOVEMENT == 0)
		return ;
	set_move_animation_on_x(look_dir, sprite);
	set_move_animation_on_y(look_dir, sprite);
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
