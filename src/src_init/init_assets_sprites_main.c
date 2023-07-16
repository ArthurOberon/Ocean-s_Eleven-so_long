/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_main.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:19:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 18:25:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Init all sprites assets of the game.
 * 
 * @param game game struct, used to get the sprites_assets struct to initialize.
 */
void	init_sprites_assets(t_game *game)
{
	t_sprites_assets	*assets;

	assets = ft_calloc(sizeof(t_sprites_assets), 1);
	if (!assets)
		exit_game(*game, "Error of malloc.\n");
	game->assets = assets;
	init_sprites_assets_walls(game, assets);
	init_sprites_assets_ui_text_box(game, assets);
	init_sprites_assets_player(game, assets);
	init_sprites_assets_others(game, assets);
	init_sprites_assets_collectibles(game, assets);
}
