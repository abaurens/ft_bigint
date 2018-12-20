/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigfloat.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:22:45 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 07:36:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGFLOAT_H
# define FT_BIGFLOAT_H

# include "bignum_types.h"

typedef struct			s_bfloat
{
	unsigned char		neg;
	t_digit				*ent;
	t_digit				*dec;
	size_t				entl;
	size_t				decl;
	size_t				len;
}						t_bfloat;

t_bfloat		*new_bfloat(const char *value);
t_bfloat		*set_bfloat(t_bfloat *num, const char *value);
t_bfloat		*copy_bfloat(t_bfloat const *const num);
void			unset_bfloat(t_bfloat *const num);
void			del_bfloat(t_bfloat const *const num);

char			*bfloat_tostr(t_bfloat const *const num);
void			*abort_bfloat(t_bfloat const *const to_abort, char step);

#endif
