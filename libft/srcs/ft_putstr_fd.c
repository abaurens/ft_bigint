/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:43:03 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/13 14:19:24 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	size_t	l;

	l = 0;
	while (s && s[l])
		l++;
	if (s && l)
		write(fd, s, l);
}
