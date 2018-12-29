/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:18:11 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/29 21:47:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"
#include "libft.h"

#include <stdio.h>

static void		swap_deci(const char **n1, const char **n2)
{
	const char	*lng;

	if (ft_strlen(*n2) <= ft_strlen(*n1))
		return ;
	lng = *n2;
	*n2 = *n1;
	*n1 = lng;
}

static char		*dup_dot(const char *n)
{
	size_t		i;
	size_t		d;
	char		*res;

	i = ft_strlen(n);
	if ((d = ft_idxof('.', n)) != i)
		i--;
	if (!(res = ft_strmcat(n, NULL, d)))
		return (NULL);
	if (!(res = (char *)ft_freturn(res, (long)ft_strmcat(res, n + d + 1, i))))
		return (NULL);
	/*ft_putendl(res);*/
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

t_bflt		*set_bflt_base(t_bflt *num, const char *value)
{
	size_t	i;
	size_t	dot;
	char	*wrk;
	char	*base;

	dot = 0;
	if ((wrk = ft_strchr(value, '.')))
		dot = ft_strlen(++wrk);
	i = 0;
	base = ft_ulltoa(DIGIT_MAX);
	if (!base || !(wrk = ft_strdup(value)))
		return (NULL);
	while (wrk && i < dot)
	{
		printf("%s * %s = ", wrk, base);
		wrk = (char *)ft_freturn(wrk, (long)mul_deci_dot(wrk, base));
		printf("%s\n", wrk);
		i++;
	}
	free(base);
	free(wrk);
	return (num);
}
