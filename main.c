/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:18:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/29 13:48:05 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_bigint.h"
#include "ft_bigfloat.h"
#include "bignum.h"

int				main(void)
{
	t_bint		n;
	set_bint(&n, "98765432109876543210");
	print_bint(&n);
	unset_bint(&n);

	/*	423
		211

		423
	   423
	  846
	  89253
	*/
	return (0);
}
