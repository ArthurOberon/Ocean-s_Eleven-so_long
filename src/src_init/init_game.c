/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:35:23 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/09 18:42:12 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_breakable_wall(char *map, int size, t_vector_2 max)
{
	int			i;
	t_vector_2	pos;

	i = 0;
	while (i < size)
	{
		if (map[i] == '1')
		{
			pos.x = i % max.x;
			pos.y = i / max.x;
			if (pos.x > 0 && pos.x < max.x - 1
				&& (pos.y > 0 && pos.y < max.y - 1))
					map[i] = '2';
		}
		i++;
	}
}

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
	game->window = NULL;
	game->assets = NULL;
	game->gameplay = NULL;
	game->camera = NULL;
	init_window(game);
	init_sprites_assets(game);
	init_sprites(game);
	init_gameplay(game);
	init_camera(game);
	get_breakable_wall(game->level->map, game->level->nb_cases,
		game->level->map_vector);
}
