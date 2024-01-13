/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:35:23 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 15:43:58 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set all wall '1' of the char array map
 * to '2'if they are not on the border of the map.
 * 
 * @param map array of char representing the map.
 * @param size size of the map.
 * @param max max of the length of a map on the x (width) and y (height) axis.
 */
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

/**
 * @brief Initialize at 0 the game struct.
 * 
 * @param game game struct to initialize at 0.
 */
void	bzero_game(t_game *game)
{
	game->level = ft_calloc(sizeof(t_level), 1);
	if (!game->level)
		exit(EXIT_FAILURE);
	game->window = NULL;
	game->assets = NULL;
	game->gameplay = NULL;
}

/**
 * @brief Initialize the game struct.
 * 
 * @param game game struct to initialize.
 * @param available_character array of available character.
 * @param chosen_character first character chosen by the player,
 * and will be the character the player will start with
 * between the available ones.
 */
void	init_game(t_game *game, int *available_character,
			int chosen_character)
{
	int	available_character_tmp[4];

	available_character_tmp[0] = available_character[0];
	available_character_tmp[1] = available_character[1];
	available_character_tmp[2] = available_character[2];
	available_character_tmp[3] = available_character[3];
	free(available_character);
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
	init_gameplay(game, available_character_tmp, chosen_character);
	init_camera(game);
}
