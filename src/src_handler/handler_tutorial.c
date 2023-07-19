/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_tutorial.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:19:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 20:55:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_tutorial(t_game *game)
{
	// not commented
	if (game->gameplay->dialogue)
	{
		game->gameplay->dialogue->text_box->is_display = false;
		game->gameplay->dialogue->text_box->read_all = false;
		game->gameplay->dialogue->text_box->text = NULL;
		free_text_box_text_pages(game->gameplay->dialogue->text_box);
		game->gameplay->dialogue
			= ft_lstfirst_texts_box(game->gameplay->dialogue);
		ft_lstclear_texts_box(&game->gameplay->dialogue);
	}
	game->gameplay->tutorial_status = -1;
	if (game->gameplay->is_start)
	{
		set_text_box_events_start(game);
	}
	return (1);
}

static int	tutorial_option(int keysym, t_game *game)
{
	// not commented
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		return (close_game(game));
	}
	if (keysym == XK_X || keysym == XK_x)
	{
		return (close_tutorial(game));
	}
	return (0);
}

int	handle_tutorial(int keysym, t_game *game)
{
	// not commented
	void	*prev;
	void	*current;
	void	*next;

	prev = game->gameplay->dialogue->prev;
	current = game->gameplay->dialogue;
	next = game->gameplay->dialogue->next;
	handle_dialogue(keysym, game);
	if (tutorial_option(keysym, game))
		return (0);
	if (game->gameplay->dialogue == current)
		return (0);
	else if (game->gameplay->dialogue == next)
	{
		game->gameplay->tutorial_status += 1;
		if (game->gameplay->tutorial_status == FRAME_TUTORIAL)
			return (close_tutorial(game));
	}
	else if (game->gameplay->dialogue == prev)
	{
		if (game->gameplay->tutorial_status > 0)
			game->gameplay->tutorial_status -= 1;
	}
	return (0);
}
