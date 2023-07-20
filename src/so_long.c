/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:21:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 12:55:33 by aoberon          ###   ########.fr       */
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
	if (!parse_map(argv[argc_index], &(game.level->map),
			&(game.level->map_vector)))
		return (free(available_character), free(game.level), 1);
	game.level->nb_cases = game.level->map_vector.x * game.level->map_vector.y;
	if (!pathfinding(&game))
		return (free(available_character), 1);
	init_game(&game, available_character, chosen_character);
	start_game(&game);
	return (0);

	// delete inutile files & printf (<stdio.h>)
}
