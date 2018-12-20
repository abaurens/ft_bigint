/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:54:27 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/07 21:57:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc(size + 1);
	while (ret && i <= size)
		ret[i++] = 0;
	return (ret);
}
