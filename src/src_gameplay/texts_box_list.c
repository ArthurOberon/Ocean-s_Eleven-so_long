/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts_box_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthuroberon <arthuroberon@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:53:08 by arthurobero       #+#    #+#             */
/*   Updated: 2023/06/01 23:37:55 by arthurobero      ###   ########.fr       */
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

	newlist = malloc(sizeof(t_texts_box_list));
	if (newlist)
	{
		newlist->text_box = text_box;
		newlist->next = NULL;
	}
	return (newlist);
}

void	ft_lstclear_texts_box(t_texts_box_list **lst)
{
	t_texts_box_list	*tmp;
	t_texts_box_list	*tmp2;

	if (!lst)
		return ;
	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp2->next;
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
		// free(tmp->text_box);

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
}
