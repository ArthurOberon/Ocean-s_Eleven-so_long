/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:43:09 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 11:45:27 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	set_one_image(t_game *game, void *ptr, char *path, t_vector_2 dst_size)
{
	t_img	src;
	t_img	dst;

	init_xpm_file(game, ptr, path, &src);
	free(path);
	if (src.size.x == dst_size.x && src.size.y == dst_size.y)
		return (src);
	dst = new_resize_img(game, ptr, &src, dst_size);
	mlx_destroy_image(ptr, src.mlx_img);
	return (dst);
}

void	alloc_sprite_asset(t_game *game, t_sprite **asset, int size)
{
	t_sprite	*sprite;

	sprite = ft_calloc(sizeof(t_sprite), 1);
	if (!sprite)
		exit_game(*game, "Error of malloc.\n");
	sprite->frame = 0;
	sprite->size = size;
	sprite->last_time = (struct timeval){0, 0};
	sprite->sprite_img = ft_calloc(sizeof(t_img), size);
	if (!sprite->sprite_img)
		exit_game(*game, "Error of malloc.\n");
	*asset = sprite;
}

void	set_images_to_asset(t_game *game, t_sprite *sprite,
	char *path, t_vector_2 size)
{
	int		i;
	void	*ptr;
	char	*complet_path;

	ptr = game->window->mlx_ptr;
	i = 0;
	while (i < sprite->size)
	{
		complet_path = find_sprite_path(game, path, i);
		sprite->sprite_img[i] = set_one_image(game, ptr, complet_path, size);
		i++;
	}
}

static void	init_one_sprite_asset(t_game *game, t_sprite **sprite,
	t_init_sprite_asset_args init_sprite_asset_args)
{
	alloc_sprite_asset(game, sprite, init_sprite_asset_args.size);
	set_images_to_asset(game, *sprite,
		init_sprite_asset_args.path, init_sprite_asset_args.dst_size);
}

void	init_sprites_assets(t_game *game)
{
	t_sprites_assets	*assets;

	assets = ft_calloc(sizeof(t_sprites_assets), 1);
	if (!assets)
		exit_game(*game, "Error of malloc.\n");
	game->assets = assets;
	init_one_sprite_asset(game, &assets->player_danny, (t_init_sprite_asset_args){PATH_PLAYER_DANNY, FRAME_PLAYER_DANNY, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_rusty, (t_init_sprite_asset_args){PATH_PLAYER_RUSTY, FRAME_PLAYER_RUSTY, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_linus, (t_init_sprite_asset_args){PATH_PLAYER_LINUS, FRAME_PLAYER_LINUS, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->player_basher, (t_init_sprite_asset_args){PATH_PLAYER_BASHER, FRAME_PLAYER_BASHER, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->exit, (t_init_sprite_asset_args){PATH_EXIT, FRAME_EXIT, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->collect, (t_init_sprite_asset_args){PATH_COLLECT, FRAME_COLLECT, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->ground, (t_init_sprite_asset_args){PATH_GROUND, FRAME_GROUND, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->guard, (t_init_sprite_asset_args){PATH_GUARD, FRAME_GUARD, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->guard_fov, (t_init_sprite_asset_args){PATH_GUARD_FOV, FRAME_GUARD_FOV, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_corner_n_e, (t_init_sprite_asset_args){PATH_WALL_CORNER_N_E, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_corner_n_o, (t_init_sprite_asset_args){PATH_WALL_CORNER_N_O, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_corner_s_o, (t_init_sprite_asset_args){PATH_WALL_CORNER_S_O, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_corner_s_e, (t_init_sprite_asset_args){PATH_WALL_CORNER_S_E, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_up, (t_init_sprite_asset_args){PATH_WALL_SIDE_UP, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_down, (t_init_sprite_asset_args){PATH_WALL_SIDE_DOWN, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_left, (t_init_sprite_asset_args){PATH_WALL_SIDE_LEFT, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_side_right, (t_init_sprite_asset_args){PATH_WALL_SIDE_RIGHT, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_roulette, (t_init_sprite_asset_args){PATH_WALL_ROULETTE, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->wall_poker, (t_init_sprite_asset_args){PATH_WALL_POKER, 1, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->dynamite, (t_init_sprite_asset_args){PATH_DYNAMITE, FRAME_DYNAMITE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->explosion, (t_init_sprite_asset_args){PATH_EXPLOSION, FRAME_EXPLOSION, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->area_qte, (t_init_sprite_asset_args){PATH_AREA_QTE, FRAME_AREA_QTE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->qte, (t_init_sprite_asset_args){PATH_QTE, FRAME_QTE, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->heart, (t_init_sprite_asset_args){PATH_HEART, FRAME_HEART, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->box, (t_init_sprite_asset_args){PATH_BOX, FRAME_BOX, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->selection_box, (t_init_sprite_asset_args){PATH_SELECTION_BOX, FRAME_SELECTION_BOX, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});
	init_one_sprite_asset(game, &assets->avatar_character, (t_init_sprite_asset_args){PATH_AVATAR_CHARACTER, FRAME_AVATAR_CHARACTER, (t_vector_2){CHUNK_SIZE, CHUNK_SIZE}});

	init_one_sprite_asset(game, &assets->alphabet, (t_init_sprite_asset_args){PATH_ALPHABET,  FRAME_ALPHABET, (t_vector_2){16, 16}});
	init_one_sprite_asset(game, &assets->special_character, (t_init_sprite_asset_args){PATH_SPECIAL_CHAR,  FRAME_SPECIAL_CHAR, (t_vector_2){16, 16}});
	init_one_sprite_asset(game, &assets->background_text, (t_init_sprite_asset_args){PATH_BACKGROUND_TEXT,  FRAME_BACKGROUND_TEXT, (t_vector_2){WINDOW_WIDTH - 40, WINDOW_HEIGHT / 4}});

}
