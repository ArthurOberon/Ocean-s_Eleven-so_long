/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_available_character.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:53:58 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/03 19:00:37 by aoberon          ###   ########.fr       */
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

static int	check_which_character(char **argv, int *argc_map,
	int *available_character, int *chosen_character)
{
	if (argv[*argc_map][1] == 'd' || argv[*argc_map][1] == 'D')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_main);
	}
	else if (argv[*argc_map][1] == 'r' || argv[*argc_map][1] == 'R')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_eater);
	}
	else if (argv[*argc_map][1] == 'l' || argv[*argc_map][1] == 'L')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_thief);
	}
	else if (argv[*argc_map][1] == 'b' || argv[*argc_map][1] == 'B')
	{
		set_one_available_character(argc_map, available_character,
			chosen_character, e_bomber);
	}
	else
		return (0);
	return (1);
}

int	*get_available_character(char **argv, int *argc_map, int *chosen_character)
{
	int		*available_character;
	int		check_error;

	available_character = ft_calloc(sizeof(int), 4);
	if (!available_character)
		return (NULL);
	*chosen_character = e_main;
	available_character[0] = 1;
	available_character[1] = 1;
	available_character[2] = 1;
	available_character[3] = 1;
	while (argv[*argc_map][0] == '-')
	{
		if (*argc_map == 1)
			ft_bzero(available_character, sizeof(int) * 4);
		check_error = check_which_character(argv, argc_map, available_character,
				chosen_character);
		if (check_error == 0)
		{
			ft_printf("Error\n");
			ft_printf("Not a valid option.\n");
			ft_printf("The option allows you to choose which character you will have at the start, the character not selectioned will be lay randomly on the map.\n");
			ft_printf("Please only use :\n-d or -D (to get Danny)\n-r or -R (to get Rusty)\n-l or -L (to get Linus)\n-b or -B (to get Basher)\n");
			ft_printf("Notice that the first option you write wil be the character you will play at the start between all the characters selected.\n");
			if (available_character)
				free(available_character);
			exit (EXIT_FAILURE);
		}
	}
	return (available_character);
}
