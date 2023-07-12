/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_game_features.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 00:14:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/12 14:04:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Close the game and free all the memory.
 * 
 * @param game game struct, to free all the memory.
 * @return int 0.
 */
int	close_game(t_game *game)
{
	exit_game(*game, NULL);
	return (0);
}

/**
 * @brief Secure the game when the player click outside the window,
 * by setting the player direction to 0.
 * 
 * @param game game struct, used to set the player direction to 0.
 * @return int 1.
 */
int	secure_lost_focus(t_game *game)
{
	game->gameplay->player->player_dir.x = 0;
	game->gameplay->player->player_dir.y = 0;
	return (0);
}

/**
 * @brief Handle the out game features, meaning the pause, restart and quit.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct, or close the game.
 */
void	handle_out_game_features(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		close_game(game);
	}
	if (keysym == XK_P || keysym == XK_p)
	{
		game->gameplay->menu_status = 0;
		if (game->gameplay->is_pause == false)
			game->gameplay->is_pause = true;
		else
		{
			game->gameplay->is_pause = false;
		}
	}
	if (keysym == XK_R || keysym == XK_r)
	{
		restart_the_game(game);
	}
	if (keysym == XK_T || keysym == XK_t)
	{
		set_tutorial_text_box(game);
		if (game->gameplay->tutorial_status == -1)
			game->gameplay->tutorial_status = 0;
	}
}

int	handle_end_screen(int keysym, t_game *game)
{
	// not commented
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q
		|| keysym == XK_space)
		close_game(game);
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
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
		close_game(game);
	if (game->gameplay->dialogue == current)
		return (0);
	else if (game->gameplay->dialogue == next)
	{
		game->gameplay->tutorial_status += 1;
		if (game->gameplay->tutorial_status == FRAME_TUTORIAL)
			game->gameplay->tutorial_status = -1;
	}
	else if (game->gameplay->dialogue == prev)
	{
		if (game->gameplay->tutorial_status > 0)
			game->gameplay->tutorial_status -= 1;
	}
	return (0);
}

	// if (keysym == XK_space)
	// {
	// 	game->gameplay->tutorial_status += 1;
	// 	if (game->gameplay->tutorial_status == FRAME_TUTORIAL)
	// 		game->gameplay->tutorial_status = -1;
	// }
	// if (keysym == XK_Delete)
	// {
	// 	if (game->gameplay->tutorial_status > 0)
	// 		game->gameplay->tutorial_status -= 1;
	// }
	// if (game->gameplay->dialogue == NULL)
	// {
	// 	add_one_text_to_dialogue(game, &game->gameplay->dialogue,
	// 		&game->gameplay->all_texts
	// 	[e_text_tutorial_1 + game->gameplay->tutorial_status]);
	// 	printf("text : %s\n", game->gameplay->all_texts
	// 	[e_text_tutorial_1 + game->gameplay->tutorial_status].text);
