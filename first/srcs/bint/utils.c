/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 05:10:07 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 18:47:03 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"
#include "libft.h"

const t_bint	*bint_longer(t_bint const *const n1, t_bint const *const n2)
{
	if (n1->len > n2->len)
		return (n1);
	return (n2);
}

const t_bint	*bint_shorter(t_bint const *const n1, t_bint const *const n2)
{
	if (n1->len < n2->len)
		return (n1);
	return (n2);
}

t_sdigit		bint_cmp(t_bint const *const n1, t_bint const *const n2)
{
	size_t		i;
	t_digit		d1;
	t_digit		d2;

	i = ft_max(n1->len, n2->len);
	while (i > 0)
	{
		d1 = (i <= n1->len ? n1->num[n1->len - i] : 0);
		d2 = (i <= n2->len ? n2->num[n2->len - i] : 0);
		if (d1 != d2)
			return (d1 - d2);
		i--;
	}
	return (0);
}

void			*abort_bint(t_bint const *const to_abort)
{
	free((void *)to_abort);
	return (NULL);
}
