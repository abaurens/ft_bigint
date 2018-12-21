/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:54:45 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/21 01:13:42 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"
#include "libft.h"

static void			swap(t_bint const **const n1, t_bint const **const n2)
{
	const t_bint	*lng;

	lng = bint_longer(*n1, *n2);
	*n2 = bint_shorter(*n1, *n2);
	*n1 = lng;
}

static void			mul_digit(const t_bint *r, t_bint const *n1,
								const t_digit d, size_t dc)
{
	size_t			i;
	size_t			l;

	i = 0;
	l = r->len - 1;
	while (i < n1->len)
	{
		r->num[l - i - dc] += n1->num[n1->len - 1 - i] * d;
		if (r->num[l - i - dc] > 9)
			r->num[l - i - dc - 1] += r->num[l - i - dc] / 10;
		r->num[l - i - dc] %= 10;
		i++;
	}
}

t_bint				*mul_bint(t_bint const *n1, t_bint const *n2)
{
	size_t			i;
	size_t			l2;
	t_bint			*res;

	i = 0;
	swap(&n1, &n2);
	if (!n1 || !n2 || !(res = (t_bint *)malloc(sizeof(t_bint))))
		return (NULL);
	l2 = n2->len;
	res->neg = 0;
	res->len = n1->len + l2;
	if (!(res->num = (t_digit *)ft_memalloc(sizeof(t_digit) * (res->len + 1))))
		return (abort_bint(res));
	while (i++ < l2)
		mul_digit(res, n1, n2->num[l2 - i], i - 1);
	if (!*res->num)
		ft_memmove(res->num, res->num + 1, --res->len);
	return (res);
}
