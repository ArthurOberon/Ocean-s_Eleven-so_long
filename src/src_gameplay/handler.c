/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:34:22 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/30 21:41:50 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_window *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	window->win_ptr = NULL;
	return (0);
}

static void	handle_player_move(int keysym, t_game *game)
{
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
	{
		game->gameplay->dir_player.y += -1;
	}
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
	{
		game->gameplay->dir_player.y += 1;
	}
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
	{
		game->gameplay->dir_player.x += -1;
	}
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
	{
		game->gameplay->dir_player.x += 1;
	}
}

	// if (IS_DEBUG)
		// debug_player_box_collider(game);

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		close_window(game->window);
		return (1);
	}
	handle_player_move(keysym, game);
	return (0);
}

int	handle_keyrelease(int keysym, t_game *game)
{
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
	{
		game->gameplay->dir_player.y += 1;
	}
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
	{
		game->gameplay->dir_player.y += -1;
	}
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
	{
		game->gameplay->dir_player.x += 1;
	}
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
	{
		game->gameplay->dir_player.x += -1;
	}
	return (0);
}
