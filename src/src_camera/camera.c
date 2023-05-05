/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:37:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/05 17:02:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	camera(t_game *game, t_camera *camera, t_player *player)
{
	camera->camera_f_pos.x
		= player->player_f_pos.x - (camera->camera_f_size.x / 2);
	camera->camera_f_pos.y
		= player->player_f_pos.y - (camera->camera_f_size.y / 2);
	get_chunks_to_display(game, camera);
}
