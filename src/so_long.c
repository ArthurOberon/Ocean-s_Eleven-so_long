/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:21:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/26 15:37:12 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	multiples_maps(char **argv)
// {
// 	if (argv[1][0] == '-' && argv[1][1] == 'm')
// 	{
// 		// check number of multiples maps.
// 		// check if each maps are valids.
// 		// save each maps in a list.
// 		printf("multiple maps\n");
// 		return (2);
// 	}
// 	return (1);
// }

int	main(int argc, char **argv)
{
	int		argc_map;
	int		available_character[4];
	int		chosen_character;
	t_game	game;

	if (argc < 2)
		exit_arg_error();
	argc_map = 1;
	chosen_character = e_main;
	available_character[0] = 1;
	available_character[1] = 1;
	available_character[2] = 1;
	available_character[3] = 1;
	while (argv[argc_map][0] == '-'
		&& ((argv[argc_map][1] == 'd' || argv[argc_map][1] == 'D')
		|| (argv[argc_map][1] == 'r' || argv[argc_map][1] == 'R')
		|| (argv[argc_map][1] == 'l' || argv[argc_map][1] == 'L')
		|| (argv[argc_map][1] == 'b' || argv[argc_map][1] == 'B')))
	{
		if (argc_map == 1)
			ft_bzero(available_character, sizeof(int) * 4);
		if (argv[argc_map][1] == 'd' || argv[argc_map][1] == 'D')
		{
			if (argc_map == 1)
				chosen_character = e_main;
			available_character[e_main] = 1;
			argc_map += 1;
		}
		if (argv[argc_map][1] == 'r' || argv[argc_map][1] == 'R')
		{
			if (argc_map == 1)
				chosen_character = e_eater;
			available_character[e_eater] = 1;
			argc_map += 1;
		}
		if (argv[argc_map][1] == 'l' || argv[argc_map][1] == 'L')
		{
			if (argc_map == 1)
				chosen_character = e_thief;
			available_character[e_thief] = 1;
			argc_map += 1;
		}
		if (argv[argc_map][1] == 'b' || argv[argc_map][1] == 'B')
		{
			if (argc_map == 1)
				chosen_character = e_bomber;
			available_character[e_bomber] = 1;
			argc_map += 1;
		}
	}
	bzero_game(&game);
	parse_map(argv[argc_map], &(game.level->map), &(game.level->map_vector));
	game.level->nb_cases = game.level->map_vector.x * game.level->map_vector.y;
	if (IS_DEBUG)
	{
		printf("Map 1 line : %s\n", game.level->map);
		ft_print_1d_to_2d(game.level);
	}
	pathfinding(&game);
	init_game(&game, available_character, chosen_character);
	start_game(&game);
	free_game(game, NULL);
	return (0);
}
