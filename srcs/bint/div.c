/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:25:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/21 22:20:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

static unsigned int	correct_error(unsigned int q, t_bint *n1, t_bint *n2)
{
	unsigned int	i;
	unsigned long	borrow;
	unsigned long	difference;

	i = 0;
	borrow = 0;
	if (bicmp(n1, n2) >= 0)
	{
		++q;
		while (!i || i < n2->len)
		{
			difference = (unsigned long)n1->blks[i];
			difference -= ((unsigned long)n2->blks[i] - borrow);
			borrow = (difference >> BIT_PER_BLOCK) & 1;
			n1->blks[i++] = (difference & MAX_BINT_VALS);
		}
		while (i > 0 && n1->blks[i - 1] == 0)
			--i;
		n1->len = i;
	}
	return (q);
}

static unsigned int	process_div(unsigned int q, t_bint *n1, t_bint *n2)
{
	unsigned int	i;
	unsigned long	carry;
	unsigned long	borrow;
	unsigned long	product;
	unsigned long	difference;

	if (q)
	{
		i = 0;
		carry = 0;
		borrow = 0;
		while(!i || i < n2->len)
		{
			product = (unsigned long)n2->blks[i] * (unsigned long)q + carry;
			carry = product >> 32;
			difference = n1->blks[i] - (product & MAX_BINT_VALS) - borrow;
			borrow = (difference >> BIT_PER_BLOCK) & 1;
			n1->blks[i++] = difference & MAX_BINT_VALS;
		}
		while (i > 0 && n1->blks[i - 1] == 0)
			--i;
		n1->len = i;
	}
	return (correct_error(q, n1, n2));
}

unsigned int		bidiv_maxq9(t_bint *n1, t_bint *n2)
{
	unsigned int	q;

	BIASSERT(!biiszero(n2) && n2->blks[n2->len - 1] >= 8
			&& n2->blks[n2->len - 1] < 0xFFFFFFFF
			&& n1->len <= n2->len, "invalid division");
	if (bicmp(n2, n1) > 0)
		return (0);
	q = n1->blks[n2->len - 1] / (n2->blks[n2->len - 1] + 1);
	BIASSERT(q <= 9, "quotient is higher than 9");
	return (process_div(q, n1, n2));
}
