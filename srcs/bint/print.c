/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:07:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/22 20:03:23 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bint/bint.h"

void		bi_print_bin(t_bint const *const n)
{
	t_block	b;
	size_t	i;
	int		j;

	i = n->len;
	while (i-- > 0)
	{
		b = n->blks[i];
		j = (sizeof(b) * 8) - 1;
		while (i == n->len - 1 && ((b >> j) & 1) == 0 && j >= 0)
			j--;
		while (j >= 0)
			printf("%c", (char)(((b >> j--) & 1) + '0'));
	}
}

void		bi_print_bin_space(t_bint const *const n)
{
	t_block	b;
	size_t	i;
	int		j;

	i = n->len;
	while (i-- > 0)
	{
		b = n->blks[i];
		j = (sizeof(b) * 8) - 1;
		while (i == n->len - 1 && ((b >> j) & 1) == 0 && j >= 0)
			j--;
		while (j >= 0)
			printf("%c", (char)(((b >> j--) & 1) + '0'));
		if (i > 0)
			printf(" ");
	}
}

void		bi_print_dec(t_bint const *const n)
{
	t_bint	t;
	size_t	l;
	size_t	i;
	char	*tmp;

	l = 0;
	t = bi_init(n);
	while (bicmplng(&t, 0) > 0)
	{
		bidiv10(&t, &t);
		l++;
	}
	if (!l)
		l++;
	if (!(tmp = malloc(l + 1)))
		return ;
	tmp[(i = l)] = 0;
	tmp[0] = '0';
	t = bi_init(n);
	while (bicmplng(&t, 0) > 0)
		tmp[--i] = bidiv10(&t, &t) + '0';
	printf("%s", tmp);
	free(tmp);
}
