/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:46:52 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/08 02:54:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*cur;
	t_list		*prev;

	cur = *alst;
	prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		del(prev->content, prev->content_size);
		free(prev);
	}
	*alst = NULL;
}
