/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:21:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 09:30:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		argc_index;
	int		chosen_character;
	int		*available_character;
	t_game	game;

	if (argc < 2)
		exit_arg_error();
	argc_index = 1;
	available_character = init_available_character(argv, &argc_index,
			&chosen_character);
	if (!available_character)
		return (1);
	bzero_game(&game);
	parse_map(argv[argc_index], &(game.level->map), &(game.level->map_vector));
	game.level->nb_cases = game.level->map_vector.x * game.level->map_vector.y;
	if (IS_DEBUG)
	{
		printf("Map 1 line : %s\n", game.level->map);
		ft_print_1d_to_2d(game.level);
	}
	pathfinding(&game);
	init_game(&game, available_character, chosen_character);
	start_game(&game);
	return (0);
}
