/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:34:22 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 22:38:47 by aoberon          ###   ########.fr       */
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
		game->player_pos.y -= 1;
		if (IS_DEBUG)
			printf("UP\n");
	}
	if (keysym == XK_S || keysym == XK_s)
	{
		game->player_pos.y += 1;
		if (IS_DEBUG)
			printf("DOWN\n");
	}
	if (keysym == XK_A || keysym == XK_a)
	{
		game->player_pos.x -= 1;
		if (IS_DEBUG)
			printf("LEFT\n");
	}
	if (keysym == XK_D || keysym == XK_d)
	{
		game->player_pos.x += 1;
		if (IS_DEBUG)
			printf("RIGHT\n");
	}
	if (IS_DEBUG)
	{
		printf("player pos : x : %d y : %d\n", game->player_pos.x,
			game->player_pos.y);
		printf("collider player : \n");
		printf("N_O : x : %d y : %d\n",
			game->player_pos.x * CHUNK_SIZE, game->player_pos.y * CHUNK_SIZE);
		printf("N_E : x : %d y : %d\n",
			(game->player_pos.x * CHUNK_SIZE) + CHUNK_SIZE, game->player_pos.y * CHUNK_SIZE);
		printf("S_O : x : %d y : %d\n",
			game->player_pos.x * CHUNK_SIZE, (game->player_pos.y * CHUNK_SIZE) + CHUNK_SIZE);
		printf("S_E : x : %d y : %d\n\n",
			(game->player_pos.x * CHUNK_SIZE) + CHUNK_SIZE, (game->player_pos.y * CHUNK_SIZE) + CHUNK_SIZE);
	}
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		close_window(&game->window);
		return (1);
	}
	handle_player_move(keysym, game);
	return (0);
}
