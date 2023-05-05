/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:33:16 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/05 17:14:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_collider(char *map, t_collider chunks)
{
	if (map[chunks.n_w] == '1')
		return (chunks.n_w);
	if (map[chunks.n_e] == '1')
		return (chunks.n_e);
	if (map[chunks.s_w] == '1')
		return (chunks.s_w);
	if (map[chunks.s_e] == '1')
		return (chunks.s_e);
	return (-1);
}

t_collider	get_collider_on_move(t_f_vector_2 *move, t_player *player,
	int x_max)
{
	t_f_vector_2	hypothetical_pos;
	t_collider		chunks;

	hypothetical_pos.x = player->player_f_pos.x + move->x;
	hypothetical_pos.y = player->player_f_pos.y + move->y;
	chunks.n_w = pos_to_chunk((int)hypothetical_pos.x,
			(int)hypothetical_pos.y, x_max);
	chunks.n_e = pos_to_chunk((int)hypothetical_pos.x + player->size.x,
			(int)hypothetical_pos.y, x_max);
	chunks.s_w = pos_to_chunk((int)hypothetical_pos.x,
			(int)hypothetical_pos.y + player->size.y, x_max);
	chunks.s_e = pos_to_chunk((int)hypothetical_pos.x + player->size.x,
			(int)hypothetical_pos.y + player->size.y, x_max);
	return (chunks);
}

static t_collider	get_collider(t_player *player, int x_max)
{
	t_collider		chunks;

	chunks.n_w = pos_to_chunk(player->player_f_pos.x,
			player->player_f_pos.y, x_max);
	chunks.n_e = pos_to_chunk(player->player_f_pos.x + player->size.x,
			player->player_f_pos.y, x_max);
	chunks.s_w = pos_to_chunk(player->player_f_pos.x,
			player->player_f_pos.y + player->size.y, x_max);
	chunks.s_e = pos_to_chunk(player->player_f_pos.x + player->size.x,
			player->player_f_pos.y + player->size.y, x_max);
	return (chunks);
}

static void	check_tile(t_game *game, char tile, int pos)
{
	if (tile == 'C')
	{
		game->level->map[pos] = '0';
		if (game->gameplay->nb_collect > 0)
			game->gameplay->nb_collect -= 1;
		game->window->map_sprites[pos] = game->assets->ground;
	}
	else if (tile == 'E')
	{
		if (game->gameplay->nb_collect == 0)
		{
			ft_putstr("SUCCESS !\n");
			close_game(game);
		}
	}
}

void	check_collider(t_game *game, t_player *player)
{
	int			x_max;
	t_collider	chunks;

	x_max = game->level->map_vector.x;
	chunks = get_collider(player, x_max);
	check_tile(game, game->level->map[chunks.n_w], chunks.n_w);
	check_tile(game, game->level->map[chunks.n_e], chunks.n_e);
	check_tile(game, game->level->map[chunks.s_w], chunks.s_w);
	check_tile(game, game->level->map[chunks.s_e], chunks.s_e);
}
