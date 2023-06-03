/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts_box_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:53:08 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/03 19:33:34 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_texts_box_list	*ft_lstlast_texts_box(t_texts_box_list *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

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

void	ft_lstdelone_texts_box(t_texts_box_list *lst)
{
	if (!lst)
		return ;
	free_text_box_text_pages(lst->text_box);
	free(lst->text_box);
	free(lst);
	lst = NULL;
}
