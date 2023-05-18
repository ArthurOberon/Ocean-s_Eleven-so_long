/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_guards.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:28:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/18 22:36:21 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_one_guard(t_window *window, t_guard guard, t_sprite *sprite)
{
// if ((guard.guard_pos.x + CHUNK_SIZE < window->img.size.x
			// && guard.guard_pos.y + CHUNK_SIZE < window->img.size.y)
		// && (guard.guard_pos.x > 0 && guard.guard_pos.y > 0))
	// printf("pos : [%d]\n", guard.guard_pos_tab);
		put_image_to_image(&window->img, guard.guard_pos,
			&(sprite->sprite_img)[sprite->frame]);
}

// fov -> Field Of View
static void	display_one_guard_fov(t_window *window, t_guard guard,
	t_sprite *sprite, t_player *player)
{
	if ((guard.guard_fov_pos_1.x + CHUNK_SIZE < window->img.size.x
			&& guard.guard_fov_pos_1.y + CHUNK_SIZE < window->img.size.y)
		&& (guard.guard_fov_pos_1.x > 0 && guard.guard_fov_pos_1.y > 0))
		put_image_to_image(&window->img, guard.guard_fov_pos_1,
			&(sprite->sprite_img)[sprite->frame]);
	if (player->player_character != e_eater)
	{
		if ((guard.guard_fov_pos_2.x + CHUNK_SIZE < window->img.size.x
				&& guard.guard_fov_pos_2.y + CHUNK_SIZE < window->img.size.y)
			&& (guard.guard_fov_pos_2.x > 0 && guard.guard_fov_pos_2.y > 0))
			put_image_to_image(&window->img, guard.guard_fov_pos_2,
				&(sprite->sprite_img)[sprite->frame]);
	}
}

static void	change_guard_f_direction(t_guard *guard)
{
	if (guard->chasing_player == true || guard->is_in_player == true)
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
	else
	{
		if (rand() % 101 > 50)
			guard->guard_look_dir.x = 0;
		else
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
		change_guard_f_direction(guard);
		set_guard_fov_direction(guard);
		guard->last_time = guard->time;
	}
}

void	display_guards(t_game *game, t_gameplay *gameplay, t_window *window,
	t_guard *guards)
{
	int			i;
	t_vector_2	pos_tmp;

	i = 0;
	while (i < gameplay->nb_guard)
	{
		if (guards[i].is_alive == true
			&& is_in_chunks_to_display(game->camera->chunks_to_display,
				game->camera->nb_chunks_in_camera_total,
				guards[i].guard_pos_tab))
		{
			pos_tmp = guards[i].guard_pos;
			guards[i].guard_pos.x -= game->camera->camera_f_pos.x;
			guards[i].guard_pos.y -= game->camera->camera_f_pos.y;
			guards[i].guard_pos.x -= (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_X)) / 2;
			guards[i].guard_pos.y -= (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_Y)) / 2;
			set_guard_fov_direction(&guards[i]);
			if (gameplay->is_stop == false)
				turn_guards(&guards[i]);
			display_one_guard(window, guards[i],
				window->map_sprites[game->level->nb_cases + e_guards]);
			display_one_guard_fov(window, guards[i],
				window->map_sprites[game->level->nb_cases + e_guard_fov],
				gameplay->player);
			guards[i].guard_pos = pos_tmp;
			set_guard_fov_direction(&guards[i]);
		}
		i++;
	}
}
