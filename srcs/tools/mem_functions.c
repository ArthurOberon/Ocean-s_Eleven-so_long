/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:19:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/07/17 23:30:05 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Set a block of memory to 0.
 * 
 * @param s block of memory to set.
 * @param n size of the block to set.
 */
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

/**
 * @brief Allocates memory and sets it to 0.
 * 
 * @param nmemb size of the type to allocate.
 * @param size size to allocate.
 * @return void* allocated memory.
 */
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

/**
 * @brief Create a duplicate of a string.
 * 
 * @param s string to duplicate.
 * @return char* string duplicate.
 */
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

/**
 * @brief Copies a block of memory.
 * 
 * @param dest destination of the copy.
 * @param src src to copy.
 * @param n size of the block to copy.
 * @return void* 
 */
void	ft_memcpy(void *dest, const void *src, size_t n)
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
}

/**
 * @brief Set a block of memory to a value.
 * 
 * @param addr address of the block of memory to set.
 * @param value value to set.
 * @param n size of the block to set.
 */
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
