/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:10:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/09 17:36:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	is_white(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (s && is_white(*s))
		s++;
	ret = (char *)s;
	while (s && *ret)
	{
		if (!is_white(*ret))
			i = (ret - s) + 1;
		ret++;
	}
	ret = ft_strsub(s, 0, i);
	return (ret);
}
