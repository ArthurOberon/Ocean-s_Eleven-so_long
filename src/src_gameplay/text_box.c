/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:00:00 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 21:20:55 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Copy n char from src to dest.
 * 
 * @param src string to copy.
 * @param n number of char to copy.
 * @return char* string copied.
 */
static char	*ft_strncpy(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * @brief Divide a string in n part of size.
 * 
 * @param str string to divide.
 * @param size size of each part.
 * @param n number of part.
 * @return char** string divided in n part of size.
 */
char	**str_n_divide(char *str, int size, int n)
{
	int		i;
	char	**result;

	result = ft_calloc(sizeof(char *), n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (i < n - 1)
		{
			result[i] = ft_strncpy(str, size);
			if (!result[i])
				return (free_2d_char_tab(result, i), NULL);
			str += size;
		}
		else
		{
			result[i] = ft_strncpy(str, ft_strlen(str));
			if (!result[i])
				return (free_2d_char_tab(result, i), NULL);
		}
		i++;
	}
	return (result);
}

/**
 * @brief Set the text_box with a text.
 * 
 * @param game game struct, used to exit_game if malloc fail.
 * @param text_box text_box struct to set.
 * @param text text to set with.
 */
static void	set_text_box(t_game *game, t_text_box *text_box, char *text)
{
	int	text_size;
	int	divide_size;

	if (text_box->text != NULL)
		return ;
	text_box->text = text;
	text_size = ft_strlen(text_box->text);
	divide_size = text_size / text_box->characters_max_one_box
		+ ((text_size % text_box->characters_max_one_box) != 0);
	text_box->page_number = divide_size;
	text_box->page_in = 0;
	text_box->text_pages = str_n_divide(text,
			text_box->characters_max_one_box, divide_size);
	if (!text_box->text_pages)
		exit_game(*game, "Error of malloc.\n");
	text_box->is_display = true;
	game->gameplay->is_stop = true;
	text_box->read_all = false;
}

/**
 * @brief Add one text (t_text) to the dialogue (t_texts_box_list).
 * 
 * @param game game struct, used to exit_game if malloc fail.
 * @param texts_box_list texts_box_list struct to the text to.
 * @param text text struct to add.
 */
void	add_one_text_to_dialogue(t_game *game,
	t_texts_box_list **texts_box_list, t_text *text)
{
	t_texts_box_list	*new;
	t_text_box			*text_box;

	if (text->has_been_display == false)
	{
		text_box = ft_calloc(sizeof(t_text_box), 1);
		if (!text_box)
			exit_game(*game, "Error of malloc.\n");
		init_one_text_box(game, game->window, game->gameplay, text_box);
		set_text_box(game, text_box, text->text);
		text->has_been_display = true;
		new = ft_lstnew_texts_box(text_box);
		if (!new)
			exit_game(*game, "Error of malloc.\n");
		ft_lstadd_back_texts_box(texts_box_list, new);
	}
}
