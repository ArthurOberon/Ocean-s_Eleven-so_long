/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_helper_walls.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:43:42 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 10:46:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Init the walls sprites assets, part 1.
 * 
 * @param game game struct.
 * @param assets assets struct, where the walls sprites assets are stored.
 */
static void	init_sprites_assets_walls_part_1(t_game *game,
	t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->wall_corner_n_e,
		(t_init_sprite_asset_args){PATH_WALL_CORNER_N_E, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_corner_n_w,
		(t_init_sprite_asset_args){PATH_WALL_CORNER_N_W, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_corner_s_w,
		(t_init_sprite_asset_args){PATH_WALL_CORNER_S_W, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_corner_s_e,
		(t_init_sprite_asset_args){PATH_WALL_CORNER_S_E, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_up,
		(t_init_sprite_asset_args){PATH_WALL_NORTH, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_down,
		(t_init_sprite_asset_args){PATH_WALL_SOUTH, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_left,
		(t_init_sprite_asset_args){PATH_WALL_WEST, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_right,
		(t_init_sprite_asset_args){PATH_WALL_EAST, FRAME_WALL,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

/**
 * @brief Init the walls sprites assets, part 2.
 * 
 * @param game game struct.
 * @param assets assets struct, where the walls sprites assets are stored.
 */
static void	init_sprites_assets_walls_part_2(t_game *game,
	t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->wall_roulette,
		(t_init_sprite_asset_args){PATH_WALL_ROULETTE, FRAME_WALL_ROULETTE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_blackjack,
		(t_init_sprite_asset_args){PATH_WALL_BLACKJACK, FRAME_WALL_BLACKJACK,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

/**
 * @brief Init the walls sprites assets.
 * 
 * @param game game struct.
 * @param assets assets struct, where the walls sprites assets are stored.
 */
void	init_sprites_assets_walls(t_game *game, t_sprites_assets *assets)
{
	init_sprites_assets_walls_part_1(game, assets);
	init_sprites_assets_walls_part_2(game, assets);
}
