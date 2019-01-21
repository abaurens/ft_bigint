/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:18:59 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/19 17:34:33 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_bigint.h"
#include "ft_bigfloat.h"
#include "libft.h"
#include "bnum.h"

int			main(void)
{
	int		i;
	t_bint	*f1;
	t_bint	*r;
	t_bint	*t;

	f1 = new_bint("2");
	r = new_bint("1");

	print_bint(r);
	i = 20000;
	while (i-- > 0)
	{
		t = r;
		printf("2 * ");
		fflush(stdout);
		print_bint(r);
		r = mul_bint(r, f1);
		print_bint(r);
		del_bint(t);
	}

	print_bint(r);

	del_bint(r);
	del_bint(f1);
	return (0);
}
