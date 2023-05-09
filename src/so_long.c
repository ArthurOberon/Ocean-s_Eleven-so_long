/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:21:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/09 18:28:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_arg_error();
	bzero_game(&game);
	parse_map(argv[1], &(game.level->map), &(game.level->map_vector));
	game.level->nb_cases = game.level->map_vector.x * game.level->map_vector.y;
	if (IS_DEBUG)
	{
		printf("Map 1 line : %s\n", game.level->map);
		ft_print_1d_to_2d(game.level);
	}
	pathfinding(&game);
	init_game(&game);
	ft_print_1d_to_2d(game.level);
	display(&game);
	free_game(game, NULL);
	return (0);
}
