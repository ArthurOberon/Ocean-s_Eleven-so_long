/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:00:00 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/01 23:40:11 by arthurobero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	set_text_box(t_game *game, t_text_box *text_box, char *text)
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
		free_game(*game, NULL);
	text_box->is_display = true;
	game->gameplay->is_stop = true;
	text_box->read_all = false;
}

void	display_text(t_game *game, t_text_box *text_box, t_text *text,
	bool not_display_again)
{
	if (text->has_been_display == false)
	{
		set_text_box(game, text_box, text->text);
		text->has_been_display = not_display_again;
	}
}
