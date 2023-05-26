/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:35:23 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/26 18:15:39 by aoberon          ###   ########.fr       */
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

// static void	put_character_on_map(t_game *game, t_gameplay *gameplay)
// {
// 	int	i;
// 	int	character;

// 	i = 0;
// 	while (i < game->level->nb_cases)
// 	{
// 		if (gameplay->available_character[0] != 0
// 			&& gameplay->available_character[1] != 0
// 			&& gameplay->available_character[2] != 0
// 			&& gameplay->available_character[3] != 0)
// 			break ;
// 		if (game->level->map[i] == '0')
// 		{
// 			if (rand() % 101 > 99.9)
// 			{
// 				character = 0;
// 				while (character < 5)
// 				{
// 					if (gameplay->available_character[character] == 0)
// 						break ;
// 					character++;
// 				}
// 				if (character == 5)
// 					break ;
// 				if (character == e_main)
// 					game->level->map[i] = 'D';
// 				if (character == e_eater)
// 					game->level->map[i] = 'R';
// 				if (character == e_thief)
// 					game->level->map[i] = 'L';
// 				if (character == e_bomber)
// 					game->level->map[i] = 'B';
// 				gameplay->available_character[character] = 2;
// 			}
// 		}
// 		i++;
// 	}
// }

void	init_game(t_game *game, int available_character[4],
			int chosen_character)
{
	srand(time(NULL));
	game->window = NULL;
	game->assets = NULL;
	game->gameplay = NULL;
	game->camera = NULL;
	get_breakable_wall(game->level->map, game->level->nb_cases,
		game->level->map_vector);
	init_window(game);
	init_sprites_assets(game);
	init_sprites(game);
	init_gameplay(game, available_character, chosen_character);
	init_camera(game);
	put_character_on_map(game, game->gameplay);
}
