/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:25:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/23 05:42:31 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		bidiv(t_bint *res, t_bint *mod, t_bint *n1, t_bint *n2)
{
	t_bint	r;
	t_bint	m;

	bi_set(&r, 0);
	m = bi_init(n1);
	if (bicmp(n1, n2) < 0)
	{
		*res = r;
		*mod = m;
		return ;
	}
	while (bicmp(&m, n2) >= 0)
	{
		bisub(&m, &m, n2);
		biincrement(&r);
	}
	*mod = m;
	*res = r;
}

unsigned int	bidiv_maxq9(t_bint *n1, t_bint *n2)
{
	t_bint		t;


	bidiv(&t, n1, n1, n2);
	BIASSERT(t.len = 1 && t.blks[0] <= 9, "digit is over the base limit");
	return (t.blks[0]);
}

unsigned int	bidiv10(t_bint *res, t_bint *n1)
{
	size_t		i;
	t_proc		c;
	t_bint		r;

	c = 0;
	r.len = 0;
	if (bicmplng(n1, 10) < 0 && ((c = n1->blks[0]) || 1))
	{
		bi_set(res, 0);
		return (c);
	}
	i = n1->len;
	while (i-- > 0)
	{
		c = ((c << BIT_PER_BLOCK) | n1->blks[i]);
		if ((r.blks[i] = (c / 10)) || r.len)
			r.len++;
		c %= 10;
	}
	if (r.len == 0)
		r.len = 1;
	*res = r;
	return (c);
}

unsigned int BigInt_DivideWithRemainder_MaxQuotient9(t_bint *pDividend, const t_bint *divisor)
{
    /* Check that the divisor has been correctly shifted into range and that it is not
     smaller than the dividend in length. */
    BIASSERT(!biiszero(divisor), "divisor is zero");
	BIASSERT(divisor->blks[divisor->len - 1] >= 8, "divisor last block is 8 or under")
	BIASSERT(divisor->blks[divisor->len - 1] < 0xFFFFFFFF, "divisor last block is over 0xFFFFFFFF");
	BIASSERT(pDividend->len <= divisor->len, "dividend length is higher than divisor length");

    /* If the dividend is smaller than the divisor, the quotient is zero and the divisor is already
     the remainder. */
    unsigned int length = divisor->len;
    if (pDividend->len < divisor->len)
        return 0;

    const unsigned int * pFinalDivisorBlock  = divisor->blks + length - 1;
    unsigned int *       pFinalDividendBlock = pDividend->blks + length - 1;

    /* Compute an estimated quotient based on the high block value. This will either match the actual quotient or
     undershoot by one. */
    unsigned int  quotient = *pFinalDividendBlock / (*pFinalDivisorBlock + 1);
    RJ_ASSERT(quotient <= 9);

    /* Divide out the estimated quotient */
    if (quotient != 0)
    {
        /* dividend = dividend - divisor*quotient */
        const unsigned int *pDivisorCur = divisor->blks;
        unsigned int *pDividendCur      = pDividend->blks;

        unsigned long borrow = 0;
        unsigned long carry = 0;
        do
        {
            unsigned long product = (unsigned long)*pDivisorCur * (unsigned long)quotient + carry;
            carry = product >> 32;

            unsigned long difference = (unsigned long)*pDividendCur - (product & 0xFFFFFFFF) - borrow;
            borrow = (difference >> 32) & 1;

            *pDividendCur = difference & 0xFFFFFFFF;

            ++pDivisorCur;
            ++pDividendCur;
        } while(pDivisorCur <= pFinalDivisorBlock);

        /* remove all leading zero blocks from dividend */
        while (length > 0 && pDividend->blks[length - 1] == 0)
            --length;

        pDividend->len = length;
    }

    /* If the dividend is still larger than the divisor, we overshot our estimate quotient. To correct,
     we increment the quotient and subtract one more divisor from the dividend. */
    if ( bicmp(pDividend, divisor) >= 0 )
    {
        ++quotient;

        /* dividend = dividend - divisor */
        const unsigned int *pDivisorCur = divisor->blks;
        unsigned int *pDividendCur      = pDividend->blks;

        unsigned long borrow = 0;
        do
        {
            unsigned long difference = (unsigned long)*pDividendCur - (unsigned long)*pDivisorCur - borrow;
            borrow = (difference >> 32) & 1;

            *pDividendCur = difference & 0xFFFFFFFF;

            ++pDivisorCur;
            ++pDividendCur;
        } while(pDivisorCur <= pFinalDivisorBlock);

        /* remove all leading zero blocks from dividend */
        while (length > 0 && pDividend->blks[length - 1] == 0)
            --length;

        pDividend->len = length;
    }

    return quotient;
}
