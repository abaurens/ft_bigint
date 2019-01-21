/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:29:54 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/14 16:16:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_unsignedlen(unsigned long long int nb)
{
	size_t	len;

	len = 1;
	while ((nb /= 10) != 0)
		len++;
	return (len);
}
