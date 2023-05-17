/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_gameplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:58:54 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/17 17:17:43 by aoberon          ###   ########.fr       */
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

void	handle_bomb(int keysym, t_game *game)
{
	if (game->gameplay->player->player_character != e_bomber)
		return ;
	if (keysym == XK_space)
	{
		if (game->gameplay->player->bomb.bomb_plant
			< game->gameplay->player->bomb.bomb_total)
		{
			game->gameplay->player->bomb.bomb_plant += 1;
			gettimeofday(&game->gameplay->player->bomb.last_time, NULL);
		}
		printf("plant a bomb. bomb planted : [%d]\n",
			game->gameplay->player->bomb.bomb_plant);
	}
	if (keysym == XK_Delete)
	{
		if (game->gameplay->player->bomb.bomb_plant > 0)
		{
			game->gameplay->player->bomb.bomb_plant -= 1;
			gettimeofday(&game->gameplay->player->bomb.last_time, NULL);
		}
		printf("remove a bomb. bomb planted : [%d]\n",
			game->gameplay->player->bomb.bomb_plant);
	}
}

void	handle_change_character_player(int keysym, t_player *player)
{
	if (keysym == XK_1 || keysym == XK_2 || keysym == XK_3 || keysym == XK_4)
	{
		set_player_to_character(player, keysym - XK_1);
		return ;
	}
	if (keysym == XK_1)
	{
		player->player_character = e_main;
		printf("new player choose : Danny\n");
	}
	if (keysym == XK_2)
	{
		player->player_character = e_eater;
		printf("new player choose : Rusty\n");
	}
	if (keysym == XK_3)
	{
		player->player_character = e_thief;
		printf("new player choose : Linus\n");
	}
	if (keysym == XK_4)
	{
		player->player_character = e_bomber;
		printf("new player choose : Basher\n");
	}
}

void	handle_pickpocket(int keysym, t_game *game)
{
	if (game->gameplay->player->player_character != e_thief)
		return ;
	if (keysym == XK_space)
	{
		game->gameplay->player->qte.pressed = true;
		if (game->gameplay->player->qte.time_to_press == false)
		{
			game->gameplay->player->qte.pressed_in_time = false;
			game->gameplay->player->qte.is_pickpocketing = true;
		}
		else
			game->gameplay->player->qte.pressed_in_time = true;
	}
	if (keysym == XK_Delete)
	{
		game->gameplay->player->qte.time_to_press = false;
		game->gameplay->player->qte.pressed_in_time = false;
		game->gameplay->player->qte.is_pickpocketing = false;
	}
}
