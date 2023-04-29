/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:34:22 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 23:44:21 by aoberon          ###   ########.fr       */
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
	if (keysym == XK_W || keysym == XK_w)
	{
		game->gameplay->dir_player.up = 1;
	}
	if (keysym == XK_S || keysym == XK_s)
	{
		game->gameplay->dir_player.down = 1;
	}
	if (keysym == XK_A || keysym == XK_a)
	{
		game->gameplay->dir_player.left = 1;
	}
	if (keysym == XK_D || keysym == XK_d)
	{
		game->gameplay->dir_player.right = 1;
	}
	if (IS_DEBUG)
		debug_player_box_collider(game);
}

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
