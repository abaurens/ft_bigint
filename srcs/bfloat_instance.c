/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfloat_instance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:20:27 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 07:46:12 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"

t_bfloat		*new_bfloat(const char *value)
{
	t_bfloat	*res;

	if (!(res = (t_bfloat *)malloc(sizeof(t_bfloat))))
		return (NULL);
	if (!set_bfloat(res, value))
		return (NULL);
	return (res);
}

void			unset_bfloat(t_bfloat *const num)
{
	free(num->ent);
	free(num->dec);
	num->entl = 0;
	num->decl = 0;
}

void			del_bfloat(t_bfloat const *const num)
{
	free(num->ent);
	free(num->dec);
	free((void *)num);
}
