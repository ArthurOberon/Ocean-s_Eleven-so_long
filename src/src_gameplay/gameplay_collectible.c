/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_collectible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:48:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/20 11:48:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Add a collectible code to the collectible_code string.
 * 
 * @param game game struct, used to get the level struct.
 * @param gameplay gameplay struct, used to get the collectible_code string.
 * @param one_collectible collectible struct,
 * contains the char to add to the string.
 */
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

/**
 * @brief Get a collectible,
 * the way a collectible is collected depends on the collectible state
 * and the new state.
 * 
 * @param game game struct, used to get the level and window struct.
 * @param gameplay gameplay struct.
 * @param one_collectible collectible struct, the collectible collected.
 * @param new_state new state of the collectible collected.
 */
static void	get_one_collectible(t_game *game, t_gameplay *gameplay,
	t_collectible *one_collectible, int new_state)
{
	if (gameplay->nb_collect_remain > 0)
	{
		if (one_collectible->state != COLLECTED_ON_GUARD)
		{
			gameplay->nb_collect_get += 1;
			gameplay->nb_collect_remain -= 1;
			add_collect_to_code(game, gameplay, one_collectible);
		}
		else
		{
			gameplay->all_texts[e_text_collect_steal_code].has_been_display
				= false;
			add_one_text_to_dialogue(game, &gameplay->dialogue,
				&gameplay->all_texts[e_text_collect_steal_code],
				game->gameplay->player->player_character);
		}
	}
	gameplay->is_display_plus_one = true;
	if (new_state == COLLECTED)
	{
		game->level->map[one_collectible->pos] = 'O';
		sprite_cpy(game->window->map_sprites[one_collectible->pos],
			one_collectible->sprite_open_animation);
	}
	one_collectible->state = new_state;
}

/**
 * @brief Get a random collectible with the state COLLECTABLE
 * in the collectible array.
 * 
 * @param game game struct, used to get the level struct.
 * @param collectible collectible struct, used to get the collectible array.
 * @return int position of the random collectible in the collectible array.
 */
static int	get_one_random_collectable_collectible(t_game *game,
	t_collectible *collectible)
{
	int	random_collectible;

	random_collectible = rand() % game->level->nb_collect;
	while (collectible[random_collectible].state != COLLECTABLE)
	{
		random_collectible = rand() % game->level->nb_collect;
	}
	return (random_collectible);
}

/**
 * @brief Collected one collectible on a guard.
 * 
 * @param game game struct, used to get the level struct.
 * @param gameplay gameplay struct, used to get is_display_plus_one.
 * @param collectible collectible struct, used to get the collectible array.
 */
static void	get_one_collectible_by_guard(t_game *game, t_gameplay *gameplay,
	t_collectible *collectible)
{
	int				random_collectible;

	if (check_all_collectibles_have_been_collected(collectible,
			game->level->nb_collect))
	{
		gameplay->is_display_plus_one = true;
		return ;
	}
	random_collectible = get_one_random_collectable_collectible(game,
			collectible);
	get_one_collectible(game, gameplay, &collectible[random_collectible],
		COLLECTED_ON_GUARD);
}

/**
 * @brief Collect one collectible.
 * 
 * @param game game struct.
 * @param gameplay gameplay struct, used to get the collectible struct.
 * @param pos position of the collectible collected.
 * @param new_state new state of the collectible collected
 * (COLLECTABLE or COLLECTED or COLLECTED_ON_GUARD).
 */
void	collected_one_collectible(t_game *game, t_gameplay *gameplay,
	int pos, int new_state)
{
	int	i;

	if (new_state == COLLECTED_ON_GUARD)
	{
		get_one_collectible_by_guard(game, gameplay, gameplay->collectible);
		return ;
	}
	if (pos == -1)
		return ;
	i = 0;
	while (i < game->level->nb_collect)
	{
		if (gameplay->collectible[i].pos == pos)
		{
			get_one_collectible(game, gameplay, &gameplay->collectible[i],
				new_state);
			return ;
		}
		i++;
	}
}
