/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:23:01 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/07 21:25:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sr;

	sr = (unsigned char *)s;
	while (n > 0)
	{
		if (*sr == ((unsigned char)c))
			return (sr);
		sr++;
		n--;
	}
	return (NULL);
}
