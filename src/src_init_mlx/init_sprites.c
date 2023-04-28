/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 19:48:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_sprite(t_game *game, t_sprite *sprite, int i)
{
	if (game->level.map[i] == '0' || game->level.map[i] == 'P')
		*sprite = game->assets.ground;
	else if (game->level.map[i] == '1')
		get_wall_image(game, sprite, i);
	else if (game->level.map[i] == 'C')
		*sprite = game->assets.collect;
	else if (game->level.map[i] == 'E')
		*sprite = game->assets.exit;
}

void	init_sprites(t_game *game)
{
	int			i;
	t_sprite	*map_sprites;

	i = 0;
	map_sprites = ft_calloc(sizeof(t_sprite), game->level.nb_cases + 1);
	if (!map_sprites)
		free_game(*game, "Error of malloc\n");
	while (i < game->level.nb_cases)
	{
		get_sprite(game, &map_sprites[i], i);
		i++;
	}
	map_sprites[i] = game->assets.player;
	game->window.map_sprites = map_sprites;
}
