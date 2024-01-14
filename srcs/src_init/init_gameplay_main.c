/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:18:56 by aoberon           #+#    #+#             */
/*   Updated: 2024/01/14 13:46:36 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Create the chunk positions of the map.
 * 
 * @param game game struct, used to exit the program if a malloc fail.
 * @param chunk_pos chunk positions to create.
 * @param size size of the map on the x (width) and y (height) axis.
 * @param nb number of chunk in the map.
 */
static void	create_chunk_positions(t_game *game, t_vector_2 **chunk_pos,
	t_vector_2 size, int nb)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(*chunk_pos) = ft_calloc(sizeof(t_vector_2), nb);
	if (!*chunk_pos)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	i = 0;
	y = 0;
	while (i < size.y)
	{
		j = 0;
		x = 0;
		while (j < size.x)
		{
			(*chunk_pos)[(i * size.x) + j] = (t_vector_2){x, y};
			j++;
			x += CHUNK_SIZE;
		}
		i++;
		y += CHUNK_SIZE;
	}
}

/**
 * @brief initialize the gameplay struct.
 * 
 * @param game game struct, used to get the level struct
 * and exit the program if a malloc fail.
 * @param available_character array of available character.
 * @param chosen_character first character chosen by the player,
 * and will be the character the player will start with
 * between the available ones.
 */
void	init_gameplay(t_game *game, int *available_character,
			int chosen_character)
{
	t_gameplay	*gameplay;

	gameplay = ft_calloc(sizeof(t_gameplay), 1);
	if (!gameplay)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	game->gameplay = gameplay;
	init_gameplay_helper(game, gameplay, available_character, chosen_character);
	create_chunk_positions(game, &gameplay->chunks_pos, game->level->map_vector,
		game->level->nb_cases);
	gameplay->map_start_state = ft_strdup(game->level->map);
	init_player(game, gameplay->player, chosen_character);
	init_guards(game, gameplay->guards);
	gameplay->dialogue = NULL;
	init_all_texts_of_the_game(game, gameplay);
	init_collectible(game, gameplay, gameplay->collectible);
	gameplay->avatar_animation
		= init_avatar_animation(game, game->assets);
	put_unavailable_character_on_map(game, gameplay);
}
