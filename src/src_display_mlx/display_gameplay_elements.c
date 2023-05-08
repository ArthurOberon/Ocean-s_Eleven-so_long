/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gameplay_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/08 23:25:23 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	bomb_patern_corner(t_game *game, t_bomb bomb, int i)
{
	int	n_w;
	int	n_e;
	int	s_w;
	int	s_e;

	if (i - 1 > 0)
	{
		n_w = bomb.bomb_chunk_pos - ((i - 1) + ((i - 1) * game->level->map_vector.x));
		n_e = bomb.bomb_chunk_pos + ((i - 1) - ((i - 1) * game->level->map_vector.x));
		s_w = bomb.bomb_chunk_pos - ((i - 1) - ((i - 1) * game->level->map_vector.x));
		s_e = bomb.bomb_chunk_pos + ((i - 1) + ((i - 1) * game->level->map_vector.x));
		if (game->level->map[n_w] == '1')
		{
			game->level->map[n_w] = '0';
			game->window->map_sprites[n_w] = game->assets->ground;
		}
		if (game->level->map[n_e] == '1')
		{
			game->level->map[n_e] = '0';
			game->window->map_sprites[n_e] = game->assets->ground;
		}
		if (game->level->map[s_w] == '1')
		{
			game->level->map[s_w] = '0';
			game->window->map_sprites[s_w] = game->assets->ground;
		}
		if (game->level->map[s_e] == '1')
		{
			game->level->map[s_e] = '0';
			game->window->map_sprites[s_e] = game->assets->ground;
		}
	}
}

static void	bomb_patern_cross(t_game *game, t_bomb bomb, int i)
{
	if (game->level->map[bomb.bomb_chunk_pos - (i * game->level->map_vector.x)] == '1')
	{
		game->level->map[bomb.bomb_chunk_pos - (i * game->level->map_vector.x)] = '0';
		game->window->map_sprites[bomb.bomb_chunk_pos - (i * game->level->map_vector.x)] = game->assets->ground;
	}
	if (game->level->map[bomb.bomb_chunk_pos + (i * game->level->map_vector.x)] == '1')
	{
		game->level->map[bomb.bomb_chunk_pos + (i * game->level->map_vector.x)] = '0';
		game->window->map_sprites[bomb.bomb_chunk_pos + (i * game->level->map_vector.x)] = game->assets->ground;
	}
	if (game->level->map[bomb.bomb_chunk_pos - i] == '1')
	{
		game->level->map[bomb.bomb_chunk_pos - i] = '0';
		game->window->map_sprites[bomb.bomb_chunk_pos - i] = game->assets->ground;
	}
	if (game->level->map[bomb.bomb_chunk_pos + i] == '1')
	{
		game->level->map[bomb.bomb_chunk_pos + i] = '0';
		game->window->map_sprites[bomb.bomb_chunk_pos + i] = game->assets->ground;
	}
}

static void	bomb_patern_box(t_game *game, t_bomb bomb, int o)
{
	int	i;
	int j;
	int	pos;

	i = -bomb.bomb_plant + 2;
	while (i < bomb.bomb_plant - 1)
	{
		j = -bomb.bomb_plant + 2;
		while (j < bomb.bomb_plant - 1)
		{
			pos = bomb.bomb_chunk_pos + (j - (i * game->level->map_vector.x));
			if (game->level->map[pos] == '1')
			{
				game->level->map[pos] = '0';
				game->window->map_sprites[pos] = game->assets->ground;
			}
			printf("i : [%d] j : [%d]\n", i , j);
			j++;
		}
		i++;
	}
	
}

static void	bomb_patern_circle(t_game *game, t_bomb bomb, int size)
{
	int	i;
	int	l;
	int	j;
	int	k;
	int pos;

	i = 0;
	k = 0;
	j = -(size - 1);
	while (j < size)
	{
			k = -(j + size - 1);
			l = (j + size);
			while (k < l && l <= size)
			{
				i = size - (size - k);
				pos = bomb.bomb_chunk_pos - (i - (j * game->level->map_vector.x));
				if (game->level->map[pos] == '1')
				{
					game->level->map[pos] = '0';
					game->window->map_sprites[pos] = game->assets->ground;
				}
				k++;
			}
			l = (j - size);
			k = -(j - size + 1);
			while (k > l && l > -size)
			{
				i = size - (size + k);
				pos = bomb.bomb_chunk_pos - (i - (j * game->level->map_vector.x));
				if (game->level->map[pos] == '1')
				{
					game->level->map[pos] = '0';
					game->window->map_sprites[pos] = game->assets->ground;
				}
				k--;
			}
		j++;
	}

}

static void	bomb_explosion(t_game *game, t_bomb bomb)
{
	int	i;

	i = 0;
	if (bomb.bomb_plant == 1)
	{
		game->level->map[bomb.bomb_chunk_pos] = '0';
		game->window->map_sprites[bomb.bomb_chunk_pos] = game->assets->ground;
		return ;
	}
	bomb_patern_circle(game, bomb, bomb.bomb_plant);
}

static void display_bomb(t_player *player, t_game *game, t_window *window)
{
	if (player->bomb.bomb_plant > 0)
	{
		if (player->bomb.bomb_chunk_pos == -1)
		{
			player->bomb.bomb_chunk_pos = pos_to_chunk(player->player_pos.x + (player->size.x / 2), player->player_pos.y + (player->size.y / 2), game->level->map_vector.x);
			player->bomb.bomb_chunk_pos += 1;
			// player->bomb.bomb_chunk_pos += player->player_look_dir.x;
			// player->bomb.bomb_chunk_pos += player->player_look_dir.y * game->level->map_vector.x;
			player->bomb.bomb_pos = chunk_to_pixel_pos(player->bomb.bomb_chunk_pos, game->level->map_vector.x);
		}
		put_image_to_image(window, player->bomb.bomb_pos, &(window->map_sprites[game->level->nb_cases]->sprite_img)[0]);
		player->bomb.time = clock();
		// printf("time : [%f]\n", player->bomb.time / CLOCKS_PER_SEC);
		// printf("last : [%f]\n\n", player->bomb.last_time / CLOCKS_PER_SEC);
		if (((player->bomb.time - player->bomb.last_time) / CLOCKS_PER_SEC) >= 0.5)
		{
			bomb_explosion(game, player->bomb);
			player->bomb.bomb_total -= player->bomb.bomb_plant;
			player->bomb.bomb_plant = 0;
			player->bomb.bomb_chunk_pos = -1;
			player->bomb.bomb_pos.x = -1;
			player->bomb.bomb_pos.y = -1;
		}
	}
}

void	display_gameplay_elements(t_game *game, t_window *window)
{
	if (game->gameplay->nb_collect == 0)
		window->map_sprites[game->level->exit_pos] = game->assets->collect;
	display_bomb(game->gameplay->player, game, window);
}
