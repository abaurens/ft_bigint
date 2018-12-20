/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:29:23 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 07:46:04 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"

#include <stdio.h>

static t_bfloat	*insert_decimal(t_bfloat *num, const char *value)
{
	size_t		i;

	i = 0;
	num->decl = 0;
	while (value && value[num->decl] >= '0' && value[num->decl] <= '9')
		++num->decl;
	while (value && num->decl > 0 && value[num->decl - 1] == '0')
		--num->decl;
	if (!num->decl)
		num->decl = 1;
	if (!(num->dec = (t_digit *)malloc(sizeof(t_digit) * num->decl)))
		return (abort_bfloat(num, 1));
	num->dec[0] = 0;
	while (value && *value >= '0' && *value <= '9' && i < num->decl)
		num->dec[i++] = *value++ - '0';
	num->len = num->entl + num->decl + 1;
	return (num);
}

t_bfloat	*set_bfloat(t_bfloat *num, const char *value)
{
	size_t	i;

	i = 0;
	num->entl = 0;
	num->neg = 0;
	while (value && (*value == '+' || *value == '-') && ++value)
		if (*(value - 1) == '-')
			num->neg = !num->neg;
	while (value && *value == '0')
		value++;
	while (value && value[num->entl] >= '0' && value[num->entl] <= '9')
		num->entl++;
	if (!num->entl)
		num->entl = 1;
	if (!(num->ent = (t_digit *)malloc(sizeof(t_digit) * num->entl)))
		return (abort_bfloat(num, 0));
	num->ent[0] = 0;
	while (value && *value >= '0' && *value <= '9')
		num->ent[i++] = *value++ - '0';
	return (insert_decimal(num, value + (value && *value == '.')));
}
