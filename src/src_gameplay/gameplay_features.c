/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_features.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 22:13:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Close the game, by printing "GAME OVER" and close/free the game.
 * 
 * @param game game struct, to free the game.
 */
static void	game_over(t_game *game)
{
	ft_printf("GAME OVER\n");
	close_game(game);
}

/**
 * @brief Get the iframes (invincibility frames) for a certain amount of time.
 * If the player is hit by a guard, he will be invincible for a certain amount.
 * 
 * @param player player struct, to set the iframes variables.
 */
static void	get_iframes(t_player *player)
{
	double			delay;

	if (player->iframes == false)
		return ;
	if (player->iframes_start_time.tv_sec == 0)
		gettimeofday(&player->iframes_start_time, NULL);
	gettimeofday(&player->iframes_time, NULL);
	delay = (((double)(player->iframes_time.tv_usec
					- player->iframes_start_time.tv_usec)
				/ CLOCKS_PER_SEC) + player->iframes_time.tv_sec
			- player->iframes_start_time.tv_sec);
	if (delay >= DELAY_IFRAMES)
	{
		player->iframes = false;
		player->iframes_start_time = (struct timeval){0, 0};
	}
}

/**
 * @brief Makes the guard chase the player, for a certain amount of time,
 * if the player is in the guard's line of sight.
 * 
 * @param game game struct, used to get the level struct.
 * @param player player struct, used to get the player position.
 * @param guard guard struct, used to move the guard.
 */
static void	guard_chase_player(t_game *game, t_player *player, t_guard *guard)
{
	double			delay;

	if (guard->chase_start_time.tv_sec == 0)
		gettimeofday(&guard->chase_start_time, NULL);
	gettimeofday(&guard->chase_time, NULL);
	delay = (((double)(guard->chase_time.tv_usec
					- guard->chase_start_time.tv_usec)
				/ CLOCKS_PER_SEC) + guard->chase_time.tv_sec
			- guard->chase_start_time.tv_sec);
	if (delay >= DELAY_GUARD_CHASE_PLAYER)
	{
		guard->chasing_player = false;
		guard->chase_start_time = (struct timeval){0, 0};
	}
	else if (guard->is_in_player == false)
	{
		guard->guard_f_dir = direction_normalized(guard->guard_pos,
				player->player_pos);
		move_guard(game, guard, player);
	}
}

/**
 * @brief launches all the gameplay features, such as 
 * game over, the text_box, the iframes and guards chasing the player.
 * 
 * @param game game struct, used to close the game if the player dies.
 * @param gameplay gameplay struct, used to get the player and guards structs.
 */
void	gameplay_features(t_game *game, t_gameplay *gameplay)
{
	int	i;

	if (gameplay->player->hp == 0)
		game_over(game);
	get_text_box_events(game, gameplay);
	get_iframes(gameplay->player);
	i = 0;
	while (i < gameplay->nb_guard)
	{
		if (gameplay->guards[i].chasing_player == true
			&& gameplay->guards[i].is_alive == true)
			guard_chase_player(game, gameplay->player, &gameplay->guards[i]);
		i++;
	}
}
