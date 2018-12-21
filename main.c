/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:18:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/21 14:56:11 by abaurens         ###   ########.fr       */
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
	t_bflt	*i;
	t_bflt	*r;

	n = new_bflt("2.0");
	i = new_bflt("2.2");
	r = mul_bflt(n, i);
	del_bflt(n);
	print_bflt(r);
	del_bflt(r);
	return (0);
}
