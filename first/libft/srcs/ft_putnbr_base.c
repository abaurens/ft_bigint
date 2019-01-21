/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:16:20 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/10 13:05:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	putnbr_b(unsigned long n, const char *b, size_t l)
{
	if (n / l != 0)
		putnbr_b(n / l, b, l);
	ft_putchar(n % l + '0');
}

void		ft_putnbr_base(int n, const char *base)
{
	long	nb;

	nb = n;
	if (!ft_isbase(base))
		return ;
	if (n < 0)
		write(1, "-", 1);
	putnbr_b((unsigned long)(n < 0 ? -nb : nb), base, ft_strlen(base));
}
