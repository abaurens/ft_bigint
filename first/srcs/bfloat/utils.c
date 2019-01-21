/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:43:32 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 19:00:41 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"

t_bflt			*ent_longer(t_bflt *n1, t_bflt *n2)
{
	if (n1->entl < n2->entl)
		return (n2);
	return (n1);
}

t_bflt			*dec_longer(t_bflt *n1, t_bflt *n2)
{
	if (n1->decl < n2->decl)
		return (n2);
	return (n1);
}

void			*abort_bflt(t_bflt const *const to_abort, char step)
{
	if (step > 0)
		free(to_abort->ent);
	free((void *)to_abort);
	return (NULL);
}
