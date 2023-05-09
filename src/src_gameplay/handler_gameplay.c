/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_gameplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:58:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/09 18:24:50 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_player_move(int keysym, t_game *game)
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
	// if (IS_DEBUG)
		// debug_player_box_collider(game);

void	handle_bomb(int keysym, t_game *game)
{
	if (keysym == XK_space)
	{
		if (game->gameplay->player->bomb.bomb_plant
			< game->gameplay->player->bomb.bomb_total)
		{
			game->gameplay->player->bomb.bomb_plant += 1;
			game->gameplay->player->bomb.last_time = clock();
		}
		printf("plant a bomb. bomb planted : [%d]\n",
			game->gameplay->player->bomb.bomb_plant);
	}
	if (keysym == XK_Delete)
	{
		if (game->gameplay->player->bomb.bomb_plant > 0)
		{
			game->gameplay->player->bomb.bomb_plant -= 1;
			game->gameplay->player->bomb.last_time = clock();
		}
		printf("remove a bomb. bomb planted : [%d]\n",
			game->gameplay->player->bomb.bomb_plant);
	}
}
