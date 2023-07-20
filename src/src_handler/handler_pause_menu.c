/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pause_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:02:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 10:36:36 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Change the menu sprites frame depending on the menu_status.
 * 
 * @param gameplay gameplay struct, used to get the menu_status.
 * @param assets assets struct, where the menu sprites are stored.
 */
static void	get_menu(t_gameplay *gameplay, t_sprites_assets *assets)
{
	assets->button_pause->frame = 0;
	assets->button_reset->frame = 0;
	assets->button_quit->frame = 0;
	assets->button_tutorial->frame = 0;
	if (gameplay->menu_status == 0)
	{
		assets->button_pause->frame = 1;
	}
	else if (gameplay->menu_status == 1)
	{
		assets->button_reset->frame = 1;
	}
	else if (gameplay->menu_status == 2)
	{
		assets->button_quit->frame = 1;
	}
	else if (gameplay->menu_status >= 3)
	{
		assets->button_tutorial->frame = 1;
	}
}

/**
 * @brief Handle the pressed button in the pause menu.
 * 
 * @param game game struct.
 * @param gameplay gameplay struct, used to get the menu_status.
 */
static void	pressed_menu_button(t_game *game, t_gameplay *gameplay)
{
	if (gameplay->menu_status == 0)
	{
		if (gameplay->is_pause == false)
			gameplay->is_pause = true;
		else
		{
			gameplay->is_pause = false;
		}
	}
	if (gameplay->menu_status == 1)
	{
		restart_the_game(game);
	}
	if (gameplay->menu_status == 2)
	{
		close_game(game);
	}
	if (gameplay->menu_status >= 3)
	{
		set_tutorial_dialogue(game);
		if (gameplay->tutorial_status == -1)
			gameplay->tutorial_status = 0;
	}
}

/**
 * @brief Handle the pause menu.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct.
 */
void	handle_pause_menu(int keysym, t_game *game)
{
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
	{
		if (game->gameplay->menu_status >= 0
			&& game->gameplay->menu_status <= 2)
			game->gameplay->menu_status += 3;
	}
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
	{
		if (game->gameplay->menu_status > 2 && game->gameplay->menu_status < 6)
			game->gameplay->menu_status -= 3;
	}
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
	{
		if (game->gameplay->menu_status > 0 && game->gameplay->menu_status <= 2)
			game->gameplay->menu_status -= 1;
	}
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
	{
		if (game->gameplay->menu_status >= 0 && game->gameplay->menu_status < 2)
			game->gameplay->menu_status += 1;
	}
	get_menu(game->gameplay, game->assets);
	if (keysym == XK_space || keysym == XK_Return)
		pressed_menu_button(game, game->gameplay);
}
