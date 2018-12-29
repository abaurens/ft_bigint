/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:54:31 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/21 14:53:13 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_bigfloat.h"
#include "libft.h"

static void			swap(t_bflt const **const n1, t_bflt const **const n2)
{
	const t_bflt	*lng;

	if (!n1 || !*n1 || !n2 || !*n2 || (*n1)->len > (*n2)->len)
		return ;
	lng = *n2;
	*n2 = *n1;
	*n1 = lng;
}

static t_digit		get_digit(t_bflt const *const n, size_t idx)
{
	if (idx < n->entl)
		return (n->ent[idx]);
	return (n->dec[idx - n->entl]);
}

static void			mul_digit(const t_bflt *r, t_bflt const *n1,
								const t_digit d, size_t dc)
{
	size_t			i;
	size_t			l;
	size_t			l1;
	t_digit			*num;
	t_digit			*prev;

	i = 0;
	l1 = n1->len - 1;
	while (i++ < l1)
	{
		num = (((r->entl + r->decl) - i - dc) < r->entl) ? r->ent : r->dec;
		l = ((r->entl + r->decl) - i - dc) - ((num == r->dec) ? r->entl : 0);
		prev = (num == r->dec && l == 0) ? &r->ent[r->entl - 1] : &num[l - 1];
		if ((num[l] += (get_digit(n1, l1 - i) * d)) > 9)
			*prev += num[l] / 10;
		num[l] %= 10;
	}
}

t_bflt				*mul_bflt(t_bflt const *n1, t_bflt const *n2)
{
	size_t			i;
	size_t			l;
	t_bflt			*res;

	i = 0;
	swap(&n1, &n2);
	if (!n1 || !n2 || !(res = (t_bflt *)malloc(sizeof(t_bflt))))
		return (NULL);
	res->neg = 0;
	res->entl = n1->entl + n2->entl;
	res->decl = n1->decl + n2->decl;
	if (!(res->ent = (t_digit *)ft_memalloc(sizeof(t_digit) * (res->entl + 1))))
		return (abort_bflt(res, 0));
	if (!(res->dec = (t_digit *)ft_memalloc(sizeof(t_digit) * res->decl)))
		return (abort_bflt(res, 1));
	l = n2->len - 1;
	while (i++ < l)
		mul_digit(res, n1, get_digit(n2, l - i), i - 1);
	if (!*res->ent)
		ft_memmove(res->ent, res->ent + 1, res->entl--);
	while ((res->decl > 0 || (res->dec = (t_digit *)ft_freturn(res->dec, 0x0)))
			&& !res->dec[res->decl - 1])
		--res->decl;
	res->len = res->decl + res->entl + 1;
	return (res);
}
