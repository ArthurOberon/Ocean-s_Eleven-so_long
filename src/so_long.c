/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:21:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/20 16:01:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_arg_error();
	if (!parse_map(argv[1], &(game.level.map), &(game.level.map_vector)))
		exit_map_error();
	printf("Map 1 line : %s\n", game.level.map);
	pathfinding(game.level);
	free(game.level.map);
	return (0);
}
