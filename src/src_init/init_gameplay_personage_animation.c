/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_personage_animation.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:37:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 16:52:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_personage_animation	*init_personage_animation(t_game *game,
	t_sprites_assets *assets)
{
	t_personage_animation	*personage_animation;

	// not commented
	personage_animation = ft_calloc(sizeof(t_personage_animation), 5);
	if (!personage_animation)
		exit_game(*game, "Error of malloc.\n");
	personage_animation[0]->idle = assets->player_danny_idle;
	personage_animation[0].move_up = assets->player_danny_move_up;
	personage_animation[0].move_down = assets->player_danny_move_down;
	personage_animation[0].move_left = assets->player_danny_move_left;
	personage_animation[0].move_right = assets->player_danny_move_right;
	personage_animation[1].idle = assets->player_rusty_idle;
	personage_animation[1].move_up = assets->player_rusty_move_up;
	personage_animation[1].move_down = assets->player_rusty_move_down;
	personage_animation[1].move_left = assets->player_rusty_move_left;
	personage_animation[1].move_right = assets->player_rusty_move_right;
	personage_animation[2].idle = assets->player_linus_idle;
	personage_animation[2].move_up = assets->player_linus_move_up;
	personage_animation[2].move_down = assets->player_linus_move_down;
	personage_animation[2].move_left = assets->player_linus_move_left;
	personage_animation[2].move_right = assets->player_linus_move_right;
	personage_animation[3].idle = assets->player_basher_idle;
	personage_animation[3].move_up = assets->player_basher_move_up;
	personage_animation[3].move_down = assets->player_basher_move_down;
	personage_animation[3].move_left = assets->player_basher_move_left;
	personage_animation[3].move_right = assets->player_basher_move_right;
	personage_animation[4].idle = assets->guard_idle;
	personage_animation[4].move_up = assets->guard_move_up;
	personage_animation[4].move_down = assets->guard_move_down;
	personage_animation[4].move_left = assets->guard_move_left;
	personage_animation[4].move_right = assets->guard_move_right;
	return (personage_animation);
}
