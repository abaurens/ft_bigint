/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:19:28 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 18:27:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIGINT_H
# define FT_BIGINT_H

# include <string.h>
# include "digits.h"

typedef struct		s_bint
{
	unsigned char	neg;
	t_digit			*num;
	size_t			len;
}					t_bint;

t_bint				*new_bint(const char *value);
t_bint				*set_bint(t_bint *num, const char *value);
t_bint				*copy_bint(t_bint const *const num);
void				unset_bint(t_bint *const num);
void				del_bint(t_bint const *const num);

char				*bint_tostr(t_bint const *const num);
void				print_bint(t_bint const *const num);

void				*abort_bint(t_bint const *const to_abort);
const t_bint		*bint_longer(t_bint const *const n1,
									t_bint const *const n2);
const t_bint		*bint_shorter(t_bint const *const n1,
									t_bint const *const n2);
t_sdigit			bint_cmp(t_bint const *const n1, t_bint const *const n2);

t_bint				*add_bint(t_bint const *const n1, t_bint const *const n2);
t_bint				*mul_bint(t_bint const *n1, t_bint const *n2);
t_bint				*div_bint(t_bint *n1, t_bint *n2);
t_bint				*mod_bint(t_bint *n1, t_bint *n2);

t_bint				*sub_bint(t_bint *n1, t_bint *n2);

#endif
