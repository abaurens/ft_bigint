/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:15:22 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 20:15:07 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIGITS_H
# define DIGITS_H

# include "string.h"

/*
**	Data type used to store digits.
**	this allows to change the memory used by a single digit within the lib.
**
**	Stay consistant for t_sdigit type !
**	It must be exactly the same type but as a signed value.
*/
typedef unsigned long	t_digit;
typedef signed long		t_sdigit;

/*
**	Base used to store the numbers
**	(This is the minimum value that requiers 2 digits to be stored)
**	due to a (temporary) problem, this value has to be a power of 10.
**
**	This value has to be strictly both positive and lower than
**	sqrt(2^sizeof(t_digit))
**
**	in theory, this macro can be at most 1000000000 if the system is 64 bit
**	and if t_digit is unsigned long
*/
# define DIGIT_MAX 1000000000ull

char			*mul_deci(const char *n1, const char *n2);
char			*add_deci(const char *n1, const char *n2);
t_digit			div_prs(char *v);
void			swap_deci(const char **n1, const char **n2);
char			*digits_tostr(t_digit *dgts, size_t lens);

#endif
