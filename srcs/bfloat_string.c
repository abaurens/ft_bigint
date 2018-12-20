/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfloat_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 07:28:35 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 07:39:54 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_bigfloat.h"

char		*bfloat_tostr(t_bfloat const *const num)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!(res = malloc(num->len + 1)))
		return (NULL);
	res[num->len] = 0;
	while (i < num->len)
	{
		if (i < num->entl)
			res[i] = num->ent[i] + '0';
		else if (i > num->entl)
			res[i] = num->dec[i - num->entl - 1] + '0';
		else
			res[i] = '.';
		i++;
	}
	return (res);
}

void		print_bfloat(t_bfloat const *const num)
{
	size_t	i;
	t_digit	c;

	i = 0;
	while (i < num->entl)
	{
		c = num->ent[i++] + '0';
		write(1, &c, 1);
	}
	write(1, ".", 1);
	i = 0;
	while (i < num->decl)
	{
		c = num->dec[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}
