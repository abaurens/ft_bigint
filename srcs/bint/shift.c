/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:58:39 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/21 21:26:17 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		shift_block(t_bint	*res, unsigned int shift, unsigned int idx)
{
	int		i;
	t_proc	t;
	t_proc	c;

	c = 0;
	i = -1;
	while ((size_t)(++i) < res->len)
	{
		if (!res->blks[i])
			continue;
		t = (((t_proc)res->blks[i]) << shift) | c;
		c = (t >> BIT_PER_BLOCK);
		res->blks[i] = (t & MAX_BINT_VALS);
	}
	if (c && res->len++)
		res->blks[idx + 1] = c;
}

void		bi_shift_left(t_bint *res, unsigned int shift)
{
	t_bint			r;
	unsigned int	i;
	unsigned int	md;
	unsigned int	len;

	len = shift / BIT_PER_BLOCK;
	md = shift % BIT_PER_BLOCK;
	r = bi_init(res);
	if (len)
	{
		i = res->len + len;
		while (i-- > 0)
			r.blks[i] = i >= len ? r.blks[i - len] : 0;
		r.len += len;
	}
	if (md != 0)
		shift_block(&r, shift % BIT_PER_BLOCK, r.len - 1);
	*res = r;
}
