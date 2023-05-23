/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:34:37 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/23 15:31:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_fps(int *fps, double *delta_time)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			now;

	if (!last_time.tv_sec)
		gettimeofday(&last_time, NULL);
	gettimeofday(&now, NULL);
	*delta_time = (((double)(now.tv_usec - last_time.tv_usec) / CLOCKS_PER_SEC)
			+ now.tv_sec - last_time.tv_sec);
	while (*delta_time <= (1.f / FPS_CAP) * 0)
	{
		gettimeofday(&now, NULL);
		*delta_time = (((double)(now.tv_usec - last_time.tv_usec)
					/ CLOCKS_PER_SEC) + now.tv_sec - last_time.tv_sec);
	}
	*fps = (int)(1.f / *delta_time);
	last_time = now;
}

void	set_player_to_character(t_game *game, t_gameplay *gameplay,
	t_player *player, int character)
{
	if (character == e_main)
	{
		if (player->has_been_hit == false)
			player->hp = 2;
		else
			player->hp = 1;
		player->player_character = e_main;
		set_text_box(game, &gameplay->text_box, "abcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyzabcdefhijklmnopqrstuvwxyz");
		printf("new player choose : Danny\n");
	}
	else if (character == e_eater)
	{
		player->hp = 1;
		player->player_character = e_eater;
		printf("new player choose : Rusty\n");
	}
	else if (character == e_thief)
	{
		player->hp = 1;
		player->player_character = e_thief;
		printf("new player choose : Linus\n");
	}
	else if (character == e_bomber)
	{
		player->hp = 1;
		player->player_character = e_bomber;
		printf("new player choose : Basher\n");
	}
}

void	restart(t_game *game)
{
	int	i;

	i = 0;
	ft_print_1d_to_2d(game->level);
	free(game->level->map);
	game->level->map = ft_strdup(game->gameplay->map_start_state);
	if (!game->level->map)
		free_game(*game, "Error of malloc.\n");
	ft_print_1d_to_2d(game->level);
	free(game->gameplay->player->bomb.explosion_pos);
	free(game->gameplay->player);
	init_player(game, game->gameplay->player);
	game->gameplay->nb_collect_remain = game->level->nb_collect;
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
