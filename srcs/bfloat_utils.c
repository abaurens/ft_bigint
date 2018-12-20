/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfloat_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 06:43:32 by abaurens          #+#    #+#             */
/*   Updated: 2018/12/20 06:53:37 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bigfloat.h"

void			*abort_bfloat(t_bfloat const *const to_abort, char step)
{
	if (step > 0)
		free(to_abort->ent);
	free((void *)to_abort);
	return (NULL);
}
