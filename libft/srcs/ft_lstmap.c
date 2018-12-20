/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:47:16 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/13 18:41:24 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		*abort_creation(t_list *lst)
{
	t_list		*prev;

	while (lst)
	{
		prev = lst;
		lst = lst->next;
		free(prev);
	}
	return (NULL);
}

static void		push_back(t_list **list, t_list *elem)
{
	t_list		*last;

	if (list)
		last = *list;
	while (list && last && last->next)
		last = last->next;
	if (*list == NULL)
		*list = elem;
	else
		last->next = elem;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ret;
	t_list		*new;

	ret = NULL;
	while (lst)
	{
		if (!(new = f(lst)))
			return (abort_creation(ret));
		push_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}
