/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 22:08:15 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/09 16:12:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!s || !f || !(ret = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (*s)
		ret[i++] = f(*s++);
	ret[i] = 0;
	return (ret);
}
