/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bomb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:45:08 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 23:48:20 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Add a bomb with SPACE, if the player is playing as a bomber.
 * 
 * @param keysym 
 * @param game 
 */
static void	handle_bomb_add(int keysym, t_game *game)
{
	if (keysym == XK_space)
	{
		if (game->gameplay->player->bomb.bomb_plant
			< game->gameplay->player->bomb.bomb_total)
		{
			game->gameplay->player->bomb.bomb_plant += 1;
			gettimeofday(&game->gameplay->player->bomb.last_time, NULL);
		}
		ft_printf("plant a bomb. bomb planted : [%d]\n",
			game->gameplay->player->bomb.bomb_plant);
	}
}

/**
 * @brief Remove a bomb with DELETE, if the player is playing as a bomber.
 * 
 * @param keysym key pressed.
 * @param game game struct, used to get the gameplay struct.
 */
static void	handle_bomb_remove(int keysym, t_game *game)
{
	if (keysym == XK_Delete)
	{
		if (game->gameplay->player->bomb.bomb_plant > 0)
		{
			game->gameplay->player->bomb.bomb_plant -= 1;
			gettimeofday(&game->gameplay->player->bomb.last_time, NULL);
		}
		if (game->gameplay->player->bomb.bomb_plant == 0)
		{
			game->gameplay->player->bomb.bomb_chunk_pos = -1;
			game->gameplay->player->bomb.bomb_pos.x = -1;
			game->gameplay->player->bomb.bomb_pos.y = -1;
		}
		ft_printf("remove a bomb. bomb planted : [%d]\n",
			game->gameplay->player->bomb.bomb_plant);
	}
}

/**
 * @brief Handle the bomb feature, add or remove a bomb
 * depending on the key pressed.
 * 
 * @param keysym 
 * @param game 
 */
void	handle_bomb(int keysym, t_game *game)
{
	if (game->gameplay->player->player_character != e_bomber)
		return ;
	handle_bomb_add(keysym, game);
	handle_bomb_remove(keysym, game);
}
