/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/11 00:06:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_over(t_game *game)
{
	ft_putstr("GAME OVER\n");
	close_game(game);
}

static void	guard_follow_player(t_game *game, t_player *player, t_guard *guard)
{
	if (player->player_pos.x > guard->guard_pos.x)
	{
		guard->guard_dir.x = 1;
	}
	else if (player->player_pos.x < guard->guard_pos.x)
	{
		guard->guard_dir.x = -1;
	}
	else
		guard->guard_dir.x = 0;
	if (player->player_pos.y > guard->guard_pos.y)
	{
		guard->guard_dir.y = 1;
	}
	else if (player->player_pos.y < guard->guard_pos.y)
	{
		guard->guard_dir.y = -1;
	}
	else
		guard->guard_dir.y = 0;
	printf("player : x [%f] y [%f]\n", player->player_f_pos.x,player->player_f_pos.y);
	printf("guard : x [%f] y : [%f]\n", guard->guard_f_pos.x, guard->guard_f_pos.y);
	printf("guard dir : x [%d] y : [%d]\n\n", guard->guard_dir.x, guard->guard_dir.y);
	move_guard(game, guard);
}

static void	get_iframes(t_player *player)
{
	if (player->iframes == false)
		return ;
	if (player->iframes_start_time == 0)
		player->iframes_start_time = clock();
	player->iframes_time = clock();
	if ((player->iframes_time - player->iframes_start_time) / CLOCKS_PER_SEC
		>= DELAY_IFRAMES)
	{
		player->iframes = false;
		player->iframes_start_time = 0;
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
