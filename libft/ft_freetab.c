/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 01:58:46 by pdurand           #+#    #+#             */
/*   Updated: 2018/02/01 01:58:48 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_freetab(char **tab)
{
	int		i;

	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}