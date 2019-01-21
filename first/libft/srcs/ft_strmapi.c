/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:15:10 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/09 16:10:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!s || !f || !(ret = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (*s)
	{
		ret[i] = f(i, *s++);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
