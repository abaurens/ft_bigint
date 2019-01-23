/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 02:48:52 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/23 05:26:53 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bint/bint.h"

/*
**	Create and return a new bigint.
**	If n is not null, the returned bigint is a copy of n.
*/

t_bint		bi_init(t_bint const *const n)
{
	t_bint	t;

	t.len = 1;
	t.blks[0] = 0;
	if (n)
		t = *n;
	return (t);
}

void		bi_set(t_bint *n, unsigned long val)
{
	int		i;

	i = 0;
	n->len = 0;
	n->blks[0] = 0;
	while (val != 0)
	{
		n->len++;
		n->blks[i++] = val & MAX_BINT_VALS;
		val >>= BIT_PER_BLOCK;
	}
	if (!n->len)
		n->len++;
}

char	biiszero(t_bint const *const n)
{
	return (!n || !n->len || (n->len == 1 && !n->blks[0]));
}
