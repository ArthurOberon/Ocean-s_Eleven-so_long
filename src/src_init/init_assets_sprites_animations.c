/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_animations.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:48:42 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/09 23:56:51 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	randomize_sprite(t_sprite *sprite)
{
	// not commented
	sprite->frame = rand() % sprite->size;
}

void	init_sprites_animations(t_game *game, t_sprite *sprite, char character)
{
	// not commented
	if (character == '1' || character == 'C')
	{
		randomize_sprite(sprite);
	}
	// else
	// {
	// 	sprite->frame = 0;
	// }
}
