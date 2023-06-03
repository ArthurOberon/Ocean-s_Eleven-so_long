/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:34:22 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/03 20:35:22 by aoberon          ###   ########.fr       */
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
	// debug text_box
	if (keysym == XK_O || keysym == XK_o)
		add_text(game, &game->gameplay->texts_box_list,
			&game->gameplay->texts[e_text_debug]);
	// debug text_box

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
	if (keysym == XK_Delete && game->gameplay->texts_box_list && game->gameplay->texts_box_list->text_box->is_display == true)
	{
		if (game->gameplay->texts_box_list->text_box->page_in != 0)
			game->gameplay->texts_box_list->text_box->page_in -= 1;
		else
		{
			if (game->gameplay->texts_box_list->prev != NULL)
			{
				game->gameplay->texts_box_list = game->gameplay->texts_box_list->prev;
				game->gameplay->texts_box_list->text_box->page_in = 0;
			}
		}
	}
	if (keysym == XK_space && game->gameplay->texts_box_list && game->gameplay->texts_box_list->text_box->is_display == true)
	{
		if (game->gameplay->texts_box_list->text_box->read_all == false)
		{
			game->gameplay->texts_box_list->text_box->page_in += 1;
			if (game->gameplay->texts_box_list->text_box->page_in
				== game->gameplay->texts_box_list->text_box->page_number)
				game->gameplay->texts_box_list->text_box->read_all = true;
		}
		if (game->gameplay->texts_box_list->text_box->read_all == true)
		{
			if (game->gameplay->texts_box_list->next == NULL)
			{
				game->gameplay->is_stop = false;
				game->gameplay->texts_box_list->text_box->is_display = false;
				game->gameplay->texts_box_list->text_box->read_all = false;
				game->gameplay->texts_box_list->text_box->text = NULL;
				free_text_box_text_pages(game->gameplay->texts_box_list->text_box);
				game->gameplay->texts_box_list = ft_lstfirst_texts_box(game->gameplay->texts_box_list);
				ft_lstclear_texts_box(&game->gameplay->texts_box_list);
			}
			else
				game->gameplay->texts_box_list = game->gameplay->texts_box_list->next;
			return (0);
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
