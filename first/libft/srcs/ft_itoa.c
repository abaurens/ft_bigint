/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:18:24 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/13 17:58:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_itoa(int n)
{
	size_t		i;
	long		nb;
	char		*ret;

	nb = n;
	i = ft_numlen(n);
	if (!(ret = (char *)malloc(i + 1)))
		return (NULL);
	ret[i--] = 0;
	*ret = (n == 0 ? '0' : '-');
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		ret[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ret);
}
