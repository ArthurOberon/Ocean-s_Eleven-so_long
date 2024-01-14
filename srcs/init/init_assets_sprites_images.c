/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_sprites_images.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:02:17 by aoberon           #+#    #+#             */
/*   Updated: 2024/01/14 13:45:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Initialize a new image pointer.
 * 
 * @param game game struct, used to exit the game and free it if an error occurs.
 * @param ptr mlx_ptr, used to create a new mlx_img.
 * @param path path to the image file (.xpm).
 * @param img image struct, where the new image will be initialized.
 */
void	init_xpm_file(t_game *game, void *ptr, char *path, t_img *img)
{
	img->mlx_img = mlx_xpm_file_to_image(ptr, path, &img->size.x, &img->size.y);
	if (!img->mlx_img)
	{
		free(path);
		exit_game(*game, EXIT_FAILURE, "Error of mlx_xpm_file_to_image.\n");
	}
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
}

/**
 * @brief Initialize an new image resized.
 * 
 * @param game game struct, used to exit the game and free it if an error occurs.
 * @param ptr mlx_ptr, used to create a new mlx_img.
 * @param new_img new image resized.
 * @param new_size new size of the image.
 */
static void	init_new_resize_img(t_game *game, void *ptr, t_img *new_img,
	t_vector_2 new_size)
{
	new_img->mlx_img = mlx_new_image(ptr, new_size.x, new_size.y);
	if (!new_img->mlx_img)
		exit_game(*game, EXIT_FAILURE, "Error of mlx_xpm_file_to_image.\n");
	new_img->addr = mlx_get_data_addr(new_img->mlx_img, &new_img->bpp,
			&new_img->line_len, &new_img->endian);
	new_img->size = new_size;
}

/**
 * @brief Resize an image to a new size.
 * 
 * @param game game struct, used to get the window struct.
 * @param ptr mlx_ptr, used to create a new mlx_img.
 * @param src src image to resize.
 * @param dst_size new size of the image.
 * @return t_img new image resized.
 */
t_img	new_resize_img(t_game *game, void *ptr, t_img *src,
	t_vector_2 dst_size)
{
	int				i;
	int				j;
	t_f_vector_2	quotient;
	t_img			dst;
	__uint32_t		pixel;

	init_new_resize_img(game, ptr, &dst, dst_size);
	quotient.x = (double)(src->size.x) / (double)(dst_size.x);
	quotient.y = (double)(src->size.y) / (double)(dst_size.y);
	j = -1;
	while (++j < dst_size.y)
	{
		i = -1;
		while (++i < dst_size.x)
		{
			pixel = get_color_pixel(src, (int)(i * quotient.x),
					(int)(j * quotient.y));
			img_pix_put(&dst, i, j, pixel);
		}
	}
	return (dst);
}

/**
 * @brief Find the path of the sprite in the folder sprites.
 * 
 * @param game game struct, used to exit the program if malloc fail.
 * @param start_path path of the sprite without the frame number.
 * @param frame frame number of the sprite.
 * @return char* complete path of the sprite to the file.
 */
char	*find_sprite_path(t_game *game, char *start_path, int frame)
{
	char	*file_path;
	char	*frame_path;
	char	*complet_path;
	char	str_itoa[10];

	file_path = SPRITES_PATH;
	file_path = ft_strjoin(file_path, start_path);
	if (!file_path)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	ft_itoa(frame, str_itoa);
	frame_path = ft_strjoin(file_path, str_itoa);
	free(file_path);
	if (!frame_path)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	complet_path = ft_strjoin(frame_path, ".xpm");
	if (!complet_path)
		exit_game(*game, EXIT_FAILURE, "Error of malloc.\n");
	free(frame_path);
	return (complet_path);
}
