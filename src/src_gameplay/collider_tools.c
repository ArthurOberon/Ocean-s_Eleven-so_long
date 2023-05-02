/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:31:49 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/02 18:36:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

double	double_modulo(double x, double y)
{
	return (x - ((int)(x / y) *x));
}

// get_tile -> not use
char	get_tile(int x, int y, char *map, int x_max)
{
	return (map[x + (y * x_max)]);
}

void	get_tile_number(int *pos_tile, int x, int y, int x_max)
{
	*pos_tile = x + (y * x_max);
}

void	check_tile_wall(char tile, double *move)
{
	if (tile == '1')
	{
		if (move != NULL)
			*move = *move - double_modulo(*move, CHUNK_SIZE);
	}
}

void	check_tile(char tile, int pos, t_game *game)
{
	if (tile == 'C')
	{
		game->level->map[pos] = '0';
		if (game->gameplay->nb_collect > 0)
			game->gameplay->nb_collect -= 1;
		game->window->map_sprites[pos] = game->assets->ground;
	}
	else if (tile == 'E')
	{
		if (game->gameplay->nb_collect == 0)
		{
			ft_putstr("SUCCESS !\n");
			close_window(game->window);
			free_game(*game, NULL);
			exit(EXIT_SUCCESS);
		}
	}
}
