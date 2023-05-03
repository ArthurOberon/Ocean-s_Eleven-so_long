/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:56:08 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/03 23:09:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_number_of_tile(t_game *game, char tile)
{
	int	i;
	int	number_tile;

	i = 0;
	number_tile = 0;
	while (i < game->level->nb_cases)
	{
		if (game->level->map[i] == tile)
			number_tile++;
		i++;
	}
	if (tile == 'C')
		printf("C : [%d]\n", number_tile);
	return (number_tile);
}

static void	get_stat_tiles_map(t_game *game)
{
	t_stat_tiles	stat_tiles;

	stat_tiles.exit = get_number_of_tile(game, 'E');
	stat_tiles.wall = get_number_of_tile(game, '1');
	stat_tiles.ground = get_number_of_tile(game, '0');
	stat_tiles.player = get_number_of_tile(game, 'P');
	stat_tiles.collect = get_number_of_tile(game, 'C');
	game->level->stat_tiles = stat_tiles;
	if (IS_DEBUG)
		debug_stat_tiles(stat_tiles);
}

static char	*find_sprite_path(t_game *game, char *start_path, int frame)
{
	char	*file_path;
	char	*str_itoa;
	char	*frame_path;
	char	*complet_path;

	file_path = SPRITES_PATH;
	file_path = ft_strjoin(file_path, start_path);
	if (!file_path)
		free_game(*game, "Error of malloc.\n");
	str_itoa = ft_itoa(frame);
	if (!str_itoa)
		free_game(*game, "Error of malloc.\n");
	frame_path = ft_strjoin(file_path, str_itoa);
	free(str_itoa);
	free(file_path);
	if (!frame_path)
		free_game(*game, "Error of malloc.\n");
	complet_path = ft_strjoin(frame_path, ".xpm");
	if (!complet_path)
		free_game(*game, "Error of malloc.\n");
	free(frame_path);
	return (complet_path);
}

static void	sprite_to_assets(t_game *game, t_sprite **asset, char *path,
	int size)
{
	int			i;
	char		*complet_path;
	void		*ptr;
	t_sprite	*sprite;

	sprite = ft_calloc(sizeof(t_sprite), 1);
	if (!sprite)
		free_game(*game, "Error of malloc.\n");
	ptr = game->window->mlx_ptr;
	sprite->frame = 0;
	sprite->size = size;
	sprite->last_time = 0;
	sprite->sprite_img = ft_calloc(sizeof(t_img), size);
	if (!sprite->sprite_img)
		free_game(*game, "Error of malloc.\n");
	i = -1;
	while (++i < size)
	{
		complet_path = find_sprite_path(game, path, i);
		init_xpm_file(game, ptr, complet_path, &(sprite->sprite_img)[i]);
		(sprite->sprite_img)[i] = resize_img(game, ptr,
				&(sprite->sprite_img)[i], (t_vector_2){CHUNK_SIZE, CHUNK_SIZE});
		free(complet_path);
	}
	*asset = sprite;
}

void	init_sprites_assets(t_game *game)
{
	t_sprites_assets	*assets;

	assets = ft_calloc(sizeof(t_sprites_assets), 1);
	if (!assets)
		free_game(*game, "Error of malloc.\n");
	game->assets = assets;
	sprite_to_assets(game, &assets->player, PATH_PLAYER, FRAME_PLAYER);
	sprite_to_assets(game, &assets->exit, PATH_EXIT, FRAME_EXIT);
	sprite_to_assets(game, &assets->collect, PATH_COLLECT, FRAME_COLLECT);
	sprite_to_assets(game, &assets->ground, PATH_GROUND, FRAME_GROUND);
	sprite_to_assets(game, &assets->wall_corner_n_e, PATH_WALL_CORNER_N_E, 1);
	sprite_to_assets(game, &assets->wall_corner_n_o, PATH_WALL_CORNER_N_O, 1);
	sprite_to_assets(game, &assets->wall_corner_s_o, PATH_WALL_CORNER_S_O, 1);
	sprite_to_assets(game, &assets->wall_corner_s_e, PATH_WALL_CORNER_S_E, 1);
	sprite_to_assets(game, &assets->wall_side_up, PATH_WALL_SIDE_UP, 1);
	sprite_to_assets(game, &assets->wall_side_down, PATH_WALL_SIDE_DOWN, 1);
	sprite_to_assets(game, &assets->wall_side_left, PATH_WALL_SIDE_LEFT, 1);
	sprite_to_assets(game, &assets->wall_side_right, PATH_WALL_SIDE_RIGHT, 1);
	sprite_to_assets(game, &assets->wall_inside, PATH_WALL_INSIDE, 1);
}

	// get_stat_tiles_map(game);
