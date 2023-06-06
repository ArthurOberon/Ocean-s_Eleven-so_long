/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:24:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/06/06 11:39:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Returns the length of a string.
 * 
 * @param s string to calculate length.
 * @return size_t length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

/**
 * @brief Checks if two strings are equal.
 * 
 * @param s1 string 1.
 * @param s2 string 2.
 * @return int 1 if equal, 0 if not.
 */
int	is_equals(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Returns the length of an integer.
 * 
 * @param nb number to calculate length.
 * @return int length of the number.
 */
int	ft_nbrlen(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		return (1);
	return (1 + ft_nbrlen(nb / 10));
}

/**
 * @brief Converts an integer to a string without malloc.
 * 
 * @param n integer to convert.
 * @param result string to store the result.
 */
void	ft_itoa(int n, char result[10])
{
	unsigned int	tmp;
	size_t			size;

	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	size = (ft_nbrlen(tmp) + (n < 0));
	ft_bzero(result, 10);
	result[size--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (tmp > 0)
	{
		result[size] = (tmp % 10) + '0';
		tmp /= 10;
		size--;
	}
	if (n < 0)
		result[0] = '-';
}

/**
 * @brief Joins two strings into a new one.
 * 
 * @param s1 first string.
 * @param s2 second string.
 * @return char* new string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	s1_size;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	s1_size = ft_strlen(s1);
	size = s1_size + ft_strlen(s2);
	result = ft_calloc(sizeof(char), size + 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		if (i < s1_size)
			result[i] = s1[i];
		else
			result[i] = s2[j++];
		i++;
	}
	result[i] = '\0';
	return (result);
}
