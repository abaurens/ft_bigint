/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:00:18 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 18:10:28 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_lltoa_base(long long int nb, const char *base)
{
	size_t	len;
	size_t	blen;
	char	*ret;

	if (!base || !ft_isbase(base))
		return (NULL);
	len = ft_numlen_base(nb, base);
	blen = ft_strlen(base);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	ret[len] = 0;
	ret[0] = (!nb ? base[0] : '-');
	while (nb != 0)
	{
		ret[--len] = (base[ft_abs(nb % blen)]);
		nb /= blen;
	}
	return (ret);
}
