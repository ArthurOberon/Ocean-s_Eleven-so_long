/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_available_character.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:53:58 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/06 14:28:57 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set one available character in the available_character array,
 * set the chosen_character if it's the first option
 * and increment argc_index.
 * 
 * @param argc_index 
 * @param available_character 
 * @param chosen_character 
 * @param character 
 */
static void	set_one_available_character(int *argc_index,
	int *available_character, int *chosen_character, int character)
{
	if (*argc_index == 1)
			*chosen_character = character;
		available_character[character] = 1;
		*argc_index += 1;
}

/**
 * @brief Check which character is in the argument.
 * 
 * @param argv arguments of the program.
 * @param argc_index index of the argument to check.
 * @param available_character available character array.
 * @param chosen_character first character chosen by the player,
 * and will be the one to start with.
 * @return int 
 */
static int	check_which_character(char **argv, int *argc_index,
	int *available_character, int *chosen_character)
{
	if (argv[*argc_index][1] == 'd' || argv[*argc_index][1] == 'D')
	{
		set_one_available_character(argc_index, available_character,
			chosen_character, e_main);
	}
	else if (argv[*argc_index][1] == 'r' || argv[*argc_index][1] == 'R')
	{
		set_one_available_character(argc_index, available_character,
			chosen_character, e_eater);
	}
	else if (argv[*argc_index][1] == 'l' || argv[*argc_index][1] == 'L')
	{
		set_one_available_character(argc_index, available_character,
			chosen_character, e_thief);
	}
	else if (argv[*argc_index][1] == 'b' || argv[*argc_index][1] == 'B')
	{
		set_one_available_character(argc_index, available_character,
			chosen_character, e_bomber);
	}
	else
		return (0);
	return (1);
}

/**
 * @brief Get the available character by checking the arguments.
 * And set the character the player will start with.
 * 
 * @param argv arguments of the program.
 * @param argc_index index of the argument to check.
	* @param chosen_character first character chosen by the player,
	* and will be the character the player will start with
	* between the available ones.
 * @return int* 
 */
int	*get_available_character(char **argv, int *argc_index,
	int *chosen_character)
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
	while (argv[*argc_index][0] == '-')
	{
		if (*argc_index == 1)
		{
			ft_bzero(available_character, sizeof(int) * 4);
		}
		check_error = check_which_character(argv, argc_index,
				available_character, chosen_character);
		if (check_error == 0)
		{
			exit_option_error(available_character);
		}
	}
	return (available_character);
}
