/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_collectible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:48:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/29 13:00:06 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	check_all_collectible_collected(t_collectible *collectible,
	int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (collectible[i].state == COLLECTABLE)
			return (false);
		i++;
	}
	return (true);
}

static void	add_collect_to_code(t_game *game, t_gameplay *gameplay,
	t_collectible *one_collectible)
{
	int		i;
	char	char_code[10];

	if (gameplay->collectible_code[game->level->nb_collect - 1] != 0)
		return ;
	i = 0;
	while (i < game->level->nb_collect)
	{
		if (gameplay->collectible_code[i] == 0)
			break ;
		i++;
	}
	ft_itoa(one_collectible->code, char_code);
	gameplay->collectible_code[i] = char_code[0];
}

static void	get_one_collectible(t_game *game, t_gameplay *gameplay,
	t_collectible *one_collectible, int new_state)
{
	one_collectible->state = new_state;
	if (game->gameplay->nb_collect_remain > 0)
	{
		gameplay->nb_collect_get += 1;
		gameplay->nb_collect_remain -= 1;
		gameplay->is_display_plus_one = true;
		printf("get code : [%d]\n", one_collectible->code);
		add_collect_to_code(game, gameplay, one_collectible);
		if (new_state == COLLECTED)
		{
			game->level->map[one_collectible->pos] = 'O';
			game->window->map_sprites[one_collectible->pos]
				= one_collectible->sprite_open_animation;
		}
	}
}

static int	get_one_random_collectable_collectible(t_game *game,
	t_gameplay *gameplay, t_collectible *collectible)
{
	int	random_collectible;

	random_collectible = rand() % game->level->nb_collect;
	while (collectible[random_collectible].state != COLLECTABLE)
	{
		random_collectible = rand() % game->level->nb_collect;
	}
	return (random_collectible);
}

static void	get_one_collectible_by_guard(t_game *game, t_gameplay *gameplay,
	t_collectible *collectible)
{
	int				random_collectible;

	if (check_all_collectible_collected(collectible, game->level->nb_collect))
	{
		gameplay->is_display_plus_one = true;
		return ;
	}
	random_collectible = get_one_random_collectable_collectible(game, gameplay,
			collectible);
	get_one_collectible(game, gameplay, &collectible[random_collectible],
		COLLECTED_ON_GUARD);
}

static void	get_one_collectible_by(t_game *game, t_gameplay *gameplay,
	t_collectible *one_collectible, int new_state)
{
	if (new_state == COLLECTED)
	{
		get_one_collectible(game, gameplay, one_collectible, new_state);
	}
	else if (new_state == COLLECTED_ON_GUARD)
	{
		get_one_collectible_by_guard(game, gameplay, gameplay->collectible);
	}
}

void	collected_one_collectible(t_game *game, t_gameplay *gameplay,
	int pos, int new_state)
{
	int	i;

	if (pos == -1)
		return ;
	i = 0;
	while (i < game->level->nb_collect)
	{
		if (gameplay->collectible[i].pos == pos)
		{
			get_one_collectible_by(game, gameplay, &gameplay->collectible[i],
				new_state);
			return ;
		}
		i++;
	}
}
