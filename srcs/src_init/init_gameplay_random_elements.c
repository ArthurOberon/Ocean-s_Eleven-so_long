/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_random_elements.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:37:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 09:35:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set the guard look direction randomly.
 * 
 * @param guard guard struct, set up his look direction.
 */
void	random_look_direction(t_guard *guard)
{
	int	random;

	guard->guard_look_dir.x = 0;
	guard->guard_look_dir.y = 0;
	random = rand() % 4;
	if (random == 0)
		guard->guard_look_dir.x = -1;
	else if (random == 1)
		guard->guard_look_dir.y = 1;
	else if (random == 2)
		guard->guard_look_dir.x = 1;
	else if (random == 3)
		guard->guard_look_dir.y = -1;
}

/**
 * @brief Get the all ground '0' position on the map.
 * 
 * @param map map of the level in a string.
 * @param size size of the map string.
 * @param ground_count number of ground '0' on the map.
 * @return int* array of all ground '0' position on the map.
 */
static int	*create_tab_ground_pos(char *map, int size, int *ground_count)
{
	int	i;
	int	j;
	int	*ground_pos;

	i = 0;
	(*ground_count) = 0;
	while (i < size)
	{
		if (map[i] == '0')
			(*ground_count)++;
		i++;
	}
	ground_pos = ft_calloc(sizeof(int), *ground_count);
	if (!ground_pos)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (map[i] == '0')
			ground_pos[j++] = i;
		i++;
	}
	return (ground_pos);
}

/**
 * @brief Set the character on a posisition on the map.
 * 
 * @param game game struct, used to get the level struct.
 * @param gameplay gameplay struct, used to get the available_character array.
 * @param character character to set on the map.
 * @param random_pos position random on the map to set the character.
 */
static void	set_character_on_pos(t_game *game, t_gameplay *gameplay,
	int character, int random_pos)
{
	if (character == e_main)
		game->level->map[random_pos] = 'D';
	if (character == e_eater)
		game->level->map[random_pos] = 'R';
	if (character == e_thief)
		game->level->map[random_pos] = 'L';
	if (character == e_bomber)
		game->level->map[random_pos] = 'B';
	gameplay->available_character[character] = 2;
}

/**
 * @brief Set a character on random position on the map.
 * 
 * @param game game struct, used to get the gameplay struct and the level struct.
 * @param ground_pos int array, all the ground '0' position on the map.
 * @param ground_count int, number of ground '0' on the map (size of ground_pos).
 * @param character character to set on the map.
 */
static void	set_character_on_random_position(t_game *game, int **ground_pos,
	int *ground_count, int character)
{
	int	random_pos;

	random_pos = (*ground_pos)[rand() % *ground_count];
	set_character_on_pos(game, game->gameplay, character, random_pos);
	free(*ground_pos);
	*ground_pos = create_tab_ground_pos(game->level->map, game->level->nb_cases,
			ground_count);
	if (!*ground_pos)
		exit_game(*game, "Error of malloc.\n");
}

/**
 * @brief Put unavailable character on the map.
 * For the array available_character, 0 is unavailable,
 * 1 is available and 2 is available on the map.
 * 
 * @param game game struct, used to get the level struct.
 * @param gameplay gameplay struct, used to get the available_character array.
 */
void	put_unavailable_character_on_map(t_game *game, t_gameplay *gameplay)
{
	int	character;
	int	ground_count;
	int	*ground_pos;

	ground_pos = create_tab_ground_pos(game->level->map, game->level->nb_cases,
			&ground_count);
	if (!ground_pos)
		exit_game(*game, "Error of malloc.\n");
	while ((gameplay->available_character[0] == 0)
		|| (gameplay->available_character[1] == 0)
		|| (gameplay->available_character[2] == 0)
		|| (gameplay->available_character[3] == 0))
	{
		if (ground_count == 0)
			break ;
		character = rand() % 4;
		while (gameplay->available_character[character] == 1
			|| gameplay->available_character[character] == 2)
			character = rand() % 4;
		set_character_on_random_position(game, &ground_pos, &ground_count,
			character);
	}
	free(ground_pos);
}
