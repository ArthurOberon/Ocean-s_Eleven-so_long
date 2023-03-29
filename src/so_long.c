/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:21:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/29 14:31:07 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_tab_print_1d_to_2d(t_level level)
{
	int	i;
	int	j;

	j = 0;
	while (j < level.map_vector.y * level.map_vector.x)
	{
		i = 0;
		while (i < level.map_vector.x)
		{
			ft_putchar(level.map[i + j]);
			ft_putchar(' ');
			i++;
		}
		j += level.map_vector.x;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_arg_error();
	if (!parse_map(argv[1], &(game.level.map), &(game.level.map_vector)))
		exit_map_error();
	game.level.nb_cases = game.level.map_vector.x * game.level.map_vector.y;
	if (IS_DEBUG)
	{
		printf("Map 1 line : %s\n", game.level.map);
		char_tab_print_1d_to_2d(game.level);
	}
	pathfinding(&game);
	free(game.level.map);
	free(game.level.path_map);
	return (0);
}
