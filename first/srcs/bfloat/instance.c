/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:20:27 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 20:01:50 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"
#include "libft.h"

t_bflt		*new_bflt(const char *value)
{
	t_bflt	*res;

	if (!(res = (t_bflt *)ft_memalloc(sizeof(t_bflt))))
		return (NULL);
	if (!set_bflt_base(res, value))
		return ((t_bflt *)ft_freturn(res, 0x0));
	return (res);
}

void		unset_bflt(t_bflt *const num)
{
	if (!num)
		return ;
	free(num->ent);
	free(num->dec);
	num->entl = 0;
	num->decl = 0;
}

void		del_bflt(t_bflt const *const num)
{
	if (num)
	{
		free(num->ent);
		free(num->dec);
	}
	free((void *)num);
}
