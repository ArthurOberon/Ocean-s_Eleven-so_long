/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:06:11 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/05 22:13:23 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Get the size of the list.
 * 
 * @param lst list to get the size.
 * @return int size of the list.
 */
int	ft_lstsize(t_lst_map *lst)
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
 * @brief Get the last element of the list.
 * 
 * @param lst list to get the last element.
 * @return t_lst_map* last element of the list.
 */
t_lst_map	*ft_lstlast(t_lst_map *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/**
 * @brief Create a new list.
 * 
 * @param content content of the new list.
 * @return t_lst_map* new list created and initialized.
 */
t_lst_map	*ft_lstnew(void *content)
{
	t_lst_map	*newlist;

	newlist = malloc(sizeof(t_lst_map));
	if (newlist)
	{
		newlist->line = content;
		newlist->next = NULL;
	}
	return (newlist);
}

/**
 * @brief Add a new element at the end of the list.
 * 
 * @param lst list to add the new element.
 * @param new element to add.
 */
void	ft_lstadd_back(t_lst_map **lst, t_lst_map *new)
{
	t_lst_map	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

/**
 * @brief Clear the list.
 * 
 * @param lst list to clear.
 */
void	ft_lstclear(t_lst_map **lst)
{
	t_lst_map	*tmp;
	t_lst_map	*tmp2;

	if (!lst)
		return ;
	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp2->next;
		free(tmp->line);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
