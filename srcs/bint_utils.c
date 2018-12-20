/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 05:10:07 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 06:39:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigint.h"

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

void			*abort_bint(t_bint const *const to_abort)
{
	free((void *)to_abort);
	return (NULL);
}
