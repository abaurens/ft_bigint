/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:40:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/28 18:40:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		bisub(t_bint *res, t_bint *n1, t_bint *n2)
{
	int		c;
	t_bint	r;
	t_proc	c2;
	t_proc	dif;

	bi_set(&r, 0);
	BIASSERT((c = bicmp(n1, n2)) >= 0, "n1 is lower than n2");
	if (!c)
	{
		*res = r;
		return ;
	}
	c = 0;
	r.len = 0;
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
