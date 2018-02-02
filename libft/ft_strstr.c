/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:39:55 by pdurand           #+#    #+#             */
/*   Updated: 2016/11/06 17:39:56 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*src1;

	src1 = (char *)s1;
	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (src1);
	while (src1[i])
	{
		k = i;
		while (s2[j] == src1[k])
		{
			k++;
			j++;
			if (s2[j] == '\0')
				return (&src1[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
