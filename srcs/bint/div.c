/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:25:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/22 20:57:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		bidiv(t_bint *res, t_bint *mod, t_bint *n1, t_bint *n2)
{
	t_bint	r;
	t_bint	m;

	bi_set(&r, 0);
	m = bi_init(n1);
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

unsigned int		bidiv_maxq9(t_bint *n1, t_bint *n2)
{
	t_bint			t;
	unsigned int	r;


	bidiv(&t, n1, n1, n2);
	BIASSERT(t.len = 1 && t.blks[0] <= 9, "digit is over the base limit");
	return (t.blks[0]);
}

int		bidiv10(t_bint *res, t_bint *n1)
{
	t_bint	r;
	t_bint	m;

	bi_set(&r, 0);
	m = bi_init(n1);
	if (bicmplng(n1, 10) < 0)
	{
		*res = r;
		return (m.blks[0]);
	}

	while (bicmplng(&m, 10) >= 0)
	{
		bisubint(&m, &m, 10);
		biincrement(&r);
	}
	*res = r;
	return (m.blks[0]);
}
