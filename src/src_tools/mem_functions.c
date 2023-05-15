/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:19:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/05/15 18:44:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((size_t)-1 / nmemb < size)
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, (nmemb * size));
	return (result);
}

char	*ft_strdup(const char *s)
{
	int		length;
	char	*result;

	length = ft_strlen(s);
	result = ft_calloc(sizeof(char), (length + 1));
	if (result == NULL)
		return (NULL);
	length = 0;
	while (s[length])
	{
		result[length] = s[length];
		length++;
	}
	result[length] = '\0';
	return (result);
}

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	size_t	i;
// 	size_t	size;

// 	size = sizeof(size_t);
// 	i = 0;
// 	if (n > size)
// 	{
// 		while (i < n - size)
// 		{
// 			*(size_t *)(dest + i) = *(size_t *)(src + i);
// 			i += size;
// 		}
// 	}
// 	while (i != n)
// 	{
// 		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
// 		i++;
// 	}
// 	return (dest);
// }

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	offset;

	i = 0;
	offset = sizeof(size_t);
	while (i + offset < n)
	{
		*(size_t *)(dest + i) = *(size_t *)(src + i);
		i += offset;
	}
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

void	ft_memset(void *addr, int value, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned int *)(addr + i) = value;
		++i;
	}
}
