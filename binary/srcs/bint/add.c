/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:51:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/20 20:02:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bint/bint.h"

void		biadd(t_bint *res, t_bint *n1, t_bint *n2)
{
	t_bint	r;
	t_proc	tmp;

	if (!res)
		return ;
	if (!n1 || !n2)
		return ;
	if (n1->len < n2->len)
		swap((uintptr_t *)&n1, (uintptr_t *)&n2);
	r.len = 0;
	r.blks[0] = 0;
	while (r.len < n1->len)
	{
		tmp = (t_proc)r.blks[r.len] + (t_proc)n1->blks[r.len];
		tmp += ((r.len < n2->len) ? n2->blks[r.len] : 0);
		if (r.len + 1 < MAX_BINT_BLKS)
			r.blks[r.len + 1] = tmp >> BIT_PER_BLOCK;
		r.blks[r.len++] = tmp & MAX_BINT_VALS;
	}
	if (r.len < MAX_BINT_BLKS && r.blks[r.len] != 0)
		++r.len;
	*res = r;
}
