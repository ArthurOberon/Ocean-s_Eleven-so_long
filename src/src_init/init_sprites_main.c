/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 23:56:28 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_cpy(t_sprite *new, t_sprite *src)
{
	// not commented
	new->frame = src->frame;
	new->last_time = src->last_time;
	new->size = src->size;
	new->sprite_img = src->sprite_img;
}

/**
 * @brief Initialize all extra map sprites.
 * 
 * @param game game struct, used to get the assets struct.
 * @param map_sprites map of sprites.
 * @param i index of the map_sprites array,
 * and end of the sprites of the level (i == length of map string).
 */
static void	init_sprites_extra_map(t_game *game, t_sprite **map_sprites, int i)
{
	map_sprites[i + e_player_danny] = game->assets->player_danny;
	map_sprites[i + e_player_rusty] = game->assets->player_rusty;
	map_sprites[i + e_player_linus] = game->assets->player_linus;
	map_sprites[i + e_player_basher] = game->assets->player_basher;
	// map_sprites[i + e_dynamite] = game->assets->dynamite;
	// map_sprites[i + e_explosion] = game->assets->explosion;
	map_sprites[i + e_area_qte] = game->assets->area_qte; // TO DELETE ?
	map_sprites[i + e_qte] = game->assets->qte; // TO DELETE ?
	map_sprites[i + e_guards] = game->assets->guard; // TO DELETE ?
	// map_sprites[i + e_guard_fov] = game->assessts->guard_fov;
	// map_sprites[i + e_button_pause] = game->assets->button_pause;
	// map_sprites[i + e_button_reset] = game->assets->button_reset;
	// map_sprites[i + e_button_quit] = game->assets->button_quit;
	// map_sprites[i + e_button_tutorial] = game->assets->button_tutorial;
	// map_sprites[i + e_heart] = game->assets->heart;
	// map_sprites[i + e_box] = game->assets->box;
	// map_sprites[i + e_selection_box] = game->assets->selection_box;
	// map_sprites[i + e_avatar_character] = game->assets->avatar_character;
	// map_sprites[i + e_alphabet] = game->assets->alphabet;
	// map_sprites[i + e_special_character] = game->assets->special_character;
	// map_sprites[i + e_background_text] = game->assets->background_text;
	map_sprites[i + e_talking_danny] = game->assets->talking_danny;
	map_sprites[i + e_talking_rusty] = game->assets->talking_rusty;
	map_sprites[i + e_talking_linus] = game->assets->talking_linus;
	map_sprites[i + e_talking_basher] = game->assets->talking_basher;
	// map_sprites[i + e_tutorial] = game->assets->tutorial;
}

/**
 * @brief init all sprites of the game.
 * 
 * @param game game struct, used to get the level and assets struct.
 */
void	init_sprites(t_game *game)
{
	int			i;
	t_sprite	**map_sprites;

	i = 0;
	map_sprites = ft_calloc(sizeof(t_sprite *), game->level->nb_cases
			+ e_total_assets);
	if (!map_sprites)
		exit_game(*game, "Error of malloc.\n");
	game->window->map_sprites = map_sprites;
	while (i < game->level->nb_cases)
	{
		map_sprites[i] = ft_calloc(sizeof(t_sprite), 1);
		if (!map_sprites[i])
			exit_game(*game, "Error of malloc.\n");
		if (game->level->map[i] == '0' || game->level->map[i] == 'P'
			|| game->level->map[i] == 'G')
			map_sprites[i] = game->assets->ground;
		else if (game->level->map[i] == '1' || game->level->map[i] == '2')
			get_wall_image(game, &map_sprites[i], i);
		else if (game->level->map[i] == 'C')
			sprite_cpy(map_sprites[i], game->assets->collectible_idle);
		else if (game->level->map[i] == 'E')
			map_sprites[i] = game->assets->exit;
		init_sprites_animations(game, map_sprites[i], game->level->map[i]);
		i++;
	}
	init_sprites_extra_map(game, map_sprites, i);
}
