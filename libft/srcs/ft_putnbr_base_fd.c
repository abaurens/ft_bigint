/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:59:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/10 13:05:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	putnbr_b(unsigned long n, const char *b, size_t l, int fd)
{
	if (n / l != 0)
		putnbr_b(n / l, b, l, fd);
	ft_putchar_fd(n % l + '0', fd);
}

void		ft_putnbr_base_fd(int n, const char *base, int fd)
{
	long	nb;

	nb = n;
	if (!ft_isbase(base))
		return ;
	if (n < 0)
		write(1, "-", 1);
	putnbr_b((unsigned long)(n < 0 ? -nb : nb), base, ft_strlen(base), fd);
}
