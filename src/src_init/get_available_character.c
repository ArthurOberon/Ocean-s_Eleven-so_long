/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_available_character.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:53:58 by arthurobero       #+#    #+#             */
/*   Updated: 2023/05/31 20:56:07 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_one_available_character(int *argc_map,
	int *available_character, int *chosen_character, int character)
{
	if (*argc_map == 1)
			*chosen_character = character;
		available_character[character] = 1;
		*argc_map += 1;
}

static void	check_which_character(char **argv, int *argc_map,
	int *available_character, int *chosen_character)
{
	if (argv[*argc_map][1] == 'd' || argv[*argc_map][1] == 'D')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_main);
	}
	if (argv[*argc_map][1] == 'r' || argv[*argc_map][1] == 'R')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_eater);
	}
	if (argv[*argc_map][1] == 'l' || argv[*argc_map][1] == 'L')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_thief);
	}
	if (argv[*argc_map][1] == 'b' || argv[*argc_map][1] == 'B')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_bomber);
	}
}

int	*get_available_character(char **argv, int *argc_map, int *chosen_character)
{
	int		*available_character;

	available_character = ft_calloc(sizeof(int), 4);
	if (!available_character)
		return (NULL);
	*chosen_character = e_main;
	available_character[0] = 1;
	available_character[1] = 1;
	available_character[2] = 1;
	available_character[3] = 1;
	while (argv[*argc_map][0] == '-'
		&& ((argv[*argc_map][1] == 'd' || argv[*argc_map][1] == 'D')
		|| (argv[*argc_map][1] == 'r' || argv[*argc_map][1] == 'R')
		|| (argv[*argc_map][1] == 'l' || argv[*argc_map][1] == 'L')
		|| (argv[*argc_map][1] == 'b' || argv[*argc_map][1] == 'B')))
	{
		if (*argc_map == 1)
			ft_bzero(available_character, sizeof(int) * 4);
		check_which_character(argv, argc_map, available_character,
			chosen_character);
	}
	return (available_character);
}
