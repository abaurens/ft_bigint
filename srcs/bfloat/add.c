/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:17:12 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 19:53:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigfloat.h"
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

static t_bflt	*add_dec(t_bflt const *const n1, t_bflt const *const n2,
							t_bflt *r)
{
	size_t		i;
	t_digit		d1;
	t_digit		d2;
	t_digit		cary;

	i = 0;
	r->decl = ft_max(n1->decl, n2->decl);
	if (!(r->dec = (t_digit *)ft_memalloc(sizeof(t_digit) * r->decl)))
		return (abort_bflt(r, 1));
	cary = 0;
	while (i < r->decl)
	{
		d1 = ((r->decl - 1) - i) < n1->decl ? n1->dec[(r->decl - 1) - i] : 0;
		d2 = ((r->decl - 1) - i) < n2->decl ? n2->dec[(r->decl - 1) - i] : 0;
		r->dec[r->decl - 1 - i] = cary + d1 + d2;
		cary = r->dec[r->decl - 1 - i] / 10;
		r->dec[r->decl - 1 - i] %= 10;
		i++;
	}
	r->ent[r->entl] = cary;
	return (r);
}

static t_bflt	*add_ent(t_bflt const *const n1, t_bflt const *const n2,
							t_bflt *r)
{
	size_t		i;
	size_t		l1;
	size_t		l2;
	t_digit		c1;
	t_digit		c2;

	i = 0;
	l1 = n1->entl - 1;
	l2 = n2->entl - 1;
	while (i < r->entl)
	{
		c1 = (l1 < i ? 0 : n1->ent[l1 - i]);
		c2 = (l2 < i ? 0 : n2->ent[l2 - i]);
		r->ent[r->entl - i] += c1 + c2;
		if (r->ent[r->entl - i] > 9)
			r->ent[r->entl - (i + 1)] = r->ent[r->entl - i] / 10;
		r->ent[r->entl - i] %= 10;
		i++;
	}
	if (!*r->ent || !(++r->entl))
		ft_memmove(r->ent, r->ent + 1, r->entl);
	r->len = r->entl + r->decl + 1;
	return (r);
}

t_bflt			*add_bflt(t_bflt const *const n1, t_bflt const *const n2)
{
	t_bflt		*res;

	if (!n1 || !n2 || !(res = malloc(sizeof(t_bflt))))
		return (NULL);
	res->neg = 0;
	res->entl = ft_max(n1->entl, n2->entl);
	if (!(res->ent = (t_digit *)ft_memalloc(sizeof(t_digit) * (res->entl + 1))))
		return (abort_bflt(res, 0));
	if (!add_dec(n1, n2, res))
		return (NULL);
	return (add_ent(n1, n2, res));
}
