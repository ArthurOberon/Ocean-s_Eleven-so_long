/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_tools.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:43:09 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/07 22:10:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Create one image.
 * 
 * @param game game struct, used to get the window struct.
 * @param ptr mlx_ptr, used to create the image.
 * @param path path to the image file (.xpm).
 * @param dst_size size of the new image.
 * @return t_img new image created.
 */
t_img	create_one_image(t_game *game, void *ptr, char *path,
	t_vector_2 dst_size)
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

/**
 * @brief Allocate a new sprite asset.
 * 
 * @param game game struct, to exit the game if a malloc fail.
 * @param asset asset struct, where the new asset will be allocated.
 * @param size number of images (frames of animation) of the asset.
 */
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

/**
 * @brief Set the images to a asset.
 * 
 * @param game game struct, used to get the window struct.
 * @param sprite sprite struct, where the images will be set.
 * @param path path of the images.
 * @param size size of the images.
 */
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
		sprite->sprite_img[i] = create_one_image(game, ptr, complet_path, size);
		i++;
	}
}

/**
 * @brief Initialize a sprite asset.
 * 
 * @param game game struct, used to get the window struct.
 * @param sprite sprite struct to initialize.
 * @param init_sprite_asset_args struct with the arguments
 * to initialize the sprite.
 */
void	init_one_sprite_asset(t_game *game, t_sprite **sprite,
	t_init_sprite_asset_args init_sprite_asset_args)
{
	alloc_sprite_asset(game, sprite, init_sprite_asset_args.size);
	set_images_to_asset(game, *sprite,
		init_sprite_asset_args.path, init_sprite_asset_args.dst_size);
}
