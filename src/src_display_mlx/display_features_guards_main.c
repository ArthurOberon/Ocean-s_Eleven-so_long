/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_guards_main.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:28:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/13 19:18:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Display one guard.
 * 
 * @param window window struct, used to display on.
 * @param guard guard struct, used to get the guard position.
 * @param sprite sprite struct, used to get the sprite of the guard.
 */
static void	display_one_guard(t_window *window, t_guard guard, t_sprite *sprite)
{
	// update_frame(sprite);
	display_one_sprite_with_transparency(window, sprite, guard.guard_pos);
}

/**
 * @brief Display both field of view (fov) of a guard.
 * (Only display the first fov if the player character is eater.)
 * 
 * @param window window struct, used to display on.
 * @param guard guard struct, used to get the fov position.
 * @param sprite sprite struct, used to get the sprite of the fov.
 * @param player player struct, used to check if the player character is eater.
 */
static void	display_one_guard_fov(t_window *window, t_guard guard,
	t_sprite *sprite, t_player *player)
{
	display_one_sprite_with_transparency(window, sprite, guard.guard_fov_pos_1);
	if (player->player_character != e_eater)
	{
		display_one_sprite_with_transparency(window, sprite,
			guard.guard_fov_pos_2);
	}
}

/**
 * @brief  Get the display position of the guard in the camera view.
 * Make a shift of position to display compared to the camera position
 * and his ratio size.
 * 
 * @param game game struct, used to get the camera struct.
 * @param guard guard struct, set up his size.
 * @return t_vector_2 the true position of the guard in the level,
 * set up the guard position a this size after the display.
 */
static t_vector_2	get_display_guard_pos(t_game *game, t_guard *guard)
{
	t_vector_2	true_pos;

	true_pos = guard->guard_pos;
	guard->guard_pos.x -= game->camera->camera_f_pos.x;
	guard->guard_pos.y -= game->camera->camera_f_pos.y;
	guard->guard_pos.x -= (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_X)) / 2;
	guard->guard_pos.y -= (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_Y)) / 2;
	set_guard_fov_direction(guard);
	return (true_pos);
}

/**
 * @brief Display guards that are in the camera view.
 * 
 * @param game game struct, used to get the camera and level struct.
 * @param gameplay gameplay struct,
 * used to get player struct and is_stop variable.
 * @param window window struct, used to display on.
 * @param guards guards struct, used to get guards positions and status.
 */
void	display_guards(t_game *game, t_gameplay *gameplay, t_window *window,
	t_guard *guards)
{
	int			i;
	t_vector_2	true_pos;

	i = 0;
	while (i < gameplay->nb_guard)
	{
		if (guards[i].is_alive == true
			&& is_in_chunks_to_display(game->camera->chunks_to_display,
				game->camera->nb_chunks_in_camera_total,
				guards[i].guard_pos_tab))
		{
			true_pos = get_display_guard_pos(game, &guards[i]);
			if (gameplay->is_pause == false && gameplay->is_stop == false)
				turn_guards(&guards[i]);
			display_one_guard(window, guards[i],
				window->map_sprites[game->level->nb_cases + e_guards]);
			display_one_guard_fov(window, guards[i], game->assets->guard_fov,
				// window->map_sprites[game->level->nb_cases + e_guard_fov],
				gameplay->player);
			guards[i].guard_pos = true_pos;
			set_guard_fov_direction(&guards[i]);
		}
		i++;
	}
}
