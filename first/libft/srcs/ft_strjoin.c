/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:03:18 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/09 16:15:31 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l;
	char	*ret;

	i = 0;
	if (s1 && s2)
		l = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2 || !(ret = (char *)malloc(l + 1)))
		return (NULL);
	ret[l] = 0;
	while (s1 && *s1 && i < l)
		ret[i++] = *s1++;
	while (s2 && *s2 && i < l)
		ret[i++] = *s2++;
	return (ret);
}
