/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_helper_player.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:43:35 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 14:27:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// not commented

static void	init_sprites_assets_danny(t_game *game, t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->player_danny_idle,
		(t_init_sprite_asset_args){PATH_PLAYER_DANNY_IDLE, FRAME_PLAYER_IDLE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_danny_move_up,
		(t_init_sprite_asset_args){PATH_PLAYER_DANNY_MOVE_UP,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_danny_move_down,
		(t_init_sprite_asset_args){PATH_PLAYER_DANNY_MOVE_DOWN,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_danny_move_left,
		(t_init_sprite_asset_args){PATH_PLAYER_DANNY_MOVE_LEFT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_danny_move_right,
		(t_init_sprite_asset_args){PATH_PLAYER_DANNY_MOVE_RIGHT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

static void	init_sprites_assets_rusty(t_game *game, t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->player_rusty_idle,
		(t_init_sprite_asset_args){PATH_PLAYER_RUSTY_IDLE, FRAME_RUSTY_IDLE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_rusty_move_up,
		(t_init_sprite_asset_args){PATH_PLAYER_RUSTY_MOVE_UP,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_rusty_move_down,
		(t_init_sprite_asset_args){PATH_PLAYER_RUSTY_MOVE_DOWN,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_rusty_move_left,
		(t_init_sprite_asset_args){PATH_PLAYER_RUSTY_MOVE_LEFT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_rusty_move_right,
		(t_init_sprite_asset_args){PATH_PLAYER_RUSTY_MOVE_RIGHT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

static void	init_sprites_assets_linus(t_game *game, t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->player_linus_idle,
		(t_init_sprite_asset_args){PATH_PLAYER_LINUS_IDLE, FRAME_PLAYER_IDLE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_linus_move_up,
		(t_init_sprite_asset_args){PATH_PLAYER_LINUS_MOVE_UP,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_linus_move_down,
		(t_init_sprite_asset_args){PATH_PLAYER_LINUS_MOVE_DOWN,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_linus_move_left,
		(t_init_sprite_asset_args){PATH_PLAYER_LINUS_MOVE_LEFT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_linus_move_right,
		(t_init_sprite_asset_args){PATH_PLAYER_LINUS_MOVE_RIGHT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

static void	init_sprites_assets_basher(t_game *game, t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->player_basher_idle,
		(t_init_sprite_asset_args){PATH_PLAYER_BASHER_IDLE, FRAME_PLAYER_IDLE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_basher_move_up,
		(t_init_sprite_asset_args){PATH_PLAYER_BASHER_MOVE_UP,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_basher_move_down,
		(t_init_sprite_asset_args){PATH_PLAYER_BASHER_MOVE_DOWN,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_basher_move_left,
		(t_init_sprite_asset_args){PATH_PLAYER_BASHER_MOVE_LEFT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_basher_move_right,
		(t_init_sprite_asset_args){PATH_PLAYER_BASHER_MOVE_RIGHT,
		FRAME_PLAYER_MOVE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

void	init_sprites_assets_player(t_game *game, t_sprites_assets *assets)
{
	init_sprites_assets_danny(game, assets);
	init_sprites_assets_rusty(game, assets);
	init_sprites_assets_linus(game, assets);
	init_sprites_assets_basher(game, assets);
}
