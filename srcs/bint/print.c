/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:07:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/21 19:58:11 by abaurens         ###   ########.fr       */
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
	((void)n);
}
