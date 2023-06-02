/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/02 17:55:47 by arthurobero      ###   ########.fr       */
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
	if (window->win_ptr)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	}
	if (window->img.mlx_img)
		mlx_destroy_image(window->mlx_ptr, window->img.mlx_img);
	if (window->mlx_ptr)
	{
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
	}
	free(window);
}

void	free_camera(t_camera *camera, void *mlx_ptr)
{
	if (camera->chunks_to_display)
		free(camera->chunks_to_display);
	if (camera->img_background.mlx_img)
		mlx_destroy_image(mlx_ptr, camera->img_background.mlx_img);
	free(camera);
}

void	free_gameplay(t_gameplay *gameplay)
{
	if (gameplay->chunks_pos)
		free(gameplay->chunks_pos);
	if (gameplay->player->bomb.explosion_pos)
		free(gameplay->player->bomb.explosion_pos);
	if (gameplay->player)
		free(gameplay->player);
	if (gameplay->guards)
		free(gameplay->guards);
	if (gameplay->map_start_state)
		free(gameplay->map_start_state);
	ft_lstclear_texts_box(&gameplay->texts_box_list);
	if (gameplay->texts)
		free(gameplay->texts);
	free(gameplay);
}

void	free_game(t_game game, const char *error)
{
	if (game.level)
	{
		free_level(game.level);
		if (game.assets)
			free_assets(game.window->mlx_ptr, game.assets);
		if (game.camera)
			free_camera(game.camera, game.window->mlx_ptr);
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
