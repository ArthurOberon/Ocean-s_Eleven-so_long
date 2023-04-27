/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 20:47:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_img *image_asset, t_sprite *sprite, int size)
{
	sprite->frame = 0;
	sprite->size = size;
	sprite->last_time = 0;
	printf("assets : [%p]\n", (void *)image_asset);
	sprite->sprite_img = image_asset;
}

void	get_sprite(t_game *game, t_sprite *sprite, int i)
{
	printf("tile: %c %d\n", game->level.map[i], i);
	if (game->level.map[i] == '0' || game->level.map[i] == 'P')
		init_sprite(game->assets.ground, sprite, FRAME_GROUND);
	else if (game->level.map[i] == '1')
		get_wall_image(game, game->assets, sprite, i);
	else if (game->level.map[i] == 'C')
		init_sprite(game->assets.collect, sprite, FRAME_COLLECT);
	else if (game->level.map[i] == 'E')
		init_sprite(game->assets.exit, sprite, FRAME_EXIT);
}

void	init_sprites(t_game *game)
{
	int			i;
	t_sprite	*map_sprites;

	i = 0;
	map_sprites = malloc(sizeof(t_sprite) * (game->level.nb_cases + 1));
	if (!map_sprites)
		printf("PANIC ! free and exit.\n");
	while (i < game->level.nb_cases)
	{
		get_sprite(game, &map_sprites[i], i);
		i++;
	}
	init_sprite(game->assets.player, &map_sprites[i], FRAME_PLAYER);
	game->window.map_sprites = map_sprites;
}
