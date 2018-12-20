/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:54:31 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 21:12:46 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bigfloat.h"

static void			swap(t_bflt const **const n1, t_bflt const **const n2)
{
	const t_bflt	*lng;

	lng = *n2;
	if ((*n1)->len < (*n2)->len)
	{
		*n2 = *n1;
		*n1 = lng;
	}
}

t_bflt				*mul_bint(t_bflt const *n1, t_bflt const *n2)
{
	return (NULL);
}
