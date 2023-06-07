/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider_check_tile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:59:08 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 23:07:02 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Check if the tile is a collectible, and collect it if it is.
 * 
 * @param game game struct, used to get the level and gameplay structs.
 * @param tile tile to check.
 * @param pos position of the tile.
 * @return int 1 if the tile is a collectible, 0 if not.
 */
static int	check_tile_collectible(t_game *game, char tile, int pos)
{
	if (tile == 'C')
	{
		game->level->map[pos] = '0';
		if (game->gameplay->nb_collect_remain > 0)
		{
			game->gameplay->nb_collect_get += 1;
			game->gameplay->nb_collect_remain -= 1;
			game->gameplay->is_display_plus_one = true;
		}
		game->window->map_sprites[pos] = game->assets->ground;
		return (1);
	}
	return (0);
}

/**
 * @brief Check if the tile is an exit,
 * and exit the game if it is and the player has collected all the collectibles.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param tile tile to check.
 * @return int 0 if the tile is not an exit.
 */
static int	check_tile_exit(t_game *game, char tile)
{
	if (tile == 'E')
	{
		if (game->gameplay->nb_collect_remain == 0)
		{
			ft_printf("SUCCESS !\n");
			close_game(game);
		}
	}
	return (0);
}

/**
 * @brief Check if the tile is a character,
 * and add the character to the available character if it is.
 * 
 * @param game game struct, used to get the gameplay struct.
 * @param tile tile to check.
 * @param pos position of the tile.
 */
static void	check_tile_character(t_game *game, char tile, int pos)
{
	if (tile == 'D' || tile == 'R' || tile == 'L' || tile == 'B')
	{
		if (tile == 'D')
			game->gameplay->available_character[e_main] = 3;
		else if (tile == 'R')
			game->gameplay->available_character[e_eater] = 3;
		else if (tile == 'L')
			game->gameplay->available_character[e_thief] = 3;
		else if (tile == 'B')
			game->gameplay->available_character[e_bomber] = 3;
		game->level->map[pos] = '0';
	}
}

/**
 * @brief Check the tile and do the corresponding action.
 * 
 * @param game game struct, used to get the level and gameplay struct.
 * @param tile tile to check.
 * @param pos position of the tile.
 */
void	check_tile(t_game *game, char tile, int pos)
{
	if (check_tile_collectible(game, tile, pos))
		return ;
	else if (check_tile_exit(game, tile))
		return ;
	else
		check_tile_character(game, tile, pos);
}
