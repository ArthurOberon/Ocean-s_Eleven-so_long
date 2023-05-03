/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:33:16 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/03 22:35:01 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos_to_chunk(int x, int y, int x_max)
{
	return ((x / CHUNK_SIZE) + ((y / CHUNK_SIZE) * x_max));
}

t_vector_2	chunk_to_pixel_pos(int chunk, int x_max)
{
	t_vector_2	pos;

	pos.x = (chunk % x_max) * CHUNK_SIZE;
	pos.y = (chunk / x_max) * CHUNK_SIZE;
	return (pos);
}

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

t_collider	check_collision(t_f_vector_2 *move, t_player *player,
	int x_max)
{
	t_f_vector_2	hypothetical_pos;
	t_collider		chunks;

	hypothetical_pos.x = player->player_f_pos.x + move->x;
	hypothetical_pos.y = player->player_f_pos.y + move->y;
	chunks.n_w = pos_to_chunk(hypothetical_pos.x, hypothetical_pos.y, x_max);
	chunks.n_e = pos_to_chunk(hypothetical_pos.x + player->size.x,
			hypothetical_pos.y, x_max);
	chunks.s_w = pos_to_chunk(hypothetical_pos.x,
			hypothetical_pos.y + player->size.y, x_max);
	chunks.s_e = pos_to_chunk(hypothetical_pos.x + player->size.x,
			hypothetical_pos.y + player->size.y, x_max);
	return (chunks);
}
