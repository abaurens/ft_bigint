/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:18:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 05:58:52 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_bigint.h"

int			main(void)
{
	t_bint	*n1;
	t_bint	n2;
	t_bint	*r;

	n1 = new_bint(NULL);
	unset_bint(n1);
	set_bint(n1, "42");
	set_bint(&n2, "42");

	print_bint(n1);
	print_bint(&n2);
	if ((r = add_bint(n1, &n2)))
	{
		print_bint(r);
		del_bint(n1);
		if ((n1 = add_bint(r, &n2)))
		{
			print_bint(n1);
			del_bint(n1);
		}
		del_bint(r);
	}
	unset_bint(&n2);
	return (0);
}
