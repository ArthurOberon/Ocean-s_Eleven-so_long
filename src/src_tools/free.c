/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/01 23:07:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_assets(void *ptr, t_sprites_assets *assets)
{
	free_one_sprite(ptr, assets->player);
	free_one_sprite(ptr, assets->exit);
	free_one_sprite(ptr, assets->collect);
	free_one_sprite(ptr, assets->ground);
	free_one_sprite(ptr, assets->wall_corner_n_o);
	free_one_sprite(ptr, assets->wall_corner_n_e);
	free_one_sprite(ptr, assets->wall_corner_s_e);
	free_one_sprite(ptr, assets->wall_corner_s_o);
	free_one_sprite(ptr, assets->wall_side_up);
	free_one_sprite(ptr, assets->wall_side_down);
	free_one_sprite(ptr, assets->wall_side_left);
	free_one_sprite(ptr, assets->wall_side_right);
	free_one_sprite(ptr, assets->wall_inside);
	free(assets);
}

static void	free_level(t_level *level)
{
	if (level->map)
		free(level->map);
	if (level->path_map)
		free(level->path_map);
	free(level);
}

void	free_window(t_window *window)
{
	if (window->map_sprites)
		free(window->map_sprites);
	if (window->mlx_ptr)
	{
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
	}
	if (window->win_ptr)
		free(window->win_ptr);
	free(window);
}

void	free_gameplay(t_gameplay *gameplay)
{
	if (gameplay->chunks_pos)
		free(gameplay->chunks_pos);
	if (gameplay->player)
		free(gameplay->player);
	free(gameplay);
}

void	free_game(t_game game, const char *error)
{
	if (game.level)
	{
		free_level(game.level);
		if (game.assets)
			free_assets(game.window->mlx_ptr, game.assets);
		if (game.window)
			free_window(game.window);
		if (game.gameplay)
			free_gameplay(game.gameplay);
	}
	if (error)
	{
		ft_putstr((char *)error);
		exit(EXIT_FAILURE);
	}
}
