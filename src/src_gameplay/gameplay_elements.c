/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:32:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/10 19:19:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_over(t_game *game)
{
	ft_putstr("GAME OVER\n");
	close_game(game);
}

static void	guard_follow_player(t_player *player, t_guard *guard)
{
	;
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
			guard_follow_player(gameplay->player, gameplay->guards);
		i++;
	}
}
