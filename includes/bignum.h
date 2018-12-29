/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:23:58 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/29 21:45:30 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGNUM_H
# define BIGNUM_H

# include <string.h>

/*
**	Data type used to store digits.
**	this allows to change the memory used by a single digit within the lib.
*/
typedef unsigned long	t_digit;

/*
**	Base used to store the numbers
**	(This is the minimum value that requiers 2 digits to be stored)
**
**	This value has to be strictly both positive and lower than
**	sqrt(2^sizeof(t_digit))
**
**	in theory, this macro can be at most 4294967295 if the system is 64 bit
**	and if t_digit is unsigned long
*/
/*# define DIGIT_MAX 4294967295ull*/
# define DIGIT_MAX 10ull

char	*add_deci(const char *n1, const char *n2);
char	*mul_deci(const char *n1, const char *n2);

#endif
