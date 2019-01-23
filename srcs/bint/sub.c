/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:40:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/23 23:28:17 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

static void		pbin(unsigned long v)
{
	if (v > 1)
		pbin(v >> 1);
	printf("%c", (char)((v & 1) + '0'));
}

void		bisub(t_bint *res, t_bint *n1, t_bint *n2)
{
	size_t	i;
	t_bint	r;
	int		c;
	t_proc	c2;
	t_proc	dif;

	bi_set(&r, 0);
	BIASSERT((c = bicmp(n1, n2)) >= 0, "n1 is lower than n2");
	if (!c)
	{
		*res = r;
		return ;
	}
	r.len = 0;
	c = 0;
	while (r.len < n1->len)
	{
		dif = n1->blks[r.len];
		c2 = (r.len < n2->len ? n2->blks[r.len] : 0) + c;
		if ((c = (dif < c2)))
			dif |= (1ul << BIT_PER_BLOCK);
		r.blks[r.len] = (dif - c2);
		r.len++;
	}
	if (r.blks[r.len - 1] == 0)
		r.len--;
	*res = r;
}

void		bisubint(t_bint *res, t_bint *n1, unsigned int v)
{
	t_bint	n2;

	bi_set(&n2, v);
	bisub(res, n1, &n2);
}
