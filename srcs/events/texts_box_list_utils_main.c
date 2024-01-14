/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts_box_list_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:53:08 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/06 21:13:30 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get the size of a texts_box_list.
 * 
 * @param lst list to get the size.
 * @return int size of the list.
 */
int	ft_lstsize_texts_box(t_texts_box_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/**
 * @brief Get the first element of a texts_box_list.
 * 
 * @param lst list to get the first element.
 * @return t_texts_box_list* first element of the list.
 */
t_texts_box_list	*ft_lstfirst_texts_box(t_texts_box_list *lst)
{
	while (lst && lst->prev)
	{
		lst = lst->prev;
	}
	return (lst);
}

/**
 * @brief Get the last element of a texts_box_list.
 * 
 * @param lst list to get the last element.
 * @return t_texts_box_list* last element of the list.
 */
t_texts_box_list	*ft_lstlast_texts_box(t_texts_box_list *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/**
 * @brief Create a new node for a texts_box_list.
 * 
 * @param text_box text_box to add to the node.
 * @return t_texts_box_list* new node created.
 */
t_texts_box_list	*ft_lstnew_texts_box(t_text_box *text_box)
{
	t_texts_box_list	*newlist;

	newlist = ft_calloc(sizeof(t_texts_box_list), 1);
	if (newlist)
	{
		newlist->text_box = text_box;
		newlist->next = NULL;
		newlist->prev = NULL;
	}
	return (newlist);
}

/**
 * @brief Add a new node to the front of a texts_box_list.
 * 
 * @param lst list to add node to.
 * @param new node to add.
 */
void	ft_lstadd_back_texts_box(t_texts_box_list **lst, t_texts_box_list *new)
{
	t_texts_box_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast_texts_box(*lst);
	tmp->next = new;
	new->prev = tmp;
}
