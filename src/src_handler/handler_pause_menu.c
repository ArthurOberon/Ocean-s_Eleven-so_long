/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_pause_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:02:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/10 23:38:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_menu(t_gameplay *gameplay, t_sprite **map_sprites, int nb_cases)
{
	// not commented
	map_sprites[nb_cases + e_button_pause]->frame = 0;
	map_sprites[nb_cases + e_button_restart]->frame = 0;
	map_sprites[nb_cases + e_button_quit]->frame = 0;
	map_sprites[nb_cases + e_button_tutorial]->frame = 0;
	if (gameplay->menu_status == 0)
	{
		map_sprites[nb_cases + e_button_pause]->frame = 1;
	}
	else if (gameplay->menu_status == 1)
	{
		map_sprites[nb_cases + e_button_restart]->frame = 1;
	}
	else if (gameplay->menu_status == 2)
	{
		map_sprites[nb_cases + e_button_quit]->frame = 1;
	}
	else if (gameplay->menu_status >= 3)
	{
		map_sprites[nb_cases + e_button_tutorial]->frame = 1;
	}
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
	get_menu(game->gameplay, game->window->map_sprites, game->level->nb_cases);
	if (keysym == XK_space)
		pressed_menu_button(game, game->gameplay);
}
