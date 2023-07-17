/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:04:26 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 18:56:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Put a img on a specific position on another img
 * with limit to put only the sprite on a screen.
 * 
 * @param window_img image of the window to put the img on.
 * @param pos position to put the img on.
 * @param img img to put.
 * @param limit limit of the sprite to put,
 * used to avoid put all the image when it's on the edge of the screen.
 */
static void	put_image_to_image_with_limit(t_img *window_img, t_vector_2 pos,
	t_img *img, t_vector_2 *limit)
{
	int			i;
	int			j;
	__uint32_t	pixel;

	j = limit[0].y;
	while (j < img->size.y - limit[1].y)
	{
		i = limit[0].x;
		while (i < img->size.x - limit[1].x)
		{
			pixel = get_color_pixel(img, i, j);
			if ((pixel >> 24) != 0xFF)
				img_pix_put(window_img, i + pos.x, j + pos.y, pixel);
			i++;
		}
		j++;
	}
}

/**
 * @brief Display one sprite on the window
 * but using put_image_to_image_with_limit for the transparency.
 * With protection against chunks on the edge of the window.
 * 
 * @param window window struct, to display on.
 * @param sprite sprite to display.
 * @param pos position to display the sprite.
 */
void	display_one_sprite_with_transparency(t_window *window,
	t_sprite *sprite, t_vector_2 pos)
{
	t_vector_2	limit[2];

	limit[0] = (t_vector_2){0, 0};
	limit[1] = (t_vector_2){0, 0};
	if ((int)pos.x < 0)
	{
		limit[0].x = -pos.x;
	}
	if ((int)pos.y < 0)
	{
		limit[0].y = -pos.y;
	}
	if ((int)pos.x + sprite->sprite_img->size.x > window->img.size.x)
		limit[1].x = (pos.x + sprite->sprite_img->size.x)
			- window->img.size.x;
	if ((int)pos.y + sprite->sprite_img->size.y > window->img.size.y)
		limit[1].y = (pos.y + sprite->sprite_img->size.y)
			- window->img.size.y;
	put_image_to_image_with_limit(&window->img, pos,
		&sprite->sprite_img[sprite->frame], limit);
}
