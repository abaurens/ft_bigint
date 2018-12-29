/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:18:59 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/29 21:44:43 by abaurens         ###   ########.fr       */
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
	t_bflt		f;

	/*set_bflt(&f, "10.5");*/
	set_bflt_base(&f, "10.5");
	/*print_bflt(&f);
	unset_bflt(&f);*/
	return (0);
}

/*
int		bin_int(int n)
{
	int	r;

	r = 0;
	while (n != 0)
	{
		r = r * 10 + n % 2;
		n /= 2;
	}
	return (bin_int(n / 2) * 10 + n % 2);
}

double bin_double(double d, int p)
{
	int		i;
	double	r;
	double	b;

	i = 0;
	r = d;
	while (i < p)
	{
		r *= 2; //deplace la virgule (de la representation binaire) a droite
		i++;
	}
	// a ce stade, le nombre represente en binaire n'a plus de virgule jusqu'a la partie voulue
	b = bin_int((int)r); // on convertis la partie entiere comme si c'etait un int
	while (i >= 0)
	{
		b /= 10.0; //deplace la virgule vers la gauche pour recuperer le nombre de sous-multiples voulu
		i--;
	}
	return (b);
}

*/
