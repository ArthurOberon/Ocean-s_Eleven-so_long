/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gameplay_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:36:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/16 16:45:53 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize the positioning of the player struct.
 * 
 * @param game game struct, used to get the level struct.
 * @param player player struct, where the variables will be initialized.
 */
static void	init_player_positioning(t_game *game, t_player *player)
{
	player->player_dir.x = 0;
	player->player_dir.y = 0;
	player->player_chunk_pos.x = game->level->player_pos_tab
		% game->level->map_vector.x;
	player->player_chunk_pos.y = game->level->player_pos_tab
		/ game->level->map_vector.x;
	player->player_pos.x = player->player_chunk_pos.x * CHUNK_SIZE;
	player->player_pos.y = player->player_chunk_pos.y * CHUNK_SIZE;
	player->player_f_pos.x = player->player_pos.x;
	player->player_f_pos.y = player->player_pos.y;
	player->player_look_dir.x = 1;
	player->player_look_dir.y = 0;
}

/**
 * @brief Initialize the eplosion position tab of the bomb struct.
 * 
 * @param game game struct, used to exit the game if a malloc fail.
 * @param bomb bomb struct, where the explosion position tab will be initialized.
 * @param alloc boolean, if true, the explosion position tab will be allocated.
 */
void	init_explosion_pos(t_game *game, t_bomb *bomb, bool alloc)
{
	int	i;

	i = 0;
	if (alloc == true)
	{
		bomb->explosion_pos = ft_calloc(bomb->explosion_tab_size,
				sizeof(t_vector_2));
		if (!bomb->explosion_pos)
			exit_game(*game, "Error of malloc.\n");
	}
	while (i < bomb->explosion_tab_size)
	{
		bomb->explosion_pos[i] = (t_vector_2){-1, -1};
		i++;
	}
}

/**
 * @brief Initialize the bomb struct.
 * 
 * @param game game struct, used to initialize the bomb struct.
 * @param player player struct, used to initialize his bomb struct.
 */
static void	init_bomb(t_game *game, t_player *player)
{
	player->bomb.bomb_total = BOMB_NUMBER;
	player->bomb.bomb_plant = 0;
	player->bomb.bomb_chunk_pos = -1;
	player->bomb.bomb_pos.x = -1;
	player->bomb.bomb_pos.y = -1;
	player->bomb.time = (struct timeval){0, 0};
	player->bomb.last_time = (struct timeval){0, 0};
	player->bomb.explosion_tab_size
		= (2 * (BOMB_NUMBER * BOMB_NUMBER)) - (2 * BOMB_NUMBER) + 1;
	player->bomb.explosion_tab_size += 1;
	init_explosion_pos(game, &player->bomb, true);
	player->bomb.time_explosion = (struct timeval){0, 0};
	player->bomb.start_time_explosion = (struct timeval){0, 0};
}

/**
 * @brief Initialize the qte struct.
 * 
 * @param player player struct, used to initialize his qte struct.
 */
static void	init_qte(t_player *player)
{
	player->qte.is_pickpocketing = false;
	player->qte.pressed = false;
	player->qte.time_to_press = false;
	player->qte.pressed_in_time = false;
	player->qte.pickpocket_area.x = player->player_pos.x - CHUNK_SIZE;
	player->qte.pickpocket_area.y = player->player_pos.y - CHUNK_SIZE;
	player->qte.pickpocket_size.x = CHUNK_SIZE * 3;
	player->qte.pickpocket_size.y = CHUNK_SIZE * 3;
	player->qte.start_time = (struct timeval){0, 0};
	player->qte.time = (struct timeval){0, 0};
}

/**
 * @brief Initialize the player struct.
 * 
 * @param game game struct, used to get the gameplau struct.
 * @param player player struct to initialize.
 * @param chosen_character first character chosen by the player,
 * and will be the character the player will start with
 * between the available ones.
 */
void	init_player(t_game *game, t_player *player, int chosen_character)
{
	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		exit_game(*game, "Error of malloc.\n");
	game->gameplay->player = player;
	player->size.x = (CHUNK_SIZE * RATIO_PLAYER_SIZE_X);
	player->size.y = (CHUNK_SIZE * RATIO_PLAYER_SIZE_Y);
	init_player_positioning(game, player);
	init_qte(player);
	init_bomb(game, player);
	player->player_character = chosen_character;
	player->hp = 2;
	player->has_been_hit = false;
	player->iframes = false;
	player->iframes_flashing = 0;
	player->iframes_start_time = (struct timeval){0, 0};
	player->iframes_time = (struct timeval){0, 0};
	player->player_sprite = NULL;
}
