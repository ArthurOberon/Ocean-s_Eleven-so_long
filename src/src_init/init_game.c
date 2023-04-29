/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:35:23 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 23:43:07 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bzero_game(t_game *game)
{
	game->level = ft_calloc(sizeof(t_level), 1);
	if (!game->level)
		exit(EXIT_FAILURE);
	game->window = NULL;
	game->assets = NULL;
	game->gameplay = NULL;
}

void	init_game(t_game *game)
{
	init_window(game);
	init_sprites_assets(game);
	init_sprites(game);
	init_gameplay(game);
}
