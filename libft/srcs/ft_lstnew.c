/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 02:47:20 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/08 02:58:49 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void			*abort_creation(t_list *elem)
{
	free(elem->content);
	free(elem);
	return (NULL);
}

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
	ret->content = NULL;
	ret->content_size = 0;
	if (content)
	{
		if (!(ret->content = ft_memalloc(content_size)))
			return (abort_creation(ret));
		ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
	}
	return (ret);
}
