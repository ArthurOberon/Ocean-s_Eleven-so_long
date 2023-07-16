/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_helper_others.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:43:27 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 18:30:07 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// not commented

static void	init_sprite_assets_guards(t_game *game, t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->guard_idle,
		(t_init_sprite_asset_args){PATH_GUARD_IDLE, FRAME_GUARD_IDLE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->guard_move_up,
		(t_init_sprite_asset_args){PATH_GUARD_MOVE_UP, FRAME_GUARD_MOVE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->guard_move_down,
		(t_init_sprite_asset_args){PATH_GUARD_MOVE_DOWN, FRAME_GUARD_MOVE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->guard_move_left,
		(t_init_sprite_asset_args){PATH_GUARD_MOVE_LEFT, FRAME_GUARD_MOVE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->guard_move_right,
		(t_init_sprite_asset_args){PATH_GUARD_MOVE_RIGHT, FRAME_GUARD_MOVE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->guard_fov,
		(t_init_sprite_asset_args){PATH_GUARD_FOV,
		FRAME_GUARD_FOV, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	// TO DELETE
	init_one_sprite_asset(game, &assets->guard,
		(t_init_sprite_asset_args){PATH_GUARD_IDLE, 1,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

static void	init_sprite_assets_big_images(t_game *game,
	t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->title_screen,
		(t_init_sprite_asset_args){PATH_TITLE_SCREEN, FRAME_TITLE_SCREEN,
		(t_vector_2){WINDOW_WIDTH, WINDOW_HEIGHT}});
	init_one_sprite_asset(game, &assets->tutorial,
		(t_init_sprite_asset_args){PATH_TUTORIAL, FRAME_TUTORIAL,
		(t_vector_2){WINDOW_WIDTH, WINDOW_HEIGHT}});
	init_one_sprite_asset(game, &assets->background,
		(t_init_sprite_asset_args){PATH_BACKGROUND, FRAME_BACKGROUND,
		(t_vector_2){WINDOW_WIDTH, WINDOW_HEIGHT}});
	init_one_sprite_asset(game, &assets->lose_screen,
		(t_init_sprite_asset_args){PATH_LOSE_SCREEN, FRAME_LOSE_SCREEN,
		(t_vector_2){WINDOW_WIDTH, WINDOW_HEIGHT}});
	init_one_sprite_asset(game, &assets->win_screen,
		(t_init_sprite_asset_args){PATH_WIN_SCREEN, FRAME_WIN_SCREEN,
		(t_vector_2){WINDOW_WIDTH, WINDOW_HEIGHT}});
}

static void	init_sprites_assets_others_(t_game *game, t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->ground,
		(t_init_sprite_asset_args){PATH_GROUND, FRAME_GROUND,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->exit,
		(t_init_sprite_asset_args){PATH_EXIT, FRAME_EXIT,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->dynamite,
		(t_init_sprite_asset_args){PATH_DYNAMITE, FRAME_DYNAMITE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->explosion,
		(t_init_sprite_asset_args){PATH_EXPLOSION, FRAME_EXPLOSION,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->area_qte,
		(t_init_sprite_asset_args){PATH_AREA_QTE, FRAME_AREA_QTE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->qte,
		(t_init_sprite_asset_args){PATH_QTE, FRAME_QTE,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

void	init_sprites_assets_others(t_game *game, t_sprites_assets *assets)
{
	init_sprite_assets_guards(game, assets);
	init_sprite_assets_big_images(game, assets);
	init_sprites_assets_others_(game, assets);
}
