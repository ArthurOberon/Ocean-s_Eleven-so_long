/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_collectible.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:39:03 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/12 15:53:41 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sprite	*get_right_open_animation(t_game *game, int code)
{
	return (game->assets->alphabet);
	// if (code == 0)
	// 	return (game->assets->collectible_0_open);
	// else if (code == 1)
	// 	return (game->assets->collectible_1_open);
	// else if (code == 2)
	// 	return (game->assets->collectible_2_open);
	// else if (code == 3)
	// 	return (game->assets->collectible_3_open);
	// else if (code == 4)
	// 	return (game->assets->collectible_4_open);
	// else if (code == 5)
	// 	return (game->assets->collectible_5_open);
	// else if (code == 6)
	// 	return (game->assets->collectible_6_open);
	// else if (code == 7)
	// 	return (game->assets->collectible_7_open);
	// else if (code == 8)
	// 	return (game->assets->collectible_8_open);
	// else
	// 	return (game->assets->collectible_9_open);
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
	t_collectible *collectible, char *collectible_code)
{
	int	i;
	int	size;

	size = gameplay->nb_collect_remain;
	collectible = ft_calloc(sizeof(t_collectible), size);
	if (!collectible)
		exit_game(*game, "Error of malloc.\n");
	gameplay->collectible = collectible;
	collectible_code = ft_calloc(sizeof(char), size);
	if (!collectible_code)
		exit_game(*game, "Error of malloc.\n");
	gameplay->collectible_code = collectible_code;
	i = 0;
	while (i < size)
	{
		collectible[i].code = rand() % 10;
		printf("code[%d] : %d\n", i, collectible[i].code);
		collectible[i].state = COLLECTABLE;
		// collectible[i].sprite_open_animation = get_right_open_animation(game,
		// 		collectible[i].code);
		collectible[i].sprite_open_animation = game->assets->qte;
		collectible[i].pos = get_collectible_pos(game, i);
		// printf("pos : %d\n", collectible[i].pos);
		// printf("code : %d\n", collectible[i].code);
		// printf("sprite : [%p]\n", collectible[i].sprite_open_animation);
		i++;
	}
	printf("\n");
}
