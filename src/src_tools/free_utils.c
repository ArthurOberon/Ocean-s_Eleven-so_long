/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:49:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/15 22:56:57 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_one_sprite(void *ptr, t_sprite *sprite)
{
	int	i;

	i = 0;
	if (!sprite)
		return ;
	while (i < sprite->size)
	{
		if (sprite->sprite_img[i].mlx_img)
			mlx_destroy_image(ptr, sprite->sprite_img[i].mlx_img);
		i++;
	}
	free(sprite->sprite_img);
	free(sprite);
}

void	free_assets(void *ptr, t_sprites_assets *assets)
{
	free_one_sprite(ptr, assets->player);
	free_one_sprite(ptr, assets->guard);
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
	free_one_sprite(ptr, assets->qte);
	free(assets);
}
