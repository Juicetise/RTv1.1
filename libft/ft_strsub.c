/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:52:00 by pdurand           #+#    #+#             */
/*   Updated: 2016/11/15 14:52:01 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dst;

	if (s == NULL)
		return (NULL);
	dst = ft_strnew(len + 1);
	i = 0;
	if (dst == NULL)
		return (NULL);
	while (i < len + start)
	{
		if (i >= start)
			dst[i - start] = s[i];
		i++;
	}
	return (dst);
}
