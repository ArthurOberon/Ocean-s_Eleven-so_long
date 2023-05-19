/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:18:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/19 18:35:59 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	srand(time(NULL));
	game->gameplay = gameplay;
	gameplay->is_pause = false;
	gameplay->is_stop = false;
	gameplay->fps = 0;
	gameplay->delta_time = 0;
	gameplay->nb_collect_remain = game->level->nb_collect;
	gameplay->nb_move = 0;
	get_chunk_positions(game, &gameplay->chunks_pos, game->level->map_vector,
		game->level->nb_cases);
	gameplay->map_start_state = ft_strdup(game->level->map);
	init_player(game, gameplay->player);
	init_guards(game, gameplay->guards);
	gameplay->text_box.is_diplay = false;
	gameplay->text_box.talking_character = gameplay->player->player_character;
	gameplay->text_box.text = NULL;
	if (IS_DEBUG)
		debug_chunk_pos(game);
}
