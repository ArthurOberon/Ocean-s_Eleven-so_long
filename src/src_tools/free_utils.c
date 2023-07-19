/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:49:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/19 16:40:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_sprites(t_sprite **map_sprites, int size)
{
	int	i;

	if (!map_sprites)
		return ;
	i = 0;
	while (i < size)
	{
		if (map_sprites[i])
			free(map_sprites[i]);
		++i;
	}
	free(map_sprites);
}

void	free_collectibles(t_collectible *collectible,
	char *collectible_code, int size)
{
	// not commented
	int	i;

	if (collectible_code)
		free(collectible_code);
	i = 0;
	while (i < size)
	{
		free(collectible[i].sprite_open_animation);
		++i;
	}
	if (collectible)
		free(collectible);
}

/**
 * @brief Free text_pages of a text_box struct.
 * 
 * @param text_box text_box struct to free text_pages from.
 */
void	free_text_box_text_pages(t_text_box *text_box)
{
	int	i;

	if (!text_box->text_pages)
		return ;
	i = 0;
	while (text_box->text_pages[i])
	{
		free(text_box->text_pages[i]);
		i++;
	}
	free(text_box->text_pages);
	text_box->text_pages = NULL;
}

/**
 * @brief Free the text_boxs_list struct, named dialogue in the gameplay struct.
 * 
 * @param dialogue text_boxs_list struct to free.
 */
void	free_dialogue(t_texts_box_list *dialogue)
{
	if (dialogue->text_box)
		free_text_box_text_pages(dialogue->text_box);
	dialogue = ft_lstfirst_texts_box(dialogue);
	ft_lstclear_texts_box(&dialogue);
}

/**
 * @brief Free a 2 dimensional char array.
 * 
 * @param tab char array to free.
 * @param y size of the array.
 */
void	free_2d_char_tab(char **tab, int y)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < y)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}
