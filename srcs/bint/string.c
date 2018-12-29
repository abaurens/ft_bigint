/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:05:11 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/29 18:12:51 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_bigint.h"
#include "libft.h"

/*
**	those functions multiply and add n1 and n2 and return
**	the result in a newly allocated string.
*/

void			swap_deci(const char **n1, const char **n2)
{
	const char	*lng;

	if (ft_strlen(*n2) <= ft_strlen(*n1))
		return ;
	lng = *n2;
	*n2 = *n1;
	*n1 = lng;
}

char			*mul_deci(const char *n1, const char *n2)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*res;

	swap_deci(&n1, &n2);
	i = ft_strlen(n2);
	len = ft_strlen(n1) + i;
	if (!(res = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while (i-- > 0 && (j = ft_strlen(n1)))
	{
		while (j-- > 0)
		{
			res[j + i + 1] += (n2[i] - '0') * (n1[j] - '0');
			res[j + i] += res[j + i + 1] / 10;
			res[j + i + 1] %= 10;
		}
	}
	if (!*res)
		ft_memmove(res, res + 1, len--);
	while (len-- > 0)
		res[len] += '0';
	return (res);
}

char			*add_deci(const char *n1, const char *n2)
{
	size_t		i;
	size_t		l1;
	size_t		l2;
	size_t		len;
	char		*res;

	i = 0;
	l1 = ft_strlen(n1);
	l2 = ft_strlen(n2);
	len = ft_max(l1, l2) + 1;
	if (!(res = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while (i++ < len)
	{
		res[len - i] += (i > l1 ? 0 : n1[l1 - i] - '0')
							+ (i > l2 ? 0 : n2[l2 - i] - '0');
		if (res[len - i] >= 10)
			res[len - i - 1] = res[len - i] / 10;
		res[len - i] = res[len - i] % 10 + '0';
	}
	if (*res == '0')
		ft_memmove(res, res + 1, len--);
	return (res);
}

char			*bint_tostr(t_bint const *const num)
{
	size_t		len;
	char		*tmp;
	char		*base;
	char		*deci;
	char		*digit;

	len = 0;
	deci = NULL;
	base = ft_ulltoa(DIGIT_MAX);
	while (len < num->len)
	{
		tmp = mul_deci(deci ? deci : "0", base);
		digit = ft_ulltoa(num->num[len++]);
		if (!tmp || !digit)
			return ((char *)ft_freturn(tmp, ft_freturn(base, 0x0)));
		deci = (char *)ft_freturn(tmp, (long)add_deci(tmp, digit));
		free(digit);
		if (!deci)
			return ((char *)ft_freturn(base, 0x0));
	}
	while (*deci == '0' && *(deci + 1))
		ft_memmove(deci, deci + 1, ft_strlen(deci));
	if (num->neg)
		deci = (char *)ft_freturn(deci, (long)ft_strmcat("-", deci, -1));
	return (deci);
}

void			print_bint(t_bint const *const num)
{
	size_t		i;
	char		*t;

	i = 0;
	if (!num || !(t = bint_tostr(num)))
		return ;
	write(1, t, ft_strlen(t));
	free(t);
	write(1, "\n", 1);
}
