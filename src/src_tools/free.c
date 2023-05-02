/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/02 13:12:06 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_camera(t_camera *camera)
{
	mlx_destroy_window(camera->mlx_ptr, camera->win_ptr);
	camera->win_ptr = NULL;
	mlx_destroy_image(camera->mlx_ptr, camera->img.mlx_img);
	if (camera->mlx_ptr)
	{
		mlx_destroy_display(camera->mlx_ptr);
		free(camera->mlx_ptr);
	}
	if (camera->win_ptr)
		free(camera->win_ptr);
	free(camera);
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
		if (game.camera)
			free_camera(game.camera);
	}
	if (error)
	{
		ft_putstr((char *)error);
		exit(EXIT_FAILURE);
	}
}
