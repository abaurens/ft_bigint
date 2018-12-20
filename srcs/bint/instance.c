/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:04:26 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 20:40:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"

t_bint		*new_bint(const char *value)
{
	size_t	i;
	t_bint	*res;

	i = 0;
	if (!(res = (t_bint *)malloc(sizeof(t_bint))))
		return (NULL);
	res->len = 0;
	res->neg = 0;
	while (value && (*value == '+' || *value == '-') && ++value)
		if (*(value - 1) == '-')
			res->neg = !res->neg;
	while (value && *value == '0')
		value++;
	while (value && value[res->len] >= '0' && value[res->len] <= '9')
		res->len++;
	if (!res->len)
		res->len = 1;
	if (!(res->num = (t_digit *)malloc(sizeof(t_digit) * res->len)))
		return (abort_bint(res));
	res->num[0] = 0;
	while (value && *value >= '0' && *value <= '9')
		res->num[i++] = *value++ - '0';
	return (res);
}

t_bint		*copy_bint(t_bint const *const num)
{
	size_t	i;
	t_bint	*res;

	i = 0;
	if (!(res = malloc(sizeof(t_bint))))
		return (NULL);
	res->len = num->len;
	res->neg = num->neg;
	if (!(res->num = (t_digit *)malloc(sizeof(t_digit) * res->len)))
		return (abort_bint(res));
	while (i < res->len)
	{
		res->num[i] = num->num[i];
		i++;
	}
	return (res);
}

t_bint		*set_bint(t_bint *num, const char *value)
{
	num->len = 0;
	num->neg = 0;
	while (value && (*value == '+' || *value == '-') && ++value)
		if (*(value - 1) == '-')
			num->neg = !num->neg;
	while (value && *value == '0')
		value++;
	while (value && value[num->len])
		num->len++;
	if (!num->len)
		num->len = 1;
	if (!(num->num = (t_digit *)malloc(sizeof(t_digit) * num->len)))
		return (NULL);
	num->len = 0;
	num->num[0] = 0;
	while (value && *value)
		num->num[num->len++] = *value++ - '0';
	return (num);
}

void		unset_bint(t_bint *const num)
{
	if (!num)
		return ;
	free(num->num);
	num->len = 0;
}

void		del_bint(t_bint const *const num)
{
	if (num)
		free(num->num);
	free((void *)num);
}
