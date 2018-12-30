/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:18:11 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 20:14:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"
#include "ft_bigint.h"
#include "digits.h"
#include "libft.h"
#include "bnum.h"

#include <stdio.h>

static char		*dup_dot(const char *n)
{
	size_t		i;
	size_t		d;
	char		dot;
	char		*res;

	i = ft_strlen(n);
	d = ft_idxof('.', n);
	if ((dot = (d != i)))
		i--;
	if (!(res = ft_strmcat(n, NULL, d)))
		return (NULL);
	if (!(res = (char *)ft_freturn(res, (long)ft_strmcat(res, n + d + dot, i))))
		return (NULL);
	return (res);
}

static char		*mul_deci_d(const char *n1, const char *n2, size_t ln)
{
	size_t		i;
	size_t		j;
	size_t		l1;
	char		*res;

	i = ft_strlen(n2);
	l1 = ft_strlen(n1);
	if (!(res = (char *)ft_memalloc(ln + 1)))
		return (NULL);
	ln = l1 + i;
	while (i-- > 0 && (j = l1))
	{
		while (j-- > 0)
		{
			res[j + i + 1] += (n2[i] - '0') * (n1[j] - '0');
			res[j + i] += res[j + i + 1] / 10;
			res[j + i + 1] %= 10;
		}
	}
	return (res);
}

static char		*mul_deci_dot(const char *n1, const char *n2)
{
	char		*res;
	char		*t1;
	char		*t2;
	size_t		ld;
	size_t		len;

	swap_deci(&n1, &n2);
	t1 = dup_dot(n1);
	if (!t1 || !(t2 = dup_dot(n2)))
		return (NULL);
	len = ft_strlen(t1) + ft_strlen(t2);
	if (ft_strchr(n1, '.') || ft_strchr(n2, '.'))
		++len;
	if (!(res = mul_deci_d(t1, t2, len)))
		return (NULL);
	len = ft_strlen(t1) + ft_strlen(t2);
	while ((ld = len) > 1 && !*res)
		ft_memmove(res, res + 1, len--);
	while (ld-- > 0)
		res[ld] += '0';
	ld = ft_strlen(n1) - (ft_strchr(n1, '.') != NULL) - ft_idxof('.', n1);
	ld += ft_strlen(n2) - (ft_strchr(n2, '.') != NULL) - ft_idxof('.', n2);
	ft_memmove(res + len - ld + 1, res + len - ld, ld + !!ld);
	res[len - ld] = res[len - ld] ? '.' : 0;
	return (res);
}

static t_bflt	*in_bflt_dot(t_bflt *dst, t_bint *num, size_t dt)
{
	dst->decl = num->len - dt;
	dst->len = dst->entl + dst->decl + 1;
	if (!(dst->dec = malloc(sizeof(t_digit) * dst->decl)))
		return ((t_bflt *)ft_freturn(dst, 0x0));
	ft_memcpy(dst->dec, num->num + dt, sizeof(t_digit) * dst->decl);
	return (dst);
}

t_bflt			*set_bflt_base(t_bflt *num, const char *value)
{
	size_t		i;
	size_t		dot;
	t_bint		tmp;
	char		*wrk;
	char		*base;

	dot = 0;
	value = !value ? "0" : value;
	if ((wrk = ft_strchr(value, '.')))
		dot = ft_strlen(++wrk);
	i = 0;
	base = ft_ulltoa(DIGIT_MAX);
	if (!base || !(wrk = ft_strdup(value)))
		return (NULL);
	while (wrk && i++ < dot)
		wrk = (char *)ft_freturn(wrk, (long)mul_deci_dot(wrk, base));
	wrk = (char *)ft_freturn(wrk, (long)ft_strmcat(wrk, 0, ft_idxof('.', wrk)));
	free(base);
	set_bint(&tmp, wrk);
	free(wrk);
	tmp.len -= dot;
	in_bflt(num, &tmp);
	in_bflt_dot(num, &tmp, (tmp.len += dot) - dot);
	unset_bint(&tmp);
	return (num);
}
