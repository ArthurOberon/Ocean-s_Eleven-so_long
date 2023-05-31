/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:20:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/31 18:48:18 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	display_aim_bomb(t_window *window, t_player *player,
	t_sprite *sprite)
{
	t_vector_2	bomb_pos;

	if (player->player_character == e_bomber && player->bomb.bomb_plant == 0)
	{
		bomb_pos.x = player->player_pos.x
			+ (CHUNK_SIZE * player->player_look_dir.x);
		bomb_pos.y = player->player_pos.y
			+ (CHUNK_SIZE * player->player_look_dir.y);
		put_image_to_image(&window->img, bomb_pos,
			&(sprite->sprite_img)[sprite->frame]);
	}
}

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

static void	display_area_pickpocketable(t_game *game, t_player *player,
	t_sprite *sprite)
{
	if (player->player_character == e_thief
		&& player->qte.is_pickpocketing == false)
	{
		display_pattern_box(game, sprite, 2);
	}
}

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
