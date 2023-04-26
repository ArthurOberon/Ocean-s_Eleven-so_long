/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:24:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/04/26 15:30:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long unsigned int	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}	

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

static int	ft_nbrlen(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		return (1);
	return (1 + ft_nbrlen(nb / 10));
}

char	*ft_itoa(int n)
{
	unsigned int	tmp;
	size_t			size;
	char			*result;

	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	size = (ft_nbrlen(tmp) + (n < 0));
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	if (n == 0)
		result[0] = 0;
	while (tmp > 0)
	{
		result[size] = (tmp % 10) + '0';
		tmp /= 10;
		size--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

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
	result = malloc(sizeof(char) * (size + 1));
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
