/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:18:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/21 01:12:34 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_bigint.h"
#include "ft_bigfloat.h"

int				main(void)
{
	t_bflt	*n;
	t_bint	*i;
	t_bflt	*r;
	t_bint	*s;

	n = new_bflt("234589876545678743456787.3458987645676454845764760049757");
	i = new_bint("2345898765456787434567873458987645676454845764760049757");
	r = mul_bflt(n, n);
	s = mul_bint(i, i);
	del_bflt(n);
	del_bint(i);
	print_bflt(r);
	write(1, " ", 1);
	print_bint(s);
	del_bflt(r);
	del_bint(s);
	return (0);
}
