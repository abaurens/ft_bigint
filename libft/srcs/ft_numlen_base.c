/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:27:58 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 17:13:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_numlen_base(long long int nb, const char *base)
{
	size_t	len;
	size_t	blen;

	len = 1;
	if (!base || !ft_isbase(base))
		return (0);
	blen = ft_strlen(base);
	if (nb < 0)
		len++;
	while ((nb /= blen) != 0)
		len++;
	return (len);
}
