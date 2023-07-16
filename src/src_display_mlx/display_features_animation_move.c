/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_animation_move.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:23:33 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 17:47:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// not commented ALL

static t_sprite	*get_frame(t_sprite *sprite)
{
	update_frame(sprite);
	return (sprite);
}

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

t_sprite	*get_guard_move_animation(t_guard *guard,
	t_personage_animation *animation)
{
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

t_sprite	*get_player_move_animation(t_player *player,
	t_personage_animation *animation)
{
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
