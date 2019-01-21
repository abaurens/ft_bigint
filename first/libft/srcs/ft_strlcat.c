/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:26:30 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/13 14:12:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (i < size)
	{
		if (dst[i] == 0)
		{
			i = 0;
			len = ft_strlen(dst);
			while (src[i] && i < (size - len) - 1)
			{
				dst[len + i] = src[i];
				i++;
			}
			dst[len + i] = '\0';
			return (len + ft_strlen(src));
		}
		i++;
	}
	return (size + ft_strlen(src));
}
