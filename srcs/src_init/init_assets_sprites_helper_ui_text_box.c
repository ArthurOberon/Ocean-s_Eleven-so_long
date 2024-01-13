/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_helper_ui_text_box.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:43:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 10:47:43 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Init the sprites assets for the ui, part 1.
 * 
 * @param game game struct.
 * @param assets assets struct, where the sprites assets are stored.
 */
static void	init_sprites_assets_ui_part_1(t_game *game,
	t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->button_pause,
		(t_init_sprite_asset_args){PATH_BUTTON_PAUSE, FRAME_MENU_BUTTON,
		(t_vector_2){CHUNK_SIZE * 2, CHUNK_SIZE * 2}});
	init_one_sprite_asset(game, &assets->button_reset,
		(t_init_sprite_asset_args){PATH_BUTTON_RESET, FRAME_MENU_BUTTON,
		(t_vector_2){CHUNK_SIZE * 2, CHUNK_SIZE * 2}});
	init_one_sprite_asset(game, &assets->button_quit,
		(t_init_sprite_asset_args){PATH_BUTTON_QUIT, FRAME_MENU_BUTTON,
		(t_vector_2){CHUNK_SIZE * 2, CHUNK_SIZE * 2}});
	init_one_sprite_asset(game, &assets->button_tutorial,
		(t_init_sprite_asset_args){PATH_BUTTON_TUTO, FRAME_MENU_BUTTON,
		(t_vector_2){CHUNK_SIZE * 2, CHUNK_SIZE * 2}});
}

/**
 * @brief Init the sprites assets for the ui, part 2.
 * 
 * @param game game struct.
 * @param assets assets struct, where the sprites assets are stored.
 */
static void	init_sprites_assets_ui_part_2(t_game *game,
	t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->plus_one,
		(t_init_sprite_asset_args){PATH_PLUS_ONE, FRAME_PLUS_ONE,
		(t_vector_2){CHUNK_SIZE / 2, CHUNK_SIZE / 2}});
	init_one_sprite_asset(game, &assets->heart,
		(t_init_sprite_asset_args){PATH_HEART, FRAME_HEART,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->box,
		(t_init_sprite_asset_args){PATH_BOX, FRAME_BOX,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->selection_box,
		(t_init_sprite_asset_args){PATH_SELECTION_BOX, FRAME_SELECTION_BOX,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->avatar_character,
		(t_init_sprite_asset_args){PATH_AVATAR_CHARACTER,
		FRAME_AVATAR_CHARACTER, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

/**
 * @brief Init the sprites assets for the text box.
 * 
 * @param game game struct.
 * @param assets assets struct, where the sprites assets are stored.
 */
static void	init_sprites_assets_text_box(t_game *game, t_sprites_assets *assets)
{
	init_one_sprite_asset(game, &assets->alphabet,
		(t_init_sprite_asset_args){PATH_ALPHABET, FRAME_ALPHABET,
		(t_vector_2){16, 16}});
	init_one_sprite_asset(game, &assets->special_character,
		(t_init_sprite_asset_args){PATH_SPECIAL_CHAR, FRAME_SPECIAL_CHAR,
		(t_vector_2){16, 16}});
	init_one_sprite_asset(game, &assets->background_text,
		(t_init_sprite_asset_args){PATH_BACKGROUND_TEXT, FRAME_BACKGROUND_TEXT,
		(t_vector_2){WINDOW_WIDTH - 40, WINDOW_HEIGHT / 4}});
	init_one_sprite_asset(game, &assets->talking_danny,
		(t_init_sprite_asset_args){PATH_TALKING_DANNY, FRAME_TALKING_CHARACTER,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->talking_rusty,
		(t_init_sprite_asset_args){PATH_TALKING_RUSTY, FRAME_TALKING_CHARACTER,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->talking_linus,
		(t_init_sprite_asset_args){PATH_TALKING_LINUS, FRAME_TALKING_CHARACTER,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->talking_basher,
		(t_init_sprite_asset_args){PATH_TALKING_BASHER, FRAME_TALKING_CHARACTER,
		(t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
}

/**
 * @brief Init the sprites assets for the ui and text box.
 * 
 * @param game game struct.
 * @param assets assets struct, where the sprites assets are stored.
 */
void	init_sprites_assets_ui_text_box(t_game *game, t_sprites_assets *assets)
{
	init_sprites_assets_ui_part_1(game, assets);
	init_sprites_assets_ui_part_2(game, assets);
	init_sprites_assets_text_box(game, assets);
}
