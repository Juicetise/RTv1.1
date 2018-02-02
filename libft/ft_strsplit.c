/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:52:37 by pdurand           #+#    #+#             */
/*   Updated: 2016/11/15 14:52:39 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(const char *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_wordlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wordnb;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	wordnb = ft_wordcount((const char *)s, c);
	tab = (char **)malloc(sizeof(*tab) *
		(ft_wordcount((const char *)s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (wordnb--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_wordlen((const char *)s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
