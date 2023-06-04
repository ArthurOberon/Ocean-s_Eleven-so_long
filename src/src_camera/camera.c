/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/04 17:54:28 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief displaying the background
 * by copy with memcpy_img the t_img *img in the window->img.
 * 
 * @param window window struct, used to get the window->img to copy in.
 * @param img img used to get the img to copy.
 */
void	display_background(t_window *window, t_img *img)
{
	memcpy_img(&window->img, (t_vector_2){0, 0}, img,
		(t_vector_2[2]){{0, 0}, {0, 0}});
}

/**
 * @brief set up all the camera part :
 * - change position of the camera compared to the player position.
 * - find all the chunks in the camera view with get_chunks_to_display().
 * - display the background, with camera->img_background as background image,
 * with display_background().
 * 
 * @param game game struct, used to get the window.
 * @param camera camera struct, set up in this function.
 * @param player player struct, used to get the player position.
 */
void	camera(t_game *game, t_camera *camera, t_player *player)
{
	camera->camera_f_pos.x
		= player->player_f_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y
		= player->player_f_pos.y - (camera->camera_f_size.y / 2);
	get_chunks_to_display(game, camera);
	display_background(game->window, &camera->img_background);
}
