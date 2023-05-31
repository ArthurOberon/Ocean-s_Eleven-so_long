/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:34:22 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/31 22:36:37 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	free_game(*game, NULL);
	exit(EXIT_SUCCESS);
	return (0);
}

int	secure_lost_focus(t_game *game)
{
	game->gameplay->player->player_dir.x = 0;
	game->gameplay->player->player_dir.y = 0;
	return (1);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		close_game(game);
		return (1);
	}
	if (keysym == XK_P || keysym == XK_p)
	{
		if (game->gameplay->is_pause == false)
			game->gameplay->is_pause = true;
		else
		{
			game->gameplay->is_pause = false;
		}
	}
	if (keysym == XK_R || keysym == XK_r)
	{
		restart(game);
	}
	if (keysym == XK_Delete && game->gameplay->text_box.is_display == true)
	{
		if (game->gameplay->text_box.page_in != 0)
			game->gameplay->text_box.page_in -= 1;
	}
	if (keysym == XK_space && game->gameplay->text_box.is_display == true)
	{
		if (game->gameplay->text_box.read_all == false)
		{
			game->gameplay->text_box.page_in += 1;
			if (game->gameplay->text_box.page_in
				== game->gameplay->text_box.page_number)
				game->gameplay->text_box.read_all = true;
		}
		if (game->gameplay->text_box.read_all == true)
		{
			game->gameplay->is_stop = false;
			game->gameplay->text_box.is_display = false;
			game->gameplay->text_box.read_all = false;
			game->gameplay->text_box.talking_character
				= game->gameplay->player->player_character;
			game->gameplay->text_box.text = NULL;
			free_text_box(&game->gameplay->text_box);
		}
	}
	handle_player_move(keysym, game);
	if (game->gameplay->is_pause == false
		&& game->gameplay->is_stop == false)
	{
		handle_bomb(keysym, game);
		handle_change_character_player(keysym, game, game->gameplay,
			game->gameplay->player);
	}
	handle_pickpocket(keysym, game);
	return (0);
}

int	handle_keyrelease(int keysym, t_game *game)
{
	handle_player_move_release(keysym, game);
	return (0);
}
