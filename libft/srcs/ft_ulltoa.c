/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:53:14 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/29 16:32:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char		*ft_ulltoa(unsigned long long int nb)
{
	size_t	len;
	char	*ret;

	len = ft_unsignedlen(nb);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	ret[len] = 0;
	ret[0] = '0';
	while (nb != 0)
	{
		ret[--len] = (ft_abs(nb % 10) + '0');
		nb /= 10;
	}
	return (ret);
}
