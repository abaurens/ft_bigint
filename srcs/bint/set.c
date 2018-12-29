/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 02:25:58 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/29 18:09:04 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_bigint.h"
#include "libft.h"

/*
**	gives the modulus of the ascii formated number
**	given as argument by DIGIT_MAX. (only used for parsing)
**	This function does not modify the arument string
*/

static t_digit		modulus(const char *v)
{
	unsigned long	d;
	char			first;

	d = 0;
	first = 1;
	while (*v)
	{
		d = (d * 10 + (*v++ - '0'));
		while (first && *v && d < DIGIT_MAX)
			d = (d * 10 + (*v++ - '0'));
		d = d % DIGIT_MAX;
		if (first)
			first = 0;
	}
	return (d);
}

/*
**	This function stores the division of the ascii formated number
**	given as argument by DIGIT_MAX in the same argument argument (like '/=' op).
**	This means v has to be allocated and that it WILL be changed.
**	This function also gives the modulus as return value.
*/

static t_digit		div_prs(char *v)
{
	size_t			i;
	unsigned long	d;
	char			*nb;
	char			first;

	i = 0;
	d = 0;
	nb = v;
	first = 1;
	while (v && *v)
	{
		d = (d * 10 + (*v++ - '0'));
		while (first && *v && d < DIGIT_MAX)
			d = (d * 10 + (*v++ - '0'));
		nb[i++] = (d / DIGIT_MAX) + '0';
		d %= DIGIT_MAX;
		if (first)
			first = 0;
	}
	if (v && !*v)
		nb[i] = 0;
	return (d);
}

static t_bint		*div_parser(t_bint *num, const char *value)
{
	size_t			l;
	char			*wrk;

	l = 0;
	if (!value || !(wrk = ft_strdup(value)))
		return (NULL);
	while (wrk && *wrk && *wrk != '0' && ++l)
		div_prs(wrk);
	l += (l ? 0 : 1);
	if (!(num->num = (t_digit *)ft_memalloc(sizeof(t_digit) * l)))
		return ((t_bint *)ft_freturn(wrk, 0x0));
	num->len = l;
	ft_strcpy(wrk, value);
	while (l > 0)
	{
		num->num[--l] = modulus(wrk);
		div_prs(wrk);
	}
	free(wrk);
	return (num);
}

t_bint				*set_bint(t_bint *num, const char *value)
{
	size_t			i;

	i = 0;
	num->len = 0;
	num->neg = 0;
	while (value && (*value == '+' || *value == '-') && ++value)
		if (*(value - 1) == '-')
			num->neg = !num->neg;
	while (value && *value == '0' && *(value + 1))
		value++;
	if (!div_parser(num, value))
		return (NULL);
	while (!*num->num && num->len > 1)
		ft_memmove(num->num, num->num + 1, num->len--);
	i = 0;
	return (num);
}
