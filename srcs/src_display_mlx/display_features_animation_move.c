/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_animation_move.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:23:33 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 11:02:09 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get the frame of the sprite, udpate the frame of the sprite, then
 * return the sprite.
 * 
 * @param sprite sprite struct, used to get the frame of the sprite.
 * @return t_sprite* sprite struct, the sprite with the new frame.
 */
static t_sprite	*get_frame(t_sprite *sprite)
{
	update_frame(sprite);
	return (sprite);
}

/**
 * @brief Get the guard idle frame.
 * 
 * @param guard guard struct, used to get the guard_look_dir.
 * @return int frame number of the idle animation.
 */
int	get_guard_idle_frame(t_guard *guard)
{
	if (guard->guard_look_dir.x == -1 && guard->guard_look_dir.y == 0)
	{
		return (1);
	}
	if (guard->guard_look_dir.x == 0 && guard->guard_look_dir.y == -1)
	{
		return (2);
	}
	if (guard->guard_look_dir.x == 1 && guard->guard_look_dir.y == 0)
	{
		return (3);
	}
	if (guard->guard_look_dir.x == 0 && guard->guard_look_dir.y == 1)
	{
		return (0);
	}
	return (0);
}

/**
 * @brief Get the guard move animation.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param guard guard struct, used to get the guard_f_dir and guard_look_dir.
 * @param animation avatar_animation struct,
 * used to get the animation of the guard.
 * @return t_sprite* sprite struct,
 * the right sprite of the guard to display depending on the guard direction.
 */
t_sprite	*get_guard_move_animation(t_game *game, t_guard *guard,
	t_avatar_animation *animation)
{
	if (game->gameplay->is_stop || game->gameplay->is_pause)
		return (guard->guard_sprite);
	if (guard->guard_f_dir.x == 0 && guard->guard_f_dir.y == 0)
		return (animation[4].idle);
	if (guard->guard_look_dir.x == 1)
		return (get_frame(animation[4].move_right));
	if (guard->guard_look_dir.x == -1)
		return (get_frame(animation[4].move_left));
	if (guard->guard_look_dir.x == 0 && guard->guard_look_dir.y != 0)
	{
		if (guard->guard_look_dir.y == 1)
			return (get_frame(animation[4].move_down));
		if (guard->guard_look_dir.y == -1)
			return (get_frame(animation[4].move_up));
	}
	return (animation[4].idle);
}

/**
 * @brief Get the player move animation.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param player player struct, used to get the player_character value.
 * @param animation avatar_animation struct,
 * used to get the animation of the player.
 * @return t_sprite* sprite struct,
 * the right sprite of the player to display depending on the player direction.
 */
t_sprite	*get_player_move_animation(t_game *game, t_player *player,
	t_avatar_animation *animation)
{
	if (game->gameplay->is_stop || game->gameplay->is_pause)
		return (get_frame(animation[player->player_character].idle));
	if (player->player_dir.x == 0 && player->player_dir.y == 0)
		return (get_frame(animation[player->player_character].idle));
	if (player->player_look_dir.x == 1)
		return (get_frame(animation[player->player_character].move_right));
	if (player->player_look_dir.x == -1)
		return (get_frame(animation[player->player_character].move_left));
	if (player->player_look_dir.x == 0 && player->player_look_dir.y != 0)
	{
		if (player->player_look_dir.y == 1)
			return (get_frame(animation[player->player_character].move_down));
		if (player->player_look_dir.y == -1)
			return (get_frame(animation[player->player_character].move_up));
	}
	return (get_frame(animation[player->player_character].idle));
}
