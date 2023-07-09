/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pause_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:02:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/10 00:46:18 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_menu(t_gameplay *gameplay)
{
	// not commented
	// ADD sprite instead of print
	char *menu[4];
	char *display_button;
	menu[0] = "Resume";
	menu[1] = "Restart";
	menu[2] = "Quit";
	menu[3] = "Tutorial";

	if (gameplay->menu_status == 0)
	{
		display_button = menu[0];
	}
	if (gameplay->menu_status == 1)
	{
		display_button = menu[1];
	}
	if (gameplay->menu_status == 2)
	{
		display_button = menu[2];
	}
	if (gameplay->menu_status >= 3)
	{
		display_button = menu[3];
	}
	printf("%d\n", gameplay->menu_status);
	printf("%s\n\n", display_button);
}

static void	pressed_menu_button(t_game *game, t_gameplay *gameplay)
{
	// not commented
	if (gameplay->menu_status == 0)
	{
		if (game->gameplay->is_pause == false)
			game->gameplay->is_pause = true;
		else
		{
			game->gameplay->is_pause = false;
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
	if (gameplay->menu_status == 3)
	{
		// display_tutorial(game);
	}
}

void	handle_pause_menu(int keysym, t_game *game)
{
	// not commented
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
	get_menu(game->gameplay);
	if (keysym == XK_space)
		pressed_menu_button(game, game->gameplay);
}
