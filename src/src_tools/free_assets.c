/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:03:52 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 09:45:10 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief free a one t_sprite struct.
 * 
 * @param ptr mlx_ptr, used to destroy the mlx_img of the sprite.
 * @param sprite sprite struct to free.
 */
void	free_one_sprite(void *ptr, t_sprite *sprite)
{
	int	i;

	i = 0;
	if (!sprite)
		return ;
	while (i < sprite->size)
	{
		if (sprite->sprite_img[i].mlx_img)
			mlx_destroy_image(ptr, sprite->sprite_img[i].mlx_img);
		i++;
	}
	free(sprite->sprite_img);
	free(sprite);
}

/**
 * @brief Free the t_sprites_assets struct, part 1.
 * 
 * @param ptr mlx_ptr, used to destroy the mlx_img of the sprites.
 * @param assets assets struct to free.
 */
static void	free_assets_part_1(void *ptr, t_sprites_assets *assets)
{
	free_one_sprite(ptr, assets->wall_corner_n_w);
	free_one_sprite(ptr, assets->wall_corner_n_e);
	free_one_sprite(ptr, assets->wall_corner_s_e);
	free_one_sprite(ptr, assets->wall_corner_s_w);
	free_one_sprite(ptr, assets->wall_side_up);
	free_one_sprite(ptr, assets->wall_side_down);
	free_one_sprite(ptr, assets->wall_side_left);
	free_one_sprite(ptr, assets->wall_side_right);
	free_one_sprite(ptr, assets->wall_roulette);
	free_one_sprite(ptr, assets->wall_blackjack);
	free_one_sprite(ptr, assets->collectible_idle);
	free_one_sprite(ptr, assets->collectible_open_0);
	free_one_sprite(ptr, assets->collectible_open_1);
	free_one_sprite(ptr, assets->collectible_open_2);
	free_one_sprite(ptr, assets->collectible_open_3);
	free_one_sprite(ptr, assets->collectible_open_4);
	free_one_sprite(ptr, assets->collectible_open_5);
	free_one_sprite(ptr, assets->collectible_open_6);
	free_one_sprite(ptr, assets->collectible_open_7);
	free_one_sprite(ptr, assets->collectible_open_8);
	free_one_sprite(ptr, assets->collectible_open_9);
	free_one_sprite(ptr, assets->ground);
	free_one_sprite(ptr, assets->exit);
	free_one_sprite(ptr, assets->player_danny_idle);
	free_one_sprite(ptr, assets->player_danny_move_up);
}

/**
 * @brief Free the t_sprites_assets struct, part 2.
 * 
 * @param ptr mlx_ptr, used to destroy the mlx_img of the sprites.
 * @param assets assets struct to free. 
 */
static void	free_assets_part_2(void *ptr, t_sprites_assets *assets)
{
	free_one_sprite(ptr, assets->player_danny_move_down);
	free_one_sprite(ptr, assets->player_danny_move_left);
	free_one_sprite(ptr, assets->player_danny_move_right);
	free_one_sprite(ptr, assets->player_rusty_idle);
	free_one_sprite(ptr, assets->player_rusty_move_up);
	free_one_sprite(ptr, assets->player_rusty_move_down);
	free_one_sprite(ptr, assets->player_rusty_move_left);
	free_one_sprite(ptr, assets->player_rusty_move_right);
	free_one_sprite(ptr, assets->player_linus_idle);
	free_one_sprite(ptr, assets->player_linus_move_up);
	free_one_sprite(ptr, assets->player_linus_move_down);
	free_one_sprite(ptr, assets->player_linus_move_left);
	free_one_sprite(ptr, assets->player_linus_move_right);
	free_one_sprite(ptr, assets->player_basher_idle);
	free_one_sprite(ptr, assets->player_basher_move_up);
	free_one_sprite(ptr, assets->player_basher_move_down);
	free_one_sprite(ptr, assets->player_basher_move_left);
	free_one_sprite(ptr, assets->player_basher_move_right);
	free_one_sprite(ptr, assets->dynamite);
	free_one_sprite(ptr, assets->explosion);
	free_one_sprite(ptr, assets->area_qte);
	free_one_sprite(ptr, assets->qte);
	free_one_sprite(ptr, assets->guard_idle);
	free_one_sprite(ptr, assets->guard_move_up);
	free_one_sprite(ptr, assets->guard_move_down);
}

/**
 * @brief Free the t_sprites_assets struct, part 3.
 * 
 * @param ptr mlx_ptr, used to destroy the mlx_img of the sprites.
 * @param assets assets struct to free.
 */
static void	free_assets_part_3(void *ptr, t_sprites_assets *assets)
{
	free_one_sprite(ptr, assets->guard_move_left);
	free_one_sprite(ptr, assets->guard_move_right);
	free_one_sprite(ptr, assets->guard_fov);
	free_one_sprite(ptr, assets->button_pause);
	free_one_sprite(ptr, assets->button_reset);
	free_one_sprite(ptr, assets->button_quit);
	free_one_sprite(ptr, assets->button_tutorial);
	free_one_sprite(ptr, assets->plus_one);
	free_one_sprite(ptr, assets->heart);
	free_one_sprite(ptr, assets->box);
	free_one_sprite(ptr, assets->selection_box);
	free_one_sprite(ptr, assets->avatar_character);
	free_one_sprite(ptr, assets->alphabet);
	free_one_sprite(ptr, assets->special_character);
	free_one_sprite(ptr, assets->background_text);
	free_one_sprite(ptr, assets->talking_danny);
	free_one_sprite(ptr, assets->talking_rusty);
	free_one_sprite(ptr, assets->talking_linus);
	free_one_sprite(ptr, assets->talking_basher);
	free_one_sprite(ptr, assets->title_screen);
	free_one_sprite(ptr, assets->tutorial);
	free_one_sprite(ptr, assets->lose_screen);
	free_one_sprite(ptr, assets->win_screen);
	free_one_sprite(ptr, assets->background);
}

/**
 * @brief free all the assets of the game.
 * 
 * @param ptr mlx_ptr, used to destroy the mlx_img of the sprites.
 * @param assets assets struct to free.
 */
void	free_assets(void *ptr, t_sprites_assets *assets)
{
	free_assets_part_1(ptr, assets);
	free_assets_part_2(ptr, assets);
	free_assets_part_3(ptr, assets);
	free(assets);
}
