/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:56:08 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/27 22:04:20 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_number_of_tile(t_game *game, char tile)
{
	int	i;
	int	number_tile;

	i = 0;
	number_tile = 0;
	while (i < game->level.nb_cases)
	{
		if (game->level.map[i] == tile)
			number_tile++;
		i++;
	}
	return (number_tile);
}

static char	*find_sprite_path(char *start_path, int frame)
{
	char	*file_path;
	char	*str_itoa;
	char	*frame_path;
	char	*complet_path;

	file_path = SPRITES_PATH;
	file_path = ft_strjoin(file_path, start_path);
	if (!file_path)
		printf("PANIC ! free and exit.\n");
	str_itoa = ft_itoa(frame);
	if (!str_itoa)
		printf("PANIC ! free and exit.\n");
	frame_path = ft_strjoin(file_path, str_itoa);
	if (!frame_path)
		printf("PANIC ! free and exit.\n");
	free(file_path);
	free(str_itoa);
	complet_path = ft_strjoin(frame_path, ".xpm");
	if (!complet_path)
		printf("PANIC ! free and exit.\n");
	free(frame_path);
	return (complet_path);
}

static void	get_stat_tiles_map(t_game *game)
{
	t_stat_tiles	stat_tiles;

	stat_tiles.exit = get_number_of_tile(game, 'E');
	stat_tiles.wall = get_number_of_tile(game, '1');
	stat_tiles.ground = get_number_of_tile(game, '0');
	stat_tiles.player = get_number_of_tile(game, 'P');
	stat_tiles.collect = get_number_of_tile(game, 'C');
	game->level.stat_tiles = stat_tiles;
	if (IS_DEBUG)
		debug_stat_tiles(stat_tiles);
}

static void	sprite_to_assets(void *ptr, t_sprite *sprite, char *path,
	int size)
{
	int		i;
	char	*complet_path;

	sprite->frame = 0;
	sprite->size = size;
	sprite->last_time = 0;
	sprite->sprite_img = malloc(sizeof(t_img) * size);
	if (!sprite->sprite_img)
		printf("PANIC ! free and exit.\n");
	i = 0;
	while (i < size)
	{
		complet_path = find_sprite_path(path, i);
		init_xpm_file(ptr, complet_path, &(sprite->sprite_img)[i]);
		(sprite->sprite_img)[i] = resize_img(ptr, &(sprite->sprite_img)[i],
				(t_vector_2){CHUNK_SIZE, CHUNK_SIZE});
		free(complet_path);
		i++;
	}
}

void	init_sprites_assets(void *ptr, t_game *game, t_sprites_assets *assets)
{
	get_stat_tiles_map(game);
	sprite_to_assets(ptr, &assets->player, PATH_PLAYER, FRAME_PLAYER);
	sprite_to_assets(ptr, &assets->exit, PATH_EXIT, FRAME_EXIT);
	sprite_to_assets(ptr, &assets->collect, PATH_COLLECT, FRAME_COLLECT);
	sprite_to_assets(ptr, &assets->ground, PATH_GROUND, FRAME_GROUND);
	sprite_to_assets(ptr, &assets->wall_corner_n_e, PATH_WALL_CORNER_N_E, 1);
	sprite_to_assets(ptr, &assets->wall_corner_n_o, PATH_WALL_CORNER_N_O, 1);
	sprite_to_assets(ptr, &assets->wall_corner_s_o, PATH_WALL_CORNER_S_O, 1);
	sprite_to_assets(ptr, &assets->wall_corner_s_e, PATH_WALL_CORNER_S_E, 1);
	sprite_to_assets(ptr, &assets->wall_side_up, PATH_WALL_SIDE_UP, 1);
	sprite_to_assets(ptr, &assets->wall_side_down, PATH_WALL_SIDE_DOWN, 1);
	sprite_to_assets(ptr, &assets->wall_side_left, PATH_WALL_SIDE_LEFT, 1);
	sprite_to_assets(ptr, &assets->wall_side_right, PATH_WALL_SIDE_RIGHT, 1);
	sprite_to_assets(ptr, &assets->wall_inside, PATH_WALL_INSIDE, 1);
}
