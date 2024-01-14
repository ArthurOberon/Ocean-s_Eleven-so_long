/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_avatar_animation.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:37:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 09:27:51 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Init the avatar animation struct, part 1.
 * 
 * @param avatar_animation avatar animation struct, where the sprites assets
 * are stored.
 * @param assets assets struct, used to get the sprites assets. 
 */
void	init_avatar_animation_part_1(t_avatar_animation *avatar_animation,
	t_sprites_assets *assets)
{
	avatar_animation[0].idle = assets->player_danny_idle;
	avatar_animation[0].move_up = assets->player_danny_move_up;
	avatar_animation[0].move_down = assets->player_danny_move_down;
	avatar_animation[0].move_left = assets->player_danny_move_left;
	avatar_animation[0].move_right = assets->player_danny_move_right;
	avatar_animation[1].idle = assets->player_rusty_idle;
	avatar_animation[1].move_up = assets->player_rusty_move_up;
	avatar_animation[1].move_down = assets->player_rusty_move_down;
	avatar_animation[1].move_left = assets->player_rusty_move_left;
	avatar_animation[1].move_right = assets->player_rusty_move_right;
	avatar_animation[2].idle = assets->player_linus_idle;
	avatar_animation[2].move_up = assets->player_linus_move_up;
	avatar_animation[2].move_down = assets->player_linus_move_down;
	avatar_animation[2].move_left = assets->player_linus_move_left;
	avatar_animation[2].move_right = assets->player_linus_move_right;
}

/**
 * @brief Init the avatar animation struct, part 2.
 * 
 * @param avatar_animation avatar animation struct, where the sprites assets
 * are stored.
 * @param assets assets struct, used to get the sprites assets.
 */
void	init_avatar_animation_part_2(t_avatar_animation *avatar_animation,
	t_sprites_assets *assets)
{
	avatar_animation[3].idle = assets->player_basher_idle;
	avatar_animation[3].move_up = assets->player_basher_move_up;
	avatar_animation[3].move_down = assets->player_basher_move_down;
	avatar_animation[3].move_left = assets->player_basher_move_left;
	avatar_animation[3].move_right = assets->player_basher_move_right;
	avatar_animation[4].idle = assets->guard_idle;
	avatar_animation[4].move_up = assets->guard_move_up;
	avatar_animation[4].move_down = assets->guard_move_down;
	avatar_animation[4].move_left = assets->guard_move_left;
	avatar_animation[4].move_right = assets->guard_move_right;
}

/**
 * @brief Init the avatar animation struct.
 * 
 * @param game game struct, used to get free the game if an error occured.
 * @param assets assets struct, used to get the sprites assets.
 * @return t_avatar_animation* avatar animation struct initialized.
 */
t_avatar_animation	*init_avatar_animation(t_game *game,
	t_sprites_assets *assets)
{
	t_avatar_animation	*avatar_animation;

	avatar_animation = ft_calloc(sizeof(t_avatar_animation), 5);
	if (!avatar_animation)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	init_avatar_animation_part_1(avatar_animation, assets);
	init_avatar_animation_part_2(avatar_animation, assets);
	return (avatar_animation);
}
