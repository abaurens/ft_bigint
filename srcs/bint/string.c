/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:05:11 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 20:41:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_bigint.h"

char		*bint_tostr(t_bint const *const num)
{
	size_t	i;
	char	*res;

	if (!num || !num->num || !num->len)
		return (NULL);
	if (!(res = (char *)malloc(num->len + num->neg + 1)))
		return (NULL);
	if ((i = num->neg))
		res[0] = '-';
	res[num->len + i] = 0;
	while (i < num->len)
	{
		res[i] = num->num[i - num->neg] + '0';
		i++;
	}
	return (res);
}

void		print_bint(t_bint const *const num)
{
	size_t	i;
	t_digit	c;

	i = 0;
	if (!num)
		return ;
	if (num->neg)
		write(1, "-", 1);
	while (i < num->len)
	{
		c = num->num[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}
