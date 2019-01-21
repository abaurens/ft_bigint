/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 02:48:52 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/21 18:09:47 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "bint/bint.h"

/*
**	Create and return a new bigint.
**	If n is not null, the returned bigint is a copy of n.
*/

t_bint		bi_init(t_bint *n)
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
		n->blks[i++] = val & 0xFFFFFFFF;
		val >>= BIT_PER_BLOCK;
	}
}

char	biiszero(t_bint *n)
{
	return (!n || !n->len || (n->len == 1 && !n->blks[0]));
}
