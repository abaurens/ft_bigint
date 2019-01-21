/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:46:04 by abaurens          #+#    #+#             */
/*   Updated: 2018/11/14 12:50:27 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s && *s)
	{
		if (*s != c && (s[1] == c || s[1] == 0))
			i++;
		s++;
	}
	return (i);
}

static void		*free_tab(char **tab)
{
	char		**tmp;

	tmp = (char **)tab;
	while (tab && *tab)
		free(*tab++);
	free(tmp);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		wrds;
	char		**ret;

	i = 0;
	ret = NULL;
	wrds = count_words(s, c);
	if (!(ret = malloc(sizeof(char *) * (wrds + 1))))
		return (NULL);
	ret[wrds] = 0;
	while (s && *s && *s == c)
		s++;
	while (s && *s)
	{
		if (!(ret[i++] = ft_strsub(s, 0, ft_idxof(c, s))))
			return (free_tab(ret));
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (ret);
}
