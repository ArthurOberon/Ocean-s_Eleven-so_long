/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deprecated_init_images_assets.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:03:08 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/28 22:38:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	get_number_of_tile(t_game *game, char tile)
// {
// 	int	i;
// 	int	number_tile;

// 	i = 0;
// 	number_tile = 0;
// 	while (i < game->level.nb_cases)
// 	{
// 		if (game->level.map[i] == tile)
// 			number_tile++;
// 		i++;
// 	}
// 	return (number_tile);
// }

// static char	*find_sprite_path(char *start_path, int frame)
// {
// 	char	*file_path;
// 	char	*str_itoa;
// 	char	*frame_path;
// 	char	*complet_path;

// 	file_path = SPRITES_PATH;
// 	file_path = ft_strjoin(file_path, start_path);
// 	if (!file_path)
// 		printf("PANIC ! free and exit.\n");
// 	str_itoa = ft_itoa(frame);
// 	if (!str_itoa)
// 		printf("PANIC ! free and exit.\n");
// 	frame_path = ft_strjoin(file_path, str_itoa);
// 	if (!frame_path)
// 		printf("PANIC ! free and exit.\n");
// 	free(file_path);
// 	free(str_itoa);
// 	complet_path = ft_strjoin(frame_path, ".xpm");
// 	if (!complet_path)
// 		printf("PANIC ! free and exit.\n");
// 	free(frame_path);
// 	return (complet_path);
// }

// static void	get_stat_tiles_map(t_game *game)
// {
// 	t_stat_tiles	stat_tiles;

// 	stat_tiles.exit = get_number_of_tile(game, 'E');
// 	stat_tiles.wall = get_number_of_tile(game, '1');
// 	stat_tiles.ground = get_number_of_tile(game, '0');
// 	stat_tiles.player = get_number_of_tile(game, 'P');
// 	stat_tiles.collect = get_number_of_tile(game, 'C');
// 	game->level.stat_tiles = stat_tiles;
// 	if (IS_DEBUG)
// 		debug_stat_tiles(stat_tiles);
// }

// static void	*get_images_to_assets(void *ptr, t_img *img, char *path,
	// int size)
// {
// 	int		i;
// 	char	*complet_path;

// 	i = 0;
// 	img = malloc(sizeof(t_img) * size);
// 	if (!img)
// 		printf("PANIC ! free and exit.\n");
// 	while (i < size)
// 	{
// 		complet_path = find_sprite_path(path, i);
// 		init_xpm_file(ptr, complet_path, &img[i]);
// 		img[i] = resize_img(ptr, &img[i], (t_vector_2){CHUNK_SIZE, CHUNK_SIZE});
// 		free(complet_path);
// 		i++;
// 	}
// 	return (img);
// }

// void	init_game_assets(t_images_assets *a, t_images_assets *b)
// {
// 	a->player = b->player;
// 	a->exit = b->exit;
// 	a->collect = b->collect;
// 	a->ground = b->ground;
// 	a->wall_corner_n_e = b->wall_corner_n_e;
// 	a->wall_corner_n_o = b->wall_corner_n_o;
// 	a->wall_corner_s_o = b->wall_corner_s_o;
// 	a->wall_corner_s_e = b->wall_corner_s_e;
// 	a->wall_side_up = b->wall_side_up;
// 	a->wall_side_down = b->wall_side_down;
// 	a->wall_side_left = b->wall_side_left;
// 	a->wall_side_right = b->wall_side_right;
// 	a->wall_inside = b->wall_inside;
// }

// void	init_images_assets(void *ptr, t_game *game)
// {
// 	t_images_assets	assets;

// 	assets = game->assets;
// 	get_stat_tiles_map(game);
// 	if (game->level.stat_tiles.wall
// 		- (game->level.map_vector.x * 2)
	// + (((game->level.map_vector.y * 2) - 4))
// 		!= 0)
// 	{
// 		assets.wall_inside = get_images_to_assets(ptr, assets.wall_inside,
						// PATH_WALL_INSIDE,1);
// 	}
// 	assets.player = get_images_to_assets(ptr, assets.player,
						// PATH_PLAYER,FRAME_PLAYER);
// 	assets.exit = get_images_to_assets(ptr, assets.exit,
						// PATH_EXIT,FRAME_EXIT);
// 	assets.collect = get_images_to_assets(ptr, assets.collect,
						// PATH_COLLECT,FRAME_COLLECT);
// 	assets.ground = get_images_to_assets(ptr, assets.ground,
						// PATH_GROUND,FRAME_GROUND);
// 	assets.wall_corner_n_e = get_images_to_assets(ptr, assets.wall_corner_n_e,
						// PATH_WALL_CORNER_N_E,1);
// 	assets.wall_corner_n_o = get_images_to_assets(ptr, assets.wall_corner_n_o,
						// PATH_WALL_CORNER_N_O,1);
// 	assets.wall_corner_s_o = get_images_to_assets(ptr, assets.wall_corner_s_o,
						// PATH_WALL_CORNER_S_O,1);
// 	assets.wall_corner_s_e = get_images_to_assets(ptr, assets.wall_corner_s_e,
						// PATH_WALL_CORNER_S_E,1);
// 	assets.wall_side_up = get_images_to_assets(ptr, assets.wall_side_up,
						// PATH_WALL_SIDE_UP,1);
// 	assets.wall_side_down = get_images_to_assets(ptr, assets.wall_side_down,
						// PATH_WALL_SIDE_DOWN,1);
// 	assets.wall_side_left = get_images_to_assets(ptr, assets.wall_side_left,
						// PATH_WALL_SIDE_LEFT,1);
// 	assets.wall_side_right = get_images_to_assets(ptr, assets.wall_side_right,
						// PATH_WALL_SIDE_RIGHT,1);
// 	init_game_assets(&game->assets, &assets);
// }

// init_xpm_file for each tiles on maps
