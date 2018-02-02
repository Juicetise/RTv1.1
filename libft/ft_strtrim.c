/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:52:24 by pdurand           #+#    #+#             */
/*   Updated: 2016/11/15 14:52:25 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimlen(char const *str)
{
	int i;
	int j;
	int baselen;
	int count;

	i = 0;
	j = ft_strlen(str);
	count = 0;
	baselen = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		i++;
		count++;
	}
	while (str[j - 1] == ' ' || str[j - 1] == '\n' || str[j - 1] == '\t')
	{
		j--;
		count++;
	}
	if (count >= baselen)
		return (0);
	return (baselen - count);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	k = ft_trimlen(s);
	str = (char *)malloc(sizeof(char) * (k + 1));
	if (str == NULL)
		return (0);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (j < k)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
