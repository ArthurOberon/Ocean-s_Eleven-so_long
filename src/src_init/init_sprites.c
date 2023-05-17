/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/17 18:34:32 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_game *game)
{
	int			i;
	t_sprite	**map_sprites;

	i = 0;
	map_sprites = ft_calloc(sizeof(t_sprite *), game->level->nb_cases
			+ e_total_assets);
	if (!map_sprites)
		free_game(*game, "Error of malloc.\n");
	game->window->map_sprites = map_sprites;
	while (i < game->level->nb_cases)
	{
		if (game->level->map[i] == '0' || game->level->map[i] == 'P'
			|| game->level->map[i] == 'G')
			map_sprites[i] = game->assets->ground;
		else if (game->level->map[i] == '1' || game->level->map[i] == '2')
			get_wall_image(game, &map_sprites[i], i);
		else if (game->level->map[i] == 'C')
			map_sprites[i] = game->assets->collect;
		else if (game->level->map[i] == 'E')
			map_sprites[i] = game->assets->exit;
		i++;
	}
	map_sprites[i + e_player_danny] = game->assets->player_danny;
	map_sprites[i + e_player_rusty] = game->assets->player_rusty;
	map_sprites[i + e_player_linus] = game->assets->player_danny;
	map_sprites[i + e_player_basher] = game->assets->player_rusty;
	map_sprites[i + e_dynamite] = game->assets->dynamite;
	map_sprites[i + e_area_qte] = game->assets->area_qte;
	map_sprites[i + e_qte] = game->assets->qte;
	map_sprites[i + e_guards] = game->assets->guard;
	map_sprites[i + e_guard_fov] = game->assets->guard_fov;
	map_sprites[i + e_heart] = game->assets->heart;
}
