/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_dialogue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:32:37 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/10 13:26:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Go to the next page of the dialogue text_box.
 * 
 * @param game game struct, used to get the gameplay struct.
 */
static void	handle_dialogue_next_page(t_game *game)
{
	if (game->gameplay->dialogue->text_box->read_all == false)
	{
		game->gameplay->dialogue->text_box->page_in += 1;
		if (game->gameplay->dialogue->text_box->page_in
			== game->gameplay->dialogue->text_box->page_number)
			game->gameplay->dialogue->text_box->read_all = true;
	}
}

/**
 * @brief Go to the next text_box/node of the dialogue.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @return int 1 if the player go to the next text_box/node
 * (meaning that the all text_box has been read), 0 otherwise.
 */
static int	handle_dialogue_next_text_box(t_game *game)
{
	if (game->gameplay->dialogue->text_box->read_all == true)
	{
		if (game->gameplay->dialogue->next == NULL)
		{
			game->gameplay->is_stop = false;
			game->gameplay->dialogue->text_box->is_display = false;
			game->gameplay->dialogue->text_box->read_all = false;
			game->gameplay->dialogue->text_box->text = NULL;
			free_text_box_text_pages(game->gameplay->dialogue->text_box);
			game->gameplay->dialogue
				= ft_lstfirst_texts_box(game->gameplay->dialogue);
			ft_lstclear_texts_box(&game->gameplay->dialogue);
		}
		else
			game->gameplay->dialogue = game->gameplay->dialogue->next;
		return (1);
	}
	return (0);
}

/**
 * @brief Go to the next page or next text_box/node of the dialogue.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct.
 * @return int 1 if the player go to the next text_box/node
 * (meaning that the all text_box has been read), 0 otherwise.
 */
static int	handle_dialogue_next(int keysym, t_game *game)
{
	int	return_value;

	return_value = 0;
	if (keysym == XK_space
		&& game->gameplay->dialogue
		&& game->gameplay->dialogue->text_box->is_display == true)
	{
		handle_dialogue_next_page(game);
		return_value = handle_dialogue_next_text_box(game);
	}
	return (return_value);
}

/**
 * @brief Go to the previous page of the dialogue.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct.
 */
static void	handle_dialogue_prev(int keysym, t_game *game)
{
	if (keysym == XK_Delete
		&& game->gameplay->dialogue
		&& game->gameplay->dialogue->text_box->is_display == true)
	{
		if (game->gameplay->dialogue->text_box->page_in != 0)
			game->gameplay->dialogue->text_box->page_in -= 1;
		else
		{
			if (game->gameplay->dialogue->prev != NULL)
			{
				game->gameplay->dialogue = game->gameplay->dialogue->prev;
				game->gameplay->dialogue->text_box->page_in = 0;
			}
		}
	}
}

/**
 * @brief Handle the dialogue of the game.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct.
 * @return int 1 if the player go to the next text_box/node
 * (meaning that the all text_box has been read), 0 otherwise.
 */
int	handle_dialogue(int keysym, t_game *game)
{
	int	return_value;

	return_value = 0;
	return_value = handle_dialogue_next(keysym, game);
	handle_dialogue_prev(keysym, game);
	return (return_value);
}
