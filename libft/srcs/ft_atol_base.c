/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:25:22 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/13 14:17:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long					ft_atol_base(const char *str, const char *base)
{
	unsigned long long	val;
	char				sign;
	int					blen;

	val = 0;
	sign = 1;
	if (!ft_isbase(base))
		return (0);
	blen = ft_strlen(base);
	while (*str && ft_contains(*str, "\t\n\r\v\f "))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str && ft_contains(*str, base))
	{
		val = val * blen + ft_idxof(*str, base);
		if (val >= FT_LLMAX && sign == 1)
			return (-1);
		if (val >= FT_LLMAX + 1 && sign == -1)
			return (0);
		str++;
	}
	return (sign * (long)val);
}
