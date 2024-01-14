/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_dialogue_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:13:36 by aoberon           #+#    #+#             */
/*   Updated: 2024/01/14 13:43:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Create a victory string.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param text string of the text before the code.
 * @param code string of the code.
 * @return char* string of the victory text.
 */
static char	*create_victory_text(t_game *game, char *text, char *code)
{
	char	*message_code;
	char	*victory_text;

	message_code = ft_strjoin(text, code);
	if (!message_code)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	victory_text = ft_strjoin(message_code, "> It's open, perfect! \
Gentlemen, $60 million just for us!");
	if (!victory_text)
	{
		free(text);
		free(message_code);
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	}
	free(text);
	free(message_code);
	return (victory_text);
}

/**
 * @brief Display the victory text.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param victory_text_status int, used to know if the text have to be displayed.
 * 0 is not displayed, 1 create the text, 2 display it.
 * @return int 1 if the text have to be displayed, 0 otherwise.
 */
int	display_victory_text(t_game *game, int *victory_text_status)
{
	if (*victory_text_status == 0)
		return (0);
	if (*victory_text_status == 1)
	{
		game->gameplay->all_texts[e_text_code].text
			= create_victory_text(game,
				game->gameplay->all_texts[e_text_code].text,
				game->gameplay->collectible_code);
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_code],
			game->gameplay->player->player_character);
		display_dialogue(game, game->gameplay->dialogue);
		mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
			game->window->img.mlx_img, 0, 0);
		*victory_text_status = 2;
		return (1);
	}
	else if (*victory_text_status == 2)
	{
		if (game->gameplay->dialogue)
			return (1);
		else if (game->gameplay->dialogue == NULL)
			game->gameplay->is_end = 1;
	}
	return (0);
}

/**
 * @brief Set the tutorial dialogue.
 * 
 * @param game game struct, used to get the gameplay struct.
 */
void	set_tutorial_dialogue(t_game *game)
{
	int	i;

	i = 0;
	while (i < FRAME_TUTORIAL)
	{
		game->gameplay->all_texts[e_text_tutorial_1 + i].has_been_display
			= false;
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts
		[e_text_tutorial_1 + i], e_main);
		i++;
	}
}

/**
 * @brief Set the starting text depending on the player character.
 * 
 * @param game game struct, used to get gameplay struct.
 */
void	set_text_box_events_start(t_game *game)
{
	if (game->gameplay->player->player_character == e_main)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_danny], e_main);
	}
	else if (game->gameplay->player->player_character == e_eater)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_rusty], e_eater);
	}
	else if (game->gameplay->player->player_character == e_thief)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_linus], e_thief);
	}
	else if (game->gameplay->player->player_character == e_bomber)
	{
		add_one_text_to_dialogue(game, &game->gameplay->dialogue,
			&game->gameplay->all_texts[e_text_start_basher], e_bomber);
	}
}

/**
 * @brief Get the events including the text box events.
 * Like remaining 1 or 0 collectible.
 * 
 * @param game game struct, used to exit the game if a malloc fail.
 * @param gameplay gameplay struct,
 * used to get the player and the dialogue struct.
 */
void	get_text_box_events(t_game *game, t_gameplay *gameplay)
{
	get_text_box_events_remain_one_collectible(game, gameplay);
	get_text_box_events_remain_zero_collectible(game, gameplay);
}
