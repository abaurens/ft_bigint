/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bnum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:23:58 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/30 19:26:00 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNUM_H
# define BNUM_H

# include "ft_bigint.h"
# include "ft_bigfloat.h"

t_bint	*to_bint(t_bflt const *const num);
t_bflt	*to_bflt(t_bint const *const num);
t_bint	*in_bint(t_bint *dst, t_bflt const *const num);
t_bflt	*in_bflt(t_bflt *dst, t_bint const *const num);

#endif
