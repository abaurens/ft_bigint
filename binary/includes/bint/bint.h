/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bint.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 02:38:17 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/20 20:03:05 by abaurens         ###   ########.fr       */
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
**
**	Theoricaly, MAX_BINT_VALS could (and will probably in the future)
**		be 4294967295 (UINT_MAX).
*/
/*
# define MAX_BINT_VALS 0xFFFFFFFF
# define BIT_PER_BLOCK 32*/ /* (8 * 4) */


# define MAX_BINT_VALS 0xFF
# define BIT_PER_BLOCK 8 /* (8 * 1) */

/*
**	Got those times by computing (ULONG_MAX += ULONG_MAX) 100000 times only with
**	addition.
**		12.19user 0.01system 0:12.28elapsed 99%CPU
**
**	Got those times by computing (2^50000)
**		5.95user 0.01system 0:06.01elapsed 99%CPU (mul)
**		2.71user 0.00system 0:02.73elapsed 99%CPU (mul2)
*/

/*
# define MAX_BINT_VALS 10ul
# define MAX_DIGIT_LEN 1
*/
/*
**	(ULONG_MAX += ULONG_MAX) 100000 times
**	22.25user 0.02system 0:22.38elapsed 99%CPU
**
**	(2^50000)
**		9.06user 0.01system 0:09.16elapsed 99%CPU (mul)
**		4.52user 0.00system 0:04.54elapsed 99%CPU (mul2)
**
*/

typedef unsigned char	t_block;
typedef unsigned int	t_proc;

typedef struct			s_bint
{
	size_t				len;
	t_block				blks[MAX_BINT_BLKS];
}						t_bint;

t_bint	bi_init(t_bint *n);
void	bi_set(t_bint *n, unsigned long val);

/*
**	print.c
*/
void	bi_print_bin(t_bint const *const n);
void	bi_print_deci(t_bint const *const n);

/*
**	bint_cmp.c
*/
long	bicmp(const t_bint *lhs, const t_bint *rhs);
long	bicmplng(const t_bint *lhs, unsigned long v);

/*
**	add.c
*/
void	biadd(t_bint *res, t_bint *n1, t_bint *n2);

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

/*
**	div.c
*/
t_block	bidivint(t_bint *res, t_bint *n, unsigned int v);
void	bidiv(t_bint *res, t_bint *n1, t_bint *n2);

/*
**	utils.c
*/
void		swap(uintptr_t *n1, uintptr_t *n2);

#endif
