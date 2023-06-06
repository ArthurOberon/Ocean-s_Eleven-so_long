/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:17:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 12:15:03 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Free all the allocated memory in the level struct.
 * 
 * @param level level struct to free.
 */
static void	free_level(t_level *level)
{
	if (level->map)
		free(level->map);
	if (level->path_map)
		free(level->path_map);
	free(level);
}

/**
 * @brief Free all the allocated memory in the window struct.
 * 
 * @param window window struct to free.
 */
static void	free_window(t_window *window)
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

/**
 * @brief Free all the allocated memory in the camera struct.
 * 
 * @param camera camera struct to free.
 * @param mlx_ptr mlx_ptr, used to destroy the mlx_img of the background image.
 */
static void	free_camera(t_camera *camera, void *mlx_ptr)
{
	if (camera->chunks_to_display)
		free(camera->chunks_to_display);
	if (camera->img_background.mlx_img)
		mlx_destroy_image(mlx_ptr, camera->img_background.mlx_img);
	free(camera);
}

/**
 * @brief Free all the allocated memory in the gameplay struct.
 * 
 * @param gameplay gameplay struct to free.
 */
static void	free_gameplay(t_gameplay *gameplay)
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
	if (gameplay->dialogue)
		free_dialogue(gameplay->dialogue);
	if (gameplay->all_texts)
		free(gameplay->all_texts);
	free(gameplay);
}

/**
 * @brief Free all the allocated memory and exit the game.
 * Exit with EXIT_SUCCESS if there is no error, otherwise exit with EXIT_FAILURE.
 * 
 * @param game game struct to free all the allocated memory.
 * @param error message to print before exiting if there is an error.
 */
void	exit_game(t_game game, const char *error)
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
		ft_printf("%s", error);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
