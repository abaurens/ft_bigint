/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:05:11 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 17:46:44 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_bigint.h"
#include "libft.h"

char			*bint_tostr(t_bint const *const num)
{
	char		*deci;

	deci = digits_tostr(num->num, num->len);
	while (*deci == '0' && *(deci + 1))
		ft_memmove(deci, deci + 1, ft_strlen(deci));
	if (num->neg)
		deci = (char *)ft_freturn(deci, (long)ft_strmcat("-", deci, -1));
	return (deci);
}

void			print_bint(t_bint const *const num)
{
	char		*t;

	if (!num || !(t = bint_tostr(num)))
		return ;
	ft_putstr(t);
	free(t);
	write(1, "\n", 1);
}
