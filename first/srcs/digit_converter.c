/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 16:31:16 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 16:43:08 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "digits.h"
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

char			*digits_tostr(t_digit *dgts, size_t lens)
{
	size_t		l;
	char		*tmp;
	char		*ent;
	char		*base;
	char		*digit;

	l = 0;
	ent = NULL;
	base = ft_ulltoa(DIGIT_MAX);
	while (l < lens)
	{
		tmp = mul_deci(ent ? ent : "0", base);
		digit = ft_ulltoa(dgts[l++]);
		if (!tmp || !digit)
			return ((char *)ft_freturn(tmp, ft_freturn(base, 0x0)));
		ent = (char *)ft_freturn(tmp, (long)add_deci(tmp, digit));
		free(digit);
		if (!ent)
			return ((char *)ft_freturn(base, 0x0));
	}
	return (ent);
}
