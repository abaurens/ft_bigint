/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idxof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:50:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/04 01:22:40 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_idxof(const char c, const char *str)
{
	register char const	*s;

	s = str;
	while (s && *s && *s != c)
		++s;
	return (s - str);
}
