/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:40:44 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/22 20:57:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		bisub(t_bint *res, t_bint *n1, t_bint *n2)
{
	t_bint	r;
	long	c;
	size_t	i;
	t_proc	ca;
	t_proc	dif;

	bi_set(&r, 0);
	BIASSERT((c = bicmp(n1, n2)) >= 0, "n1 is lower than n2");
	if (!c)
	{
		*res = r;
		return ;
	}
	i = 0;
	ca = 0;
	while (i < n1->len)
	{
		dif = n1->blks[i];
		if (dif < ((i < n2->len ? n2->blks[i] : 0) + ca))
		{
			dif *= 10;
			ca = 1;
		}
		else
			ca = 0;
		dif -= n2->blks[i];
		r.blks[i] = dif;
		i++;
	}
	r.len = i;
	*res = r;
}

void		bisubint(t_bint *res, t_bint *n1, unsigned int v)
{
	t_bint	n2;

	bi_set(&n2, v);
	bisub(res, n1, &n2);
}
