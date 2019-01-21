/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 00:44:23 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/13 14:19:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t	l;

	l = 0;
	while (s && s[l])
		l++;
	if (s && l > 0)
		write(1, s, l);
	write(1, "\n", 1);
}
