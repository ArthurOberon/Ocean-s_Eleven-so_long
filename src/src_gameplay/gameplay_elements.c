/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 16:23:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_over(t_game *game)
{
	ft_putstr("GAME OVER\n");
	close_game(game);
}

// Get guard_dir in t_f_vector_2
static void	guard_follow_player(t_game *game, t_player *player, t_guard *guard)
{
	guard->guard_dir.x = player->player_pos.x - guard->guard_pos.x;\
	printf("guard dir : x [%d]\n", guard->guard_dir.x);
	if (guard->guard_dir.x > 1)
		guard->guard_dir.x = 1;
	else if (guard->guard_dir.x < -1)
		guard->guard_dir.x = -1;
	guard->guard_dir.y = player->player_pos.y - guard->guard_pos.y;
	printf("guard dir : y [%d]\n", guard->guard_dir.y);
	if (guard->guard_dir.y > 1)
		guard->guard_dir.y = 1;
	else if (guard->guard_dir.y < -1)
		guard->guard_dir.y = -1;
	printf("guard dir : x [%d] y : [%d]\n\n", guard->guard_dir.x, guard->guard_dir.y);
	// if (player->player_pos.x > guard->guard_pos.x)
	// {
	// 	guard->guard_dir.x = 1;
	// }
	// else if (player->player_pos.x < guard->guard_pos.x)
	// {
	// 	guard->guard_dir.x = -1;
	// }
	// else
	// 	guard->guard_dir.x = 0;
	// if (player->player_pos.y > guard->guard_pos.y)
	// {
	// 	guard->guard_dir.y = 1;
	// }
	// else if (player->player_pos.y < guard->guard_pos.y)
	// {
	// 	guard->guard_dir.y = -1;
	// }
	// else
		// guard->guard_dir.y = 0;
	// printf("player : x [%f] y [%f]\n", player->player_f_pos.x,player->player_f_pos.y);
	// printf("guard : x [%f] y : [%f]\n", guard->guard_f_pos.x, guard->guard_f_pos.y);
	// printf("guard dir : x [%d] y : [%d]\n\n", guard->guard_dir.x, guard->guard_dir.y);
	move_guard(game, guard);
}

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

void	gameplay_elements(t_game *game, t_gameplay *gameplay)
{
	int	i;

	if (gameplay->player->hp == 0)
		game_over(game);
	get_iframes(gameplay->player);
	i = 0;
	while (i < gameplay->nb_guard)
	{
		if (gameplay->guards[i].following_player == true
			&& gameplay->guards[i].is_alive == true)
			guard_follow_player(game, gameplay->player, gameplay->guards);
		i++;
	}
}
