/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:06:11 by aoberon           #+#    #+#             */
/*   Updated: 2023/03/08 15:28:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_lst_map	*ft_lstlast(t_lst_map *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

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
