/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:52:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/09 18:45:10 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	explode_chunk(t_game *game, t_bomb bomb, int i, int j)
{
	int	pos;

	pos = bomb.bomb_chunk_pos - (i - (j * game->level->map_vector.x));
	if (game->level->map[pos] == '2')
	{
		game->level->map[pos] = '0';
		game->window->map_sprites[pos] = game->assets->ground;
	}
}

static void	bomb_pattern_circle(t_game *game, t_bomb bomb, int size)
{
	int	i;
	int	l;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = (-(size - 1)) - 1;
	while (++j < size)
	{
		k = -(j + size - 1);
		l = (j + size);
		while (k < l && l <= size)
		{
			i = size - (size - k++);
			explode_chunk(game, bomb, i, j);
		}
		l = (j - size);
		k = -(j - size + 1);
		while (k > l && l > -size)
		{
			i = size - (size + k--);
			explode_chunk(game, bomb, i, j);
		}
	}
}

static void	make_bomb_explode(t_game *game, t_bomb bomb)
{
	int	i;

	i = 0;
	if (bomb.bomb_plant == 1)
	{
		if (game->level->map[bomb.bomb_chunk_pos] == '2')
		{
			game->level->map[bomb.bomb_chunk_pos] = '0';
			game->window->map_sprites[bomb.bomb_chunk_pos]
				= game->assets->ground;
		}
		return ;
	}
	bomb_pattern_circle(game, bomb, bomb.bomb_plant);
}

// bomb->bomb_chunk_pos += player_look_dir.x;
// bomb->bomb_chunk_pos += player->player_look_dir.y
	// * game->level->map_vector.x;
void	display_bomb(t_player *player, t_bomb *bomb, t_game *game,
	t_window *window)
{
	if (bomb->bomb_plant <= 0)
		return ;
	if (bomb->bomb_chunk_pos == -1)
	{
		bomb->bomb_chunk_pos = pos_to_chunk(player->player_pos.x
				+ (player->size.x / 2), player->player_pos.y
				+ (player->size.y / 2), game->level->map_vector.x);
		bomb->bomb_chunk_pos += player->player_look_dir.x;
		bomb->bomb_chunk_pos += player->player_look_dir.y
			* game->level->map_vector.x;
		bomb->bomb_pos = chunk_to_pixel_pos(bomb->bomb_chunk_pos,
				game->level->map_vector.x);
	}
	put_image_to_image(window, bomb->bomb_pos,
		&(window->map_sprites[game->level->nb_cases]->sprite_img)[0]);
	bomb->time = clock();
	if (((bomb->time - bomb->last_time) / CLOCKS_PER_SEC) >= BOMB_TIMING)
	{
		make_bomb_explode(game, *bomb);
		bomb->bomb_total -= bomb->bomb_plant;
		bomb->bomb_plant = 0;
		bomb->bomb_chunk_pos = -1;
		bomb->bomb_pos.x = -1;
		bomb->bomb_pos.y = -1;
	}
}

// OTHERS BOMB PATTERN :

// static void	bomb_pattern_corner(t_game *game, t_bomb bomb, int i)
// {
// 	int	n_w;
// 	int	n_e;
// 	int	s_w;
// 	int	s_e;

// 	if (i - 1 > 0)
// 	{
// 		n_w = bomb.bomb_chunk_pos - ((i - 1) + ((i - 1)
	// * game->level->map_vector.x));
// 		n_e = bomb.bomb_chunk_pos + ((i - 1) - ((i - 1)
	// * game->level->map_vector.x));
// 		s_w = bomb.bomb_chunk_pos - ((i - 1) - ((i - 1)
	// * game->level->map_vector.x));
// 		s_e = bomb.bomb_chunk_pos + ((i - 1) + ((i - 1)
	// * game->level->map_vector.x));
// 		if (game->level->map[n_w] == '1')
// 		{
// 			game->level->map[n_w] = '0';
// 			game->window->map_sprites[n_w] = game->assets->ground;
// 		}
// 		if (game->level->map[n_e] == '1')
// 		{
// 			game->level->map[n_e] = '0';
// 			game->window->map_sprites[n_e] = game->assets->ground;
// 		}
// 		if (game->level->map[s_w] == '1')
// 		{
// 			game->level->map[s_w] = '0';
// 			game->window->map_sprites[s_w] = game->assets->ground;
// 		}
// 		if (game->level->map[s_e] == '1')
// 		{
// 			game->level->map[s_e] = '0';
// 			game->window->map_sprites[s_e] = game->assets->ground;
// 		}
// 	}
// }

// static void	bomb_pattern_cross(t_game *game, t_bomb bomb, int i)
// {
// 	if (game->level->map[bomb.bomb_chunk_pos
	// - (i * game->level->map_vector.x)] == '1')
// 	{
// 		game->level->map[bomb.bomb_chunk_pos
	// - (i * game->level->map_vector.x)] = '0';
// 		game->window->map_sprites[bomb.bomb_chunk_pos
	// - (i * game->level->map_vector.x)] = game->assets->ground;
// 	}
// 	if (game->level->map[bomb.bomb_chunk_pos
	// + (i * game->level->map_vector.x)] == '1')
// 	{
// 		game->level->map[bomb.bomb_chunk_pos
	// + (i * game->level->map_vector.x)] = '0';
// 		game->window->map_sprites[bomb.bomb_chunk_pos
	// + (i * game->level->map_vector.x)] = game->assets->ground;
// 	}
// 	if (game->level->map[bomb.bomb_chunk_pos - i] == '1')
// 	{
// 		game->level->map[bomb.bomb_chunk_pos - i] = '0';
// 		game->window->map_sprites[bomb.bomb_chunk_pos - i]
	// = game->assets->ground;
// 	}
// 	if (game->level->map[bomb.bomb_chunk_pos + i] == '1')
// 	{
// 		game->level->map[bomb.bomb_chunk_pos + i] = '0';
// 		game->window->map_sprites[bomb.bomb_chunk_pos + i]
	// = game->assets->ground;
// 	}
// }

// static void	bomb_pattern_box(t_game *game, t_bomb bomb, int o)
// {
// 	int	i;
// 	int j;
// 	int	pos;

// 	i = -bomb.bomb_plant + 2;
// 	while (i < bomb.bomb_plant - 1)
// 	{
// 		j = -bomb.bomb_plant + 2;
// 		while (j < bomb.bomb_plant - 1)
// 		{
// 			pos = bomb.bomb_chunk_pos + (j - (i * game->level->map_vector.x));
// 			if (game->level->map[pos] == '1')
// 			{
// 				game->level->map[pos] = '0';
// 				game->window->map_sprites[pos] = game->assets->ground;
// 			}
// 			printf("i : [%d] j : [%d]\n", i , j);
// 			j++;
// 		}
// 		i++;
// 	}
// }
