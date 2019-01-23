/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:25:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/23 21:12:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		bidiv(t_bint *res, t_bint *mod, t_bint *n1, t_bint *n2)
{
	t_bint	r;
	t_bint	m;
	int		i;

	m = *n1;
	bi_set(&r, 0);
	if (bicmp(n1, n2) < 0)
	{
		*res = r;
		*mod = m;
		return ;
	}
	i = 0;
	/*printf("n2 = "); bi_print_dec(n2); printf("\n");*/
	while (i < 10 && bicmp(&m, n2) >= 0)
	{
		printf("  "); bi_print_dec(&m); printf("\n");/* the substraction seems wrong...*/
		printf("- "); bi_print_dec(n2); printf("\n");
		bisub(&m, &m, n2);
		printf("= "); bi_print_dec(&m); printf("\n\n");
		biincrement(&r);
		i++;
	}
	if (i == 10)
		exit(0);
	printf("\n");
	*mod = m;
	*res = r;
}
/*
unsigned int		bidiv_fast(t_bint *remainer, const t_bint *dividend, const t_bint *divisor)
{
	unsigned int	quotient;
	t_bint  		divid;
	t_bint			divis;
	t_bint			prev;

	quotient = 1;
	divid = *dividend;
	divis = *divisor;
	if (bicmp(&divid, &divis) == 0)
	{
		bi_set(remainer, 0);
		return (1);
	}
	else if (bicmp(&divid, &divis) < 0)
	{
		*remainer = divid;
		return (0);
	}
	prev = divis;
	while (bicmp(&divid, &divis) > 0)
	{
		prev = divis;
		bi_shift_left(&divis, 1);
		quotient <<= 1;
	}
	if (bicmp(&divid, &divis) < 0)
	{
		divis = prev;
		quotient >>= 1;
	}
	bisub(&divid, &divid, &divis);
	return (quotient + bidiv_fast(remainer, &divid, divisor));
}
*/
unsigned int		bidiv_fast(t_bint *remainer, const t_bint *dividend, const t_bint *divisor)
{
	unsigned int	quotient;
	unsigned int	q;
	t_bint  		divid;
	t_bint			divis;
	t_bint			prev;

	quotient = 0;
	divid = *dividend;
	while (1)
	{
		q = 1;
		divis = *divisor;
		if (bicmp(&divid, &divis) == 0)
		{
			bi_set(remainer, 0);
			return (quotient + 1);
		}
		else if (bicmp(&divid, &divis) < 0)
		{
			*remainer = divid;
			return (quotient);
		}
		prev = divis;
		while (bicmp(&divid, &divis) > 0)
		{
			prev = divis;
			bi_shift_left(&divis, 1);
			q <<= 1;
		}
		if (bicmp(&divid, &divis) < 0)
		{
			divis = prev;
			q >>= 1;
		}
		bisub(&divid, &divid, &divis);
		quotient += q;
	}
	return (quotient);
}

unsigned int	bidiv_maxq9(t_bint *n1, t_bint *n2)
{
	t_bint		t;


	bidiv(&t, n1, n1, n2);
	BIASSERT(t.len = 1 && t.blks[0] <= 9, "digit is over the base limit");
	return (t.blks[0]);
}

unsigned int	bidiv10(t_bint *res, t_bint *n1)
{
	size_t		i;
	t_proc		c;
	t_bint		r;

	c = 0;
	r.len = 0;
	if (bicmplng(n1, 10) < 0 && ((c = n1->blks[0]) || 1))
	{
		bi_set(res, 0);
		return (c);
	}
	i = n1->len;
	while (i-- > 0)
	{
		c = ((c << BIT_PER_BLOCK) | n1->blks[i]);
		if ((r.blks[i] = (c / 10)) || r.len)
			r.len++;
		c %= 10;
	}
	if (r.len == 0)
		r.len = 1;
	*res = r;
	return (c);
}
