/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:05:45 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/18 17:23:51 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_inside_area(t_f_vector_2 pos, t_f_vector_2 pos_size,
t_f_vector_2 area, t_f_vector_2 size_area)
{
	if ((pos.x >= area.x && pos.x <= area.x + size_area.x)
		&& (pos.y >= area.y && pos.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x + pos_size.x >= area.x
			&& pos.x + pos_size.x <= area.x + size_area.x)
		&& (pos.y >= area.y && pos.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x >= area.x && pos.x <= area.x + size_area.x)
		&& (pos.y + pos_size.y >= area.y
			&& pos.y + pos_size.y <= area.y + size_area.y))
	{
		return (1);
	}
	if ((pos.x + pos_size.x >= area.x
			&& pos.x + pos_size.x <= area.x + size_area.x)
		&& (pos.y + pos_size.y >= area.y
			&& pos.y + pos_size.y <= area.y + size_area.y))
	{
		return (1);
	}
	return (0);
}

void	check_collider_positions(t_game *game,
	t_player *player, t_guard *guards)
{
	int	i;

	i = 0;
	while (i < game->gameplay->nb_guard)
	{
		if (guards[i].is_alive == true && is_in_chunks_to_display(game->camera->chunks_to_display,
				game->camera->nb_chunks_in_camera_total, guards[i].guard_pos_tab))
		{
			if (is_inside_area(player->player_f_pos,
					(t_f_vector_2){(double)player->size.x, (double)player->size.y},
				guards[i].guard_f_pos, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE}))
			{
				guards[i].is_in_player = true;
				if (player->iframes == false)
				{
					player->hp -= 1;
					player->has_been_hit = true;
					player->iframes = true;
				}
				if (guards[i].chasing_player == true)
					guards[i].chasing_player = false;
				else
					guards[i].chasing_player = true;
			}
			else
			{
				guards[i].is_in_player = false;
			}
			if (is_inside_area(player->player_f_pos,
					(t_f_vector_2){(double)player->size.x, (double)player->size.y},
				guards[i].guard_fov_f_pos_1, (t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE}))
			{
				guards[i].chasing_player = true;
			}
			else if (player->player_character != e_eater
				&& is_inside_area(player->player_f_pos,
					(t_f_vector_2){(double)player->size.x, (double)player->size.y},
				guards[i].guard_fov_f_pos_2,
				(t_f_vector_2){CHUNK_SIZE, CHUNK_SIZE}))
			{
				if (game->level->map[pos_to_chunk(guards[i].guard_fov_pos_1.x, guards[i].guard_fov_pos_1.y, game->level->map_vector.x)] != '2')
				{
					guards[i].chasing_player = true;
				}
			}
			else
			{
				if (guards[i].chasing_player == false)
				{
					guards[i].guard_f_dir.x = 0;
					guards[i].guard_f_dir.y = 0;
				}
			}
		}
		i++;
	}
}
