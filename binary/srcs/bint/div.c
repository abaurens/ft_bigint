/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:25:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/20 19:22:19 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

unsigned int	bidiv_maxq9(t_bint *dividend, t_bint *divisor)
{
    /*
	**	Check that the divisor has been correctly shifted into range and that it is not
    **	smaller than the dividend in length.
	*/
    BIASSERT(!divisor.IsZero() &&
				divisor.m_blocks[divisor.m_length-1] >= 8 &&
				divisor.m_blocks[divisor.m_length-1] < 0xFFFFFFFF &&
				pDividend->m_length <= divisor.m_length );

    // If the dividend is smaller than the divisor, the quotient is zero and the divisor is already
    // the remainder.
    tU32 length = divisor.m_length;
    if (pDividend->m_length < divisor.m_length)
        return 0;

    const tU32 * pFinalDivisorBlock  = divisor.m_blocks + length - 1;
    tU32 *       pFinalDividendBlock = pDividend->m_blocks + length - 1;

    // Compute an estimated quotient based on the high block value. This will either match the actual quotient or
    // undershoot by one.
    tU32  quotient = *pFinalDividendBlock / (*pFinalDivisorBlock + 1);
    RJ_ASSERT(quotient <= 9);

    // Divide out the estimated quotient
    if (quotient != 0)
    {
        // dividend = dividend - divisor*quotient
        const tU32 *pDivisorCur = divisor.m_blocks;
        tU32 *pDividendCur      = pDividend->m_blocks;

        tU64 borrow = 0;
        tU64 carry = 0;
        do
        {
            tU64 product = (tU64)*pDivisorCur * (tU64)quotient + carry;
            carry = product >> 32;

            tU64 difference = (tU64)*pDividendCur - (product & 0xFFFFFFFF) - borrow;
            borrow = (difference >> 32) & 1;

            *pDividendCur = difference & 0xFFFFFFFF;

            ++pDivisorCur;
            ++pDividendCur;
        } while(pDivisorCur <= pFinalDivisorBlock);

        // remove all leading zero blocks from dividend
        while (length > 0 && pDividend->m_blocks[length - 1] == 0)
            --length;

        pDividend->m_length = length;
    }

    // If the dividend is still larger than the divisor, we overshot our estimate quotient. To correct,
    // we increment the quotient and subtract one more divisor from the dividend.
    if ( BigInt_Compare(*pDividend, divisor) >= 0 )
    {
        ++quotient;

        // dividend = dividend - divisor
        const tU32 *pDivisorCur = divisor.m_blocks;
        tU32 *pDividendCur      = pDividend->m_blocks;

        tU64 borrow = 0;
        do
        {
            tU64 difference = (tU64)*pDividendCur - (tU64)*pDivisorCur - borrow;
            borrow = (difference >> 32) & 1;

            *pDividendCur = difference & 0xFFFFFFFF;

            ++pDivisorCur;
            ++pDividendCur;
        } while(pDivisorCur <= pFinalDivisorBlock);

        // remove all leading zero blocks from dividend
        while (length > 0 && pDividend->m_blocks[length - 1] == 0)
            --length;

        pDividend->m_length = length;
    }

    return quotient;
}
