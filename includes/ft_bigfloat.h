/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigfloat.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:22:45 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/22 02:25:16 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGFLOAT_H
# define FT_BIGFLOAT_H

# include "bignum.h"

typedef struct		s_bflt
{
	unsigned char	neg;
	t_digit			*ent;
	t_digit			*dec;
	size_t			entl;
	size_t			decl;
	size_t			len;
}					t_bflt;

typedef t_bflt		t_bfloat;

t_bflt				*new_bflt(const char *value);
t_bflt				*set_bflt(t_bflt *num, const char *value);
t_bflt				*copy_bflt(t_bflt const *const num);
void				unset_bflt(t_bflt *const num);
void				del_bflt(t_bflt const *const num);

char				*bfloat_tostr(t_bflt const *const num);
void				print_bflt(t_bflt const *const num);

void				*abort_bflt(t_bflt const *const to_abort, char step);

t_bflt				*add_bflt(t_bflt const *const n1, t_bflt const *const n2);
t_bflt				*mul_bflt(t_bflt const *const n1, t_bflt const *const n2);

#endif
