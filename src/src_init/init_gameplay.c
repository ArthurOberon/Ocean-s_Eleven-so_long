/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:18:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 23:09:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player(t_game *game, t_player *player)
{
	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		free_game(*game, "Error of malloc.\n");
	player->size.x = (CHUNK_SIZE * RATIO_PLAYER_SIZE_X);
	player->size.y = (CHUNK_SIZE * (RATIO_PLAYER_SIZE_Y));
	player->dir_player.x = 0;
	player->dir_player.y = 0;
	player->player_chunk_pos.x = game->level->player_pos_tab
		- game->level->map_vector.x;
	player->player_chunk_pos.y = game->level->player_pos_tab
		/ game->level->map_vector.y;
	player->player_pos.x = player->player_chunk_pos.x * CHUNK_SIZE;
	player->player_pos.y = player->player_chunk_pos.y * CHUNK_SIZE;
	player->player_f_pos.x = player->player_chunk_pos.x * CHUNK_SIZE;
	player->player_f_pos.y = player->player_chunk_pos.y * CHUNK_SIZE;
	game->gameplay->player = player;
}

static void	get_chunk_positions(t_game *game, t_vector_2 **chunk_pos,
	t_vector_2 size, int nb)
{
	int	i;
	int	j;
	int	x;
	int	y;

	(*chunk_pos) = ft_calloc(sizeof(t_vector_2), nb);
	if (!*chunk_pos)
		free_game(*game, "Error of malloc.\n");
	i = 0;
	y = 0;
	while (i < size.y)
	{
		j = 0;
		x = 0;
		while (j < size.x)
		{
			(*chunk_pos)[(i * size.x) + j] = (t_vector_2){x, y};
			j++;
			x += CHUNK_SIZE;
		}
		i++;
		y += CHUNK_SIZE;
	}
}

void	init_gameplay(t_game *game)
{
	t_gameplay	*gameplay;

	gameplay = ft_calloc(sizeof(t_gameplay), 1);
	if (!gameplay)
		free_game(*game, "Error of malloc\n");
	game->gameplay = gameplay;
	gameplay->fps = 0;
	gameplay->delta_time = 0;
	gameplay->nb_collect = game->level->nb_collect;
	get_chunk_positions(game, &gameplay->chunks_pos, game->level->map_vector,
		game->level->nb_cases);
	init_player(game, gameplay->player);
	if (IS_DEBUG)
		debug_chunk_pos(game);
}
