/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_restart_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:15:22 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 13:32:01 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Restart the array of available characters at the start state.
 * 
 * @param gameplay gameplay struct, to restart.
 */
static void	restart_the_game_available_character(t_gameplay *gameplay)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (gameplay->available_character[i] == 2
			|| gameplay->available_character[i] == 3)
			gameplay->available_character[i] = 0;
		i++;
	}
}

/**
 * @brief Restart the map sprites representing the map of the level.
 * 
 * @param game game struct, to restart.
 */
static void	restart_map_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->level->nb_cases)
	{
		if (game->level->map[i] == '0' || game->level->map[i] == 'P')
			game->window->map_sprites[i] = game->assets->ground;
		else if (game->level->map[i] == '1' || game->level->map[i] == '2')
			get_wall_image(game, &game->window->map_sprites[i], i);
		else if (game->level->map[i] == 'C')
			game->window->map_sprites[i] = game->assets->collectible_idle;
		else if (game->level->map[i] == 'E')
			game->window->map_sprites[i] = game->assets->exit;
		i++;
	}
}

/**
 * @brief Restart all texts of the game.
 * 
 * @param game game struct, to restart.
 */
static void	restart_all_texts_of_the_game(t_game *game)
{
	int	j;

	j = 0;
	while (j < e_total_text_number)
	{
		game->gameplay->all_texts[j].has_been_display = false;
		j++;
	}
	set_tutorial_text_box(game);
}

static void	restart_gameplay_small_variables(t_gameplay *gameplay,
	t_level *level)
{
	// not commented
	gameplay->is_pause = false;
	gameplay->is_stop = false;
	gameplay->is_display_plus_one = false;
	gameplay->tutorial_status = 0;
	gameplay->menu_status = 0;
	gameplay->fps = 0;
	gameplay->delta_time = 0;
	gameplay->nb_collect_get = 0;
	gameplay->nb_collect_remain = level->nb_collect;
	gameplay->nb_move = 0;
}

/**
 * @brief Restart the game to the start state.
 * 
 * @param game game struct, to restart.
 */
void	restart_the_game(t_game *game)
{
	free(game->level->map);
	game->level->map = ft_strdup(game->gameplay->map_start_state);
	if (!game->level->map)
		exit_game(*game, "Error of malloc.\n");
	free(game->gameplay->guards);
	init_guards(game, game->gameplay->guards);
	free(game->gameplay->player->bomb.explosion_pos);
	free(game->gameplay->player);
	init_player(game, game->gameplay->player, game->gameplay->chosen_character);
	restart_gameplay_small_variables(game->gameplay, game->level);
	restart_the_game_available_character(game->gameplay);
	ft_lstclear_texts_box(&game->gameplay->dialogue);
	put_unavailable_character_on_map(game, game->gameplay);
	mlx_clear_window(game->window->mlx_ptr, game->window->win_ptr);
	restart_map_sprites(game);
	restart_all_texts_of_the_game(game);
	init_collectible(game, game->gameplay, game->gameplay->collectible);
	game->gameplay->is_start = true;
}
