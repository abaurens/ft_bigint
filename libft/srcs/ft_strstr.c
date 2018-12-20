/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:18:32 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/08 16:39:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	while (*haystack)
	{
		i = 0;
		while (needle[i] && haystack[i] && needle[i] == haystack[i])
			i++;
		if (needle[i] == 0)
			return ((char *)haystack);
		haystack++;
	}
	if (!*needle)
		return ((char *)haystack);
	return (NULL);
}
