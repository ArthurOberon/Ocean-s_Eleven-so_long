/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 19:39:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_random_frame_animation(t_sprite *sprite, char character)
{
	// not commented
	if (character == '2' || character == 'C')
	{
		sprite->frame = rand() % sprite->size;
	}
}

void	sprite_cpy(t_sprite *new, t_sprite *src)
{
	// not commented
	new->frame = src->frame;
	new->last_time = src->last_time;
	new->size = src->size;
	new->sprite_img = src->sprite_img;
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
	map_sprites = ft_calloc(sizeof(t_sprite *), game->level->nb_cases);
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
			sprite_cpy(map_sprites[i], game->assets->ground);
		else if (game->level->map[i] == '1' || game->level->map[i] == '2')
			get_wall_image(game, &map_sprites[i], i);
		else if (game->level->map[i] == 'C')
			sprite_cpy(map_sprites[i], game->assets->collectible_idle);
		else if (game->level->map[i] == 'E')
			sprite_cpy(map_sprites[i], game->assets->exit);
		get_random_frame_animation(map_sprites[i], game->level->map[i]);
		i++;
	}
}
