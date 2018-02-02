/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:23:00 by pdurand           #+#    #+#             */
/*   Updated: 2016/11/10 17:23:01 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	j = 0;
	length = 0;
	while (dst[i] != '\0' && length != dstsize)
	{
		length++;
		i++;
	}
	if (length == dstsize)
		return (length + ft_strlen((char *)src));
	while (j < (dstsize - length - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (length + ft_strlen((char *)src));
}
