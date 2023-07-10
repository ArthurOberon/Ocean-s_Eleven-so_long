/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_player_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:18:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/10 14:41:51 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Handle player movement press keys, to start player movement.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to change player struct.
 */
void	handle_player_move_press(int keysym, t_game *game)
{
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
	{
		game->gameplay->player->player_dir.y += -1;
	}
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
	{
		game->gameplay->player->player_dir.y += 1;
	}
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
	{
		game->gameplay->player->player_dir.x += -1;
	}
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
	{
		game->gameplay->player->player_dir.x += 1;
	}
}

/**
 * @brief Handle player movement release keys, to stop player movement
 * 
 * @param keysym key released.
 * @param game game struct, used to change player struct.
 */
void	handle_player_move_release(int keysym, t_game *game)
{
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
	{
		game->gameplay->player->player_dir.y += 1;
	}
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
	{
		game->gameplay->player->player_dir.y += -1;
	}
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
	{
		game->gameplay->player->player_dir.x += 1;
	}
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
	{
		game->gameplay->player->player_dir.x += -1;
	}
}
