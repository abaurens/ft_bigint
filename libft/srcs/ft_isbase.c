/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:20:29 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/14 12:52:56 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		ft_isbase(const char *base)
{
	int		i;
	size_t	l;

	l = 0;
	while (*base)
	{
		i = 1;
		while (base[i] && *base != base[i])
			i++;
		if (base[i] != 0)
			return (0);
		base++;
		l++;
	}
	return (l >= 2);
}
