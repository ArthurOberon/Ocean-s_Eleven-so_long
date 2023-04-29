/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:49:01 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 16:46:06 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	collectibles_count(t_level *level)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < level->nb_cases)
	{
		if (level->map[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

static t_vector_2	*collectibles_pos(t_level *level, int c_count)
{
	int			i;
	int			k;
	t_vector_2	*collectibles_pos;

	collectibles_pos = ft_calloc(sizeof(t_vector_2), c_count);
	if (!collectibles_pos)
	{
		free(level->map);
		exit(EXIT_FAILURE);
	}
	i = 0;
	k = 0;
	while (i < level->nb_cases)
	{
		if (level->map[i] == 'C')
		{
			collectibles_pos[k]
				= (t_vector_2){i % level->map_vector.x, i / level->map_vector.x};
			k++;
		}
		i++;
	}
	return (collectibles_pos);
}

static int	a_star_collectibles(t_game *game, t_vector_2 *c_pos, int c_count)
{
	int	i;
	int	c_pos_converted;

	i = 0;
	while (i < c_count)
	{
		c_pos_converted = c_pos[i].x + (c_pos[i].y * game->level->map_vector.x);
		if (!a_star(game->level, game->level->player_pos_tab, c_pos_converted))
		{
			free(c_pos);
			exit_pathfinding_error(game->level, 'C', c_pos_converted);
		}
		ft_bzero(game->level->path_map, sizeof(t_path_map)
			* game->level->nb_cases);
		i++;
	}
	free(c_pos);
	return (1);
}

void	pathfinding(t_game *game)
{
	int			c_count;
	t_vector_2	*c_pos;

	game->level->player_pos_tab = find_character(game->level, 'P');
	game->level->exit_pos = find_character(game->level, 'E');
	c_count = collectibles_count(game->level);
	game->level->nb_collect = c_count;
	c_pos = collectibles_pos(game->level, c_count);
	game->level->path_map = init_path_map(game->level);
	if (!game->level->path_map)
	{
		free(c_pos);
		free(game->level->map);
		exit(EXIT_FAILURE);
	}
	a_star_collectibles(game, c_pos, c_count);
	ft_bzero(game->level->path_map, sizeof(t_path_map) * game->level->nb_cases);
	if (!a_star(game->level, game->level->player_pos_tab, game->level->exit_pos))
		exit_pathfinding_error(game->level, 'E', game->level->exit_pos);
}
