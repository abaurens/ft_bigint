/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:55:04 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 19:40:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"
#include "libft.h"

/*
**	add a bint to another and give the result in a newly allocated one.
**	the two original bint stay unchanged in the process.
*/

t_bint		*add_bint(t_bint const *const n1, t_bint const *const n2)
{
	size_t	i;
	size_t	l1;
	size_t	l2;
	t_bint	*res;

	i = 0;
	if (!n1 || !n2 || !(res = copy_bint(bint_longer(n1, n2))))
		return (NULL);
	free(res->num);
	l1 = n1->len - 1;
	l2 = n2->len - 1;
	if (!(res->num = (t_digit *)ft_memalloc(sizeof(t_digit) * (res->len + 2))))
		return (abort_bint(res));
	while (i < res->len)
	{
		res->num[res->len - i] += (l1 < i ? 0 : n1->num[l1 - i])\
				+ (l2 < i ? 0 : n2->num[l2 - i]);
		if (res->num[res->len - i] > 9)
			res->num[res->len - (i + 1)] = 1;
		res->num[res->len - i] %= 10;
		i++;
	}
	if (!*res->num || !(++res->len))
		ft_memmove(res->num, res->num + 1, res->len);
	return (res);
}
