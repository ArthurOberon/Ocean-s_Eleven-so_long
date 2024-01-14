/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts_box_list_utils_free.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:13:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 21:13:58 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Delete and free a single node from a texts_box_list.
 * 
 * @param lst list to delete node from.
 */
void	ft_lstdelone_texts_box(t_texts_box_list *lst)
{
	if (!lst)
		return ;
	free_text_box_text_pages(lst->text_box);
	free(lst->text_box);
	free(lst);
	lst = NULL;
}

/**
 * @brief Delete and free all nodes from a texts_box_list.
 * 
 * @param lst list to delete nodes from.
 */
void	ft_lstclear_texts_box(t_texts_box_list **lst)
{
	t_texts_box_list	*tmp;
	t_texts_box_list	*tmp_next;

	if (!lst)
		return ;
	tmp = *lst;
	tmp_next = *lst;
	while (tmp)
	{
		tmp_next = tmp_next->next;
		ft_lstdelone_texts_box(tmp);
		tmp = tmp_next;
	}
	*lst = NULL;
}
