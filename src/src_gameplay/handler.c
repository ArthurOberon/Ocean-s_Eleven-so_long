/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:34:22 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/10 14:42:49 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	free_game(*game, NULL);
	exit(EXIT_SUCCESS);
	return (0);
}

int	secure_lost_focus(t_game *game)
{
	game->gameplay->player->player_dir.x = 0;
	game->gameplay->player->player_dir.y = 0;
	return (1);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		close_game(game);
		return (1);
	}
	if (keysym == XK_P || keysym == XK_p)
	{
		if (game->gameplay->is_pause == false)
			game->gameplay->is_pause = true;
		else
		{
			game->gameplay->is_pause = false;
		}
	}
	if (keysym == XK_R || keysym == XK_r)
	{
		int	i;

		i = 0;
		ft_print_1d_to_2d(game->level);
		free(game->level->map);
		game->level->map = ft_strdup(game->gameplay->map_start_state);
		ft_print_1d_to_2d(game->level);
		init_player(game, game->gameplay->player);
		game->gameplay->nb_collect = game->level->nb_collect;
		game->gameplay->nb_move = 0;
		mlx_clear_window(game->window->mlx_ptr, game->window->win_ptr);
		while (i < game->level->nb_cases)
		{
			if (game->level->map[i] == '0' || game->level->map[i] == 'P')
				game->window->map_sprites[i] = game->assets->ground;
			else if (game->level->map[i] == '1' || game->level->map[i] == '2')
				get_wall_image(game, &game->window->map_sprites[i], i);
			else if (game->level->map[i] == 'C')
				game->window->map_sprites[i] = game->assets->collect;
			else if (game->level->map[i] == 'E')
				game->window->map_sprites[i] = game->assets->exit;
			i++;
		}
	}
	handle_player_move(keysym, game);
	if (game->gameplay->is_pause == false)
	{
		handle_bomb(keysym, game);
		handle_change_character_player(keysym, game->gameplay->player);
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_game *game)
{
	handle_player_move_release(keysym, game);
	return (0);
}
