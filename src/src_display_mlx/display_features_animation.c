/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_animation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:54:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/09 23:57:17 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_animation(t_gameplay *gameplay, t_sprite *sprite)
{
	if (gameplay->nb_collect_remain != 0)
		return ;
	update_frame(sprite);
}

static void	open_collectible_animation(t_game *game, t_gameplay *gameplay,
	t_sprite *sprite, int chunk_pos)
{
	update_frame(sprite);
	if (sprite->frame == 0)
		game->window->map_sprites[chunk_pos] = game->assets->ground;
}

void	get_animation(t_game *game, t_gameplay *gameplay, t_sprite *sprite,
	int chunk_pos)
{
	char	character;

	character = game->level->map[chunk_pos];
	if (character == 'E')
		exit_animation(gameplay, sprite);
	else if (character == 'O')
		open_collectible_animation(game, gameplay, sprite, chunk_pos);
	else
		update_frame(sprite);
}
