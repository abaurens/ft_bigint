/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bint_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:16:18 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/21 16:55:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

long	bicmp(const t_bint *lhs, const t_bint *rhs)
{
	long	i;

	if (!lhs || !rhs)
		return (0);
	if ((i = lhs->len - rhs->len) != 0)
		return (i);
	i = lhs->len;
	while (i-- > 0)
	{
		if (lhs->blks[i] != rhs->blks[i])
			return (lhs->blks[i] > rhs->blks[i] ? 1 : -1);
	}
	return (0);
}

long	bicmplng(const t_bint *lhs, unsigned long v)
{
	t_bint	rhs;

	if (!lhs && !v)
		return (0);
	if (lhs->len == 1 && v < MAX_BINT_VALS && lhs->blks[0] != v)
		return (lhs->blks[0] > v ? 1 : -1);
	bi_set(&rhs, v);
	return (bicmp(lhs, &rhs));
}
