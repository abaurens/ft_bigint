/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 07:28:35 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 19:49:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_bigfloat.h"
#include "ft_bigint.h"
#include "bnum.h"
#include "libft.h"

static char	*decimal_part(t_bflt const *const num, char *res)
{
	char	*tmp;
	size_t	l;
	size_t	dl;

	if (!(tmp = digits_tostr(num->ent, num->entl)))
		return ((char *)ft_freturn(res, 0x0));
	while (*tmp == '0' && *(tmp + 1))
		ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
	l = ft_strlen(tmp);
	ft_memdel((void **)&tmp);
	if (l < ft_strlen(res))
		tmp = ft_strdup(res + l);
	dl = ft_idxof(0, tmp);
	while (dl > 0 && tmp[dl - 1] == '0')
		tmp[--dl] = 0;
	res[l] = 0;
	if (dl > 0)
	{
		if (!(res = (char *)ft_freturn(res, (long)ft_strmcat(res, ".", -1))))
			return ((char *)ft_freturn(tmp, 0x0));
		res = (char *)ft_freturn(res, (long)ft_strmcat(res, tmp, -1));
	}
	free(tmp);
	return (res);
}

char		*bfloat_tostr(t_bflt const *const num)
{
	size_t	i;
	t_bint	tmp;
	char	*res;

	i = 0;
	res = NULL;
	ft_bzero(&tmp, sizeof(tmp));
	tmp.len = num->entl + num->decl;
	if (!(tmp.num = malloc(sizeof(t_digit) * tmp.len)))
		return (NULL);
	while (i < tmp.len)
	{
		tmp.num[i] = (i < num->entl ? num->ent[i] : num->dec[i - num->entl]);
		i++;
	}
	if (!(res = bint_tostr(&tmp)))
		return (NULL);
	free(tmp.num);
	return (decimal_part(num, res));
}

void		print_bflt(t_bflt const *const num)
{
	char	*t;

	if (!num || !(t = bfloat_tostr(num)))
		return ;
	ft_putstr(t);
	free(t);
	write(1, "\n", 1);
}
