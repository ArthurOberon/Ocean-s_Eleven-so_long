/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:20:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/16 02:52:25 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_iframes(t_window *window, t_player *player,
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

	if (player->player_character == e_bomber)
	{
		bomb_pos.x = player->player_pos.x
			+ (CHUNK_SIZE * player->player_look_dir.x);
		bomb_pos.y = player->player_pos.y
			+ (CHUNK_SIZE * player->player_look_dir.y);
		put_image_to_image(&window->img, bomb_pos,
			&(sprite->sprite_img)[sprite->frame]);
	}
}

static void	display_pattern_box(t_game *game, int player_pos,
	t_sprite *sprite, int size)
{
	int			i;
	int			j;
	int			pos;
	t_vector_2	f_pos;

	i = -size + 1;
	while (i < size)
	{
		j = -size + 1;
		while (j < size)
		{
			if (i != 0 || j != 0)
			{
				pos = player_pos + (i + (j * game->level->map_vector.x));
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
	int			player_pos;

	if (player->player_character == e_thief)
	{
		player_pos = player->player_chunk_pos.x
			+ (player->player_chunk_pos.y * game->level->map_vector.x);
		display_pattern_box(game, player_pos, sprite, 2);
	}
}

void	display_player(t_game *game, t_window *window, t_player *player,
	t_sprite *sprite)
{
	display_iframes(window, player, sprite);
	display_aim_bomb(window, player, sprite);
	display_area_pickpocketable(game, player, sprite);
}
