/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:04:01 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 19:25:43 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"
#include "ft_bigint.h"
#include "libft.h"

t_bint		*in_bint(t_bint *dst, t_bflt const *const num)
{
	unset_bint(dst);
	dst->len = num->entl;
	if (!(dst->num = malloc(sizeof(t_digit) * dst->len)))
		return ((t_bint *)ft_freturn(dst, 0x0));
	ft_memcpy(dst->num, num->ent, sizeof(t_digit) * dst->len);
	return (dst);
}

t_bflt		*in_bflt(t_bflt *dst, t_bint const *const num)
{
	unset_bflt(dst);
	dst->entl = num->len;
	dst->len = dst->entl;
	dst->decl = 0;
	if (!(dst->ent = malloc(sizeof(t_digit) * dst->entl)))
		return ((t_bflt *)ft_freturn(dst, 0x0));
	ft_memcpy(dst->ent, num->num, sizeof(t_digit) * dst->entl);
	return (dst);
}

t_bint		*to_bint(t_bflt const *const num)
{
	t_bint	*res;

	if (!(res = new_bint(NULL)))
		return (NULL);
	return (in_bint(res, num));
}

t_bflt		*to_bflt(t_bint const *const num)
{
	t_bflt	*res;

	if (!(res = new_bflt(NULL)))
		return (NULL);
	return (in_bflt(res, num));
}
