/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:49:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/29 19:52:05 by aoberon          ###   ########.fr       */
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
