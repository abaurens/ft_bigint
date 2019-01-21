/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:54:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/21 18:04:35 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

static const unsigned int	g_pow10[] =
{
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000
};

static const t_bint			g_pow10_b[] =
{
	{1, {100000000}},
	{2, {0x6fc10000, 0x002386f2}},
	{4, {0, 0x85acef81, 0x2d6d415b, 0x000004ee}},
	{7, {0, 0, 0xbf6a1f01, 0x6e38ed64, 0xdaa797ed, 0xe93ff9f4, 0x00184f03}},

	{14, {0, 0, 0, 0, 0x2e953e01, 0x03df9909, 0x0f1538fd,
			0x2374e42f, 0xd3cff5ec, 0xc404dc08, 0xbccdb0da,
			0xa6337f19, 0xe91f2603, 0x0000024e}},
	{27, {0, 0, 0, 0, 0, 0, 0, 0, 0x982e7c01, 0xbed3875b, 0xd8d99f72,
			0x12152f87, 0x6bde50c6, 0xcf4a6e70, 0xd595d80f, 0x26b2716e,
			0xadc666b0, 0x1d153624, 0x3c42d35a, 0x63ff540e, 0xcc5573c0,
			0x65f9ef17, 0x55bc28f2, 0x80dcc7f7, 0xf46eeddc, 0x5fdcefce,
			0x000553f7}}
};

void				bipow10(t_bint *const res, unsigned int ex)
{
	unsigned int	i;
	t_bint			t1;
	t_bint			t2;

	BIASSERT(ex < 512, "tried to compute 10^512 or upper value...");
	i = ex & 0b111;
	bi_set(&t1, g_pow10[i]);
	ex >>= 3;
	i = 0;
	while (ex != 0)
	{
		t2 = g_pow10_b[i++];
		if (ex & 1)
			bimulto(&t1, &t2);
		ex >>= 1;
	}
	*res = t1;
}

void				bimul_pow10(t_bint *res, t_bint *n, unsigned int ex)
{
	unsigned int	i;
	t_bint			t1;
	t_bint			t2;

	BIASSERT(ex < 512, "tried to compute 10^512 or upper value...");
	t1 = *n;
	if ((i = (ex & 0b111)) != 0)
		bimulint(&t1, n, g_pow10[i]);
	i = 0;
	ex >>= 3;
	while (ex != 0)
	{
		t2 = g_pow10_b[i++];
		if (ex & 1)
			bimulto(&t1, &t2);
		ex >>= 1;
	}
	*res = t1;
}

void				bipow2(t_bint *res, unsigned int ex)
{
	unsigned int	i;
	unsigned int	j;
	t_bint			r;

	j = 0;
	i = ex / 32;
	BIASSERT(i < MAX_BINT_BLKS, "this power of 2 is too big for MAX_BINT_BLKS");
	while (j <= i)
		r.blks[j++] = 0;
	r.len = i + 1;
	j = (ex % 32);
	r.blks[i] |= (1 << j);
	*res = r;
}
