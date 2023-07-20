/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_collectible.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:39:03 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 11:48:48 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sprite	*get_right_open_animation(t_game *game, int code)
{
	if (code == 0)
		return (game->assets->collectible_open_0);
	else if (code == 1)
		return (game->assets->collectible_open_1);
	else if (code == 2)
		return (game->assets->collectible_open_2);
	else if (code == 3)
		return (game->assets->collectible_open_3);
	else if (code == 4)
		return (game->assets->collectible_open_4);
	else if (code == 5)
		return (game->assets->collectible_open_5);
	else if (code == 6)
		return (game->assets->collectible_open_6);
	else if (code == 7)
		return (game->assets->collectible_open_7);
	else if (code == 8)
		return (game->assets->collectible_open_8);
	else
		return (game->assets->collectible_open_9);
}

static int	get_collectible_pos(t_game *game, int number_code)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < game->level->nb_cases)
	{
		if (game->level->map[i] == 'C')
		{
			if (k == number_code)
				return (i);
			k++;
		}
		i++;
	}
	return (-1);
}

void	init_collectible(t_game *game, t_gameplay *gameplay,
	t_collectible *collectible)
{
	int		i;
	int		size;
	char	*collectible_code;

	size = game->level->nb_collect;
	collectible = ft_calloc(sizeof(t_collectible), size);
	if (!collectible)
		exit_game(*game, "Error of malloc.\n");
	gameplay->collectible = collectible;
	collectible_code = ft_calloc(sizeof(char), size + 1);
	if (!collectible_code)
		exit_game(*game, "Error of malloc.\n");
	gameplay->collectible_code = collectible_code;
	i = 0;
	while (i < size)
	{
		collectible[i].code = rand() % 10;
		collectible[i].state = COLLECTABLE;
		collectible[i].sprite_open_animation = ft_calloc(sizeof(t_sprite), 1);
		sprite_cpy(collectible[i].sprite_open_animation,
			get_right_open_animation(game, collectible[i].code));
		collectible[i].pos = get_collectible_pos(game, i);
		i++;
	}
}
