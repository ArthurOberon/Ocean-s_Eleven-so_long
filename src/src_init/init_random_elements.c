/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_random_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:37:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/26 19:48:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	*get_all_ground_pos(char *map, int size, int *ground_count)
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

void	put_unavailable_character_on_map(t_game *game, t_gameplay *gameplay)
{
	int	random_pos;
	int	character;
	int	ground_count;
	int	*ground_pos;

	ground_pos = get_all_ground_pos(game->level->map, game->level->nb_cases,
			&ground_count);
	if (!ground_pos)
		free_game(*game, "Error of malloc.\n");
	while ((gameplay->available_character[0] == 0)
		|| (gameplay->available_character[1] == 0)
		|| (gameplay->available_character[2] == 0)
		|| (gameplay->available_character[3] == 0))
	{
		character = rand() % 4;
		while (gameplay->available_character[character] == 1
			|| gameplay->available_character[character] == 2)
			character = rand() % 4;
		random_pos = ground_pos[rand() % ground_count--];
		set_character_on_pos(game, gameplay, character, random_pos);
	}
	free(ground_pos);
}
