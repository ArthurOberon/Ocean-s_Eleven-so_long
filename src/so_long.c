/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:21:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/04 19:24:03 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		argc_map;
	int		chosen_character;
	int		*available_character;
	t_game	game;

	if (argc < 2)
		exit_arg_error();
	argc_map = 1;
	available_character = get_available_character(argv, &argc_map,
			&chosen_character);
	if (!available_character)
		return (1);
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
