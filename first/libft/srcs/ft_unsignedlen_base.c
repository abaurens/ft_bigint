/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:30:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 16:17:26 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_unsignedlen_base(unsigned long long int nb, const char *base)
{
	size_t	len;
	size_t	blen;

	len = 1;
	if (!base || !ft_isbase(base))
		return (0);
	blen = ft_strlen(base);
	while ((nb /= blen) != 0)
		len++;
	return (len);
}
