/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_guards_turn_fov.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:25:16 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 22:09:06 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Turn the guard look direction clockwise.
 * 
 * @param guard guard struct, change his look direction.
 */
static void	standard_change_guard_direction(t_guard *guard)
{
	if (guard->guard_look_dir.x == -1 && guard->guard_look_dir.y == 0)
	{
		guard->guard_look_dir.x = 0;
		guard->guard_look_dir.y = -1;
	}
	else if (guard->guard_look_dir.x == 0 && guard->guard_look_dir.y == -1)
	{
		guard->guard_look_dir.x = 1;
		guard->guard_look_dir.y = 0;
	}
	else if (guard->guard_look_dir.x == 1 && guard->guard_look_dir.y == 0)
	{
		guard->guard_look_dir.x = 0;
		guard->guard_look_dir.y = 1;
	}
	else if (guard->guard_look_dir.x == 0 && guard->guard_look_dir.y == 1)
	{
		guard->guard_look_dir.x = -1;
		guard->guard_look_dir.y = 0;
	}
}

/**
 * @brief Turn the guard direction, clockwise if he does not look diagonally
 * (meaning !(x != 0 && y != 0)),
 * else (after a purchase on diagonals) set randomly
 * one of the axe at 0 and the let the other at his current value.
 * 
 * @param guard guard struct, set up his look direction.
 */
static void	change_guard_direction(t_guard *guard)
{
	if (guard->chasing_player == true || guard->is_in_player == true)
		return ;
	if (!(guard->guard_look_dir.x != 0 && guard->guard_look_dir.y != 0))
	{
		standard_change_guard_direction(guard);
	}
	else
	{
		if (rand() % 101 > 50)
		{
			guard->guard_look_dir.x = 0;
		}
		else
		{
			guard->guard_look_dir.y = 0;
		}
	}
}

/**
 * @brief Turn the guard direction after a delay.
 * 
 * @param guard guard struct, set up his direction.
 */
void	turn_guards(t_guard *guard)
{
	double			delay;

	gettimeofday(&guard->time, NULL);
	delay = (((double)(guard->time.tv_usec - guard->last_time.tv_usec)
				/ CLOCKS_PER_SEC) + guard->time.tv_sec
			- guard->last_time.tv_sec);
	if (delay >= DELAY_TURN_GUARD)
	{
		change_guard_direction(guard);
		set_guard_fov_direction(guard);
		guard->last_time = guard->time;
	}
}
