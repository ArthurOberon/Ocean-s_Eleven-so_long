/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_features_animation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:54:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/23 12:05:05 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_animation(t_gameplay *gameplay, t_sprite *sprite)
{
	if (gameplay->nb_collect_remain != 0)
		return ;
	update_frame(sprite);
}

static void	collectible_animation(t_gameplay *gameplay, t_sprite *sprite)
{
	
}

void	get_animation(t_game *game, t_gameplay *gameplay, t_sprite *sprite,
	int chunk_pos)
{
	char	character;

	character = game->level->map[chunk_pos];
	if (character == 'E')
		exit_animation(gameplay, sprite);
	else if (character == 'C')
		collectible_animation(gameplay, sprite);
	else
		update_frame(sprite);
}
