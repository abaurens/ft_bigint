/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:25:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/28 20:29:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		bidiv(t_bint *res, t_bint *mod, t_bint *n1, t_bint *n2)
{
	t_bint	r;
	t_bint	m;

	m = *n1;
	bi_set(&r, 0);
	if (bicmp(n1, n2) < 0)
	{
		*res = r;
		*mod = m;
		return ;
	}
	while (bicmp(&m, n2) >= 0)
	{
		bisub(&m, &m, n2);
		biincrement(&r);
	}
	*mod = m;
	*res = r;
}

unsigned int	bidiv_maxq92(t_bint *n1, t_bint *n2)
{
	unsigned int	r;
	t_bint			m;
	long			c;

	r = 5;
	if (bicmp(n1, n2) < 0)
		return (0);
	bimulint(&m, n2, r);
	while (bicmp(&m, n1) < 0 && r++)
		biadd(&m, &m, n2);
	while (bicmp(&m, n1) > 0 && r--)
		bisub(&m, &m, n2);
	bisub(n1, n1, &m);
	return (r);
}

unsigned int	bidiv_maxq93(t_bint *n1, t_bint *n2)
{
	unsigned int	r;
	t_bint			m;
	long			c;

	r = 5;
	if (bicmp(n1, n2) < 0)
		return (0);
	bimulint(&m, n2, r);
	if (bicmp(&m, n1) < 0)
		bisub(n1, n1, &m);
	m = *n2;
	while (bicmp(&m, n1) < 0 && r++)
		biadd(&m, &m, n2);
	while (bicmp(&m, n1) > 0 && r--)
		bisub(&m, &m, n2);
	bisub(n1, n1, &m);
	return (r);
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
