/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:42:59 by aoberon           #+#    #+#             */
/*   Updated: 2022/11/16 18:44:48 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putstr_int(char	*s)
{
	if (!s)
		return (ft_putstr("(null)"), ft_strlen("(null)"));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
