/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_guards.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:28:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 15:00:05 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_one_guard(t_window *window, t_guard guard, t_sprite *sprite)
{
	put_image_to_image(window, guard.guard_pos,
		&(sprite->sprite_img)[sprite->frame]);
}

// fov -> Field Of View
static void	display_one_guard_fov(t_window *window, t_guard guard,
	t_sprite *sprite)
{
	put_image_to_image(window, guard.guard_fov_pos_1,
		&(sprite->sprite_img)[sprite->frame]);
	put_image_to_image(window, guard.guard_fov_pos_2,
		&(sprite->sprite_img)[sprite->frame]);
}

static void	change_guard_direction(t_guard *guard)
{
	if (guard->following_player == true)
		return ;
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

static void	turn_guards(t_guard *guard)
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

void	display_guards(t_game *game, t_gameplay *gameplay, t_window *window,
	t_guard *guards)
{
	int	i;

	i = 0;
	while (i < gameplay->nb_guard)
	{
		if (guards[i].is_alive == true
			&& is_in_chunks_to_display(game->camera->chunks_to_display,
				game->camera->nb_chunks_in_camera_total,
				guards[i].guard_pos_tab))
		{
			turn_guards(&guards[i]);
			display_one_guard(window, guards[i],
				window->map_sprites[game->level->nb_cases + 1]);
			display_one_guard_fov(window, guards[i],
				window->map_sprites[game->level->nb_cases + 1]);
		}
		i++;
	}
}
