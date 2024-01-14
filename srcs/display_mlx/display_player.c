/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:20:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/23 11:25:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief display the player, normally or flashing if the player is invincible.
 * 
 * @param window window struct, used to display on.
 * @param player player struct, used to get the player position and iframes info.
 * @param sprite sprite struct, used to get the sprite of the player.
 */
static void	display_player_on_window(t_window *window, t_player *player,
	t_sprite *sprite)
{
	if (player->iframes == true)
	{
		if (player->iframes_flashing == 2)
		{
			put_image_to_image(&window->img, player->player_pos,
				&(sprite->sprite_img)[sprite->frame]);
			player->iframes_flashing = 0;
		}
		else
			player->iframes_flashing++;
	}
	else
		put_image_to_image(&window->img, player->player_pos,
			&(sprite->sprite_img)[sprite->frame]);
}

/**
 * @brief display the bomb depending on the player look direction,
 * if the player character is bomber and the bomb is not planted.
 * 
 * @param window window struct, used to display on.
 * @param player player struct, used to get the player position
 * and look direction.
 * @param sprite sprite struct, used to get the sprite of the bomb.
 */
static void	display_aim_bomb(t_window *window, t_player *player,
	t_sprite *sprite)
{
	t_vector_2	bomb_pos;

	if (player->player_character == e_bomber && player->bomb.bomb_plant == 0
		&& player->bomb.bomb_total > 0)
	{
		bomb_pos.x = player->player_pos.x
			+ (CHUNK_SIZE * player->player_look_dir.x);
		bomb_pos.y = player->player_pos.y
			+ (CHUNK_SIZE * player->player_look_dir.y);
		put_image_to_image(&window->img, bomb_pos,
			&(sprite->sprite_img)[sprite->frame]);
	}
}

/**
 * @brief display a pattern of a box, depending on the size.
 * 
 * @param game game struct, used to get window and gameplay structs.
 * @param sprite sprite struct, used to get the sprite of the box.
 * @param size size of the box.
 */
static void	display_pattern_box(t_game *game, t_sprite *sprite, int size)
{
	int			i;
	int			j;
	t_vector_2	f_pos;

	i = -size + 1;
	while (i < size)
	{
		j = -size + 1;
		while (j < size)
		{
			if (i != 0 || j != 0)
			{
				f_pos.x = game->gameplay->player->player_pos.x
					+ (CHUNK_SIZE * i);
				f_pos.y = game->gameplay->player->player_pos.y
					+ (CHUNK_SIZE * j);
				put_image_to_image(&game->window->img,
					f_pos,
					&(sprite->sprite_img)[sprite->frame]);
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Display area where player can pickpocket
 * if the player character is thief and is not pickpocketing.
 *
 * @param game game struct, used to get window and gameplay struct.
 * @param player player struct, used to get player info.
 * @param sprite sprite struct, used to get the sprite of the area.
 */
static void	display_area_pickpocketable(t_game *game, t_player *player,
	t_sprite *sprite)
{
	if (player->player_character == e_thief
		&& player->qte.is_pickpocketing == false)
	{
		display_pattern_box(game, sprite, 2);
	}
}

/**
 * @brief Display player on the window.
 * 
 * @param game game struct, used to get camera and sprite_assets info.
 * @param window window struct, used to display on.
 * @param player player struct, used to display and his features.
 * @param sprite sprite struct, used to get the player sprite.
 */
void	display_player(t_game *game, t_window *window, t_player *player,
	t_sprite *sprite)
{
	t_vector_2	pos_tmp;

	pos_tmp = player->player_pos;
	player->player_pos.x = player->player_pos.x - game->camera->camera_f_pos.x;
	player->player_pos.y = player->player_pos.y - game->camera->camera_f_pos.y;
	player->player_pos.x = player->player_pos.x
		- (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_X)) / 2;
	player->player_pos.y = player->player_pos.y
		- (CHUNK_SIZE - (CHUNK_SIZE * RATIO_PLAYER_SIZE_Y)) / 2;
	display_player_on_window(window, player, sprite);
	display_aim_bomb(window, player, game->assets->dynamite);
	display_area_pickpocketable(game, player, game->assets->area_qte);
	player->player_pos = pos_tmp;
}
