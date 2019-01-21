/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:54:31 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/21 16:44:22 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

static const unsigned int	g_pow10[] =
{
	1, /* 10^0 */
	10, /* 10^1 */
	100, /* 10^2 */
	1000, /* 10^3 */
	10000, /* 10^4 */
	100000, /* 10^5 */
	1000000, /* 10^6 */
	10000000 /* 10^7 */
};

static const t_bint			g_pow10_b[] =
{
	{ 1, { 100000000 } }, /* 10^8 */
	{ 2, { 0x6fc10000, 0x002386f2 } }, /* 10^16 */
	{ 4, { 0, 0x85acef81, 0x2d6d415b, 0x000004ee, } }, /* 10^32 */
	{ 7, { 0, 0, 0xbf6a1f01, 0x6e38ed64, 0xdaa797ed, 0xe93ff9f4, 0x00184f03, } }, /* 10^64 */
	{ 14, { 0, 0, 0, 0, 0x2e953e01, 0x03df9909, 0x0f1538fd, 0x2374e42f,
		0xd3cff5ec, 0xc404dc08, 0xbccdb0da, 0xa6337f19, 0xe91f2603, 0x0000024e, } }, /* 10^128 */
	{ 27, { 0, 0, 0, 0, 0, 0, 0, 0, 0x982e7c01, 0xbed3875b, 0xd8d99f72,
			0x12152f87, 0x6bde50c6, 0xcf4a6e70, 0xd595d80f, 0x26b2716e,
			0xadc666b0, 0x1d153624, 0x3c42d35a, 0x63ff540e, 0xcc5573c0,
			0x65f9ef17, 0x55bc28f2, 0x80dcc7f7, 0xf46eeddc, 0x5fdcefce,
			0x000553f7, } } /* 10^256 */
};

void				bipow10(t_bint *const res, unsigned int ex)
{
	unsigned int	i;
	t_bint			t1;
	t_bint			t2;
	t_bint			*tc;
	t_bint			*tn;

	tc = &t1;
	tn = &t2;
	BIASSERT(ex < 1024, tried to compute 10^1024 or upper value...);
	i = ex & 0b111;
	bi_set(&t1, g_pow10[i]);
	ex >>= 3;
	i = 0;
	while (ex != 0)
	{
		if (ex & 1)
		{
			bimul(tn, tc, g_pow10_b + i);
			swap((uintptr_t *)&tn, (uintptr_t *)&tc);
		}
		ex >>= 1;
		i++;
	}
	*res = *tc;
}

void	bimul_pow10(t_bint *res, t_bint *n, unsigned int ex)
{
	unsigned int	i;
	t_bint			t1;
	t_bint			t2;
	t_bint			*tc;
	t_bint			*tn;

	i = 0;
	BIASSERT(ex < 1024, tried to compute 10^1024 or upper value...);
	i = ex & 0b111;
	t1 = *n;
    if (i != 0)
        bimulint(&t1, n, g_pow10[i]);
	ex >>= 3;
	i = 0;
	tc = &t1;
	tn = &t2;
	while (ex != 0)
	{
		if (ex & 1)
		{
			bimul(tn, tc, g_pow10_b + i);
			swap((uintptr_t *)&tn, (uintptr_t *)&tc);
		}
		ex >>= 1;
		i++;
	}
	*res = *tc;
}

void	bipow2(t_bint *res, unsigned int ex)
{

}
