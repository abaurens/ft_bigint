/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bint.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 02:38:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/22 19:47:56 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINT_H
# define BINT_H

# define _GNU_SOURCE
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>

# define BIASSERT(CND, MSG) if (!(CND)) { \
	dprintf(2, "Assertion (%s) failed : %s\n", #CND, #MSG); \
	abort(); \
}

# define MAX_BINT_BLKS 100000ul

/*
**	Because of multiplication, the maximum value of a single block
**		has to be less or equals to sqrt(2^(sizeof(t_block) * 8) - 1).
**
**	Basically, since t_block is an unsigned long, MAX_BINT_VALS has
**		to be less than sqrt(ULONG_MAX) which is 4294967295 (UINT_MAX).
**	This is because the bigger value a t_block has to store is
**		MAX_BINT_VALS^2 (when multiplying).
*/

# define MAX_BINT_VALS 0xFFFFFFFF
# define BIT_PER_BLOCK 32 /* (8 * 4) */

typedef unsigned int	t_block;
typedef unsigned long	t_proc;

typedef struct			s_bint
{
	size_t				len;
	t_block				blks[MAX_BINT_BLKS];
}						t_bint;

t_bint	bi_init(t_bint const *const n);
char	biiszero(t_bint const *const n);
void	bi_set(t_bint *n, unsigned long val);

/*
**	print.c
*/
void	bi_print_dec(t_bint const *const n);
void	bi_print_bin(t_bint const *const n);
void	bi_print_bin_space(t_bint const *const n);

/*
**	bint_cmp.c
*/
long	bicmp(const t_bint *lhs, const t_bint *rhs);
long	bicmplng(const t_bint *lhs, unsigned long v);

/*
**	add.c
*/
void	biincrement(t_bint *n1);
void	biadd(t_bint *res, t_bint *n1, t_bint *n2);
void	biaddint(t_bint *res, t_bint *n1, unsigned int v);

/*
**	sub.c
*/
void	bisub(t_bint *res, t_bint *n1, t_bint *n2);
void	bisubint(t_bint *res, t_bint *n1, unsigned int v);

/*
**	mul.c
*/
void	bimul(t_bint *res, t_bint *n1, t_bint *n2);
void	bimulto(t_bint *n1, t_bint *n2);
void	bimulint(t_bint *res, t_bint *n1, unsigned int v);
void	bimulintto(t_bint *n1, unsigned int v);

void	bimul2(t_bint *res, t_bint *n);
void	bimul10(t_bint *res, t_bint *n);
void	bimul2to(t_bint *n);
void	bimul10to(t_bint *n);

/*
**	pow.c
*/
void	bipow10(t_bint *const res, unsigned int ex);
void	bimul_pow10(t_bint *res, t_bint *n, unsigned int ex);

/*
**	div.c
*/
t_block	bidiv_maxq9(t_bint *n1, t_bint *n2);
unsigned int bi_divide_with_remainder_max_quotient9(t_bint *pDividend, const t_bint *div);

/*
**	shift.c
*/
void	bi_shift_left(t_bint *res, unsigned int shift);
void	bi_shift_left_2(t_bint *res, unsigned int shift);

/*
**	utils.c
*/
void	swap(uintptr_t *n1, uintptr_t *n2);

#endif
