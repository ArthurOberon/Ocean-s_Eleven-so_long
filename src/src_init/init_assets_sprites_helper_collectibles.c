/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_helper_collectibles.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:41:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 20:39:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_sprites_assets_collectibles_part_1(t_game *game,
	t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->collectible_idle,
		(t_init_sprite_asset_args){PATH_COLLECT_IDLE,
		FRAME_COLLECT_IDLE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_0,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_0,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_1,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_1,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_2,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_2,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_3,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_3,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_4,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_4,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_5,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_5,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

static void	init_sprites_assets_collectibles_part_2(t_game *game,
	t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->collectible_open_6,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_6,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_7,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_7,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_8,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_8,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collectible_open_9,
		(t_init_sprite_asset_args){PATH_COLLECT_OPEN_9,
		FRAME_COLLECT_OPEN, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

void	init_sprites_assets_collectibles(t_game *game, t_sprites_assets *assets)
{
	// not commented
	init_sprites_assets_collectibles_part_1(game, assets);
	init_sprites_assets_collectibles_part_2(game, assets);
}
