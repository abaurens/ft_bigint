/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:04:26 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/22 04:53:14 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"

t_bint		*new_bint(const char *value)
{
	size_t	i;
	t_bint	*res;

	i = 0;
	if (!(res = (t_bint *)malloc(sizeof(t_bint))))
		return (NULL);
	if (!set_bint(res, value))
		return (abort_bint(res));
	return (res);
}

t_bint		*copy_bint(t_bint const *const num)
{
	size_t	i;
	t_bint	*res;

	i = 0;
	if (!(res = malloc(sizeof(t_bint))))
		return (NULL);
	res->len = num->len;
	res->neg = num->neg;
	if (!(res->num = (t_digit *)malloc(sizeof(t_digit) * res->len)))
		return (abort_bint(res));
	while (i < res->len)
	{
		res->num[i] = num->num[i];
		i++;
	}
	return (res);
}

void		unset_bint(t_bint *const num)
{
	if (!num)
		return ;
	free(num->num);
	num->len = 0;
}

void		del_bint(t_bint const *const num)
{
	if (num)
		free(num->num);
	free((void *)num);
}
