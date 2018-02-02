/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:32:56 by pdurand           #+#    #+#             */
/*   Updated: 2017/02/06 18:47:45 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 16

static int	proceed(int const fd, char *buff, char *s[fd])
{
	char	*tmp;
	char	*p;
	int		i;

	i = 0;
	while ((p = ft_strchr(s[fd], '\n')) == NULL &&
		(i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return (i == -1 ? -1 : 1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*s[OPEN_MAX];
	char		*tmp;
	char		*str;
	int			i;
	char		*buff;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if ((buff = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if (!s[fd] && (s[fd] = ft_strnew(1)) == NULL)
		return (-1);
	if ((i = proceed(fd, buff, s)) == -1)
		return (-1);
	if ((str = ft_strchr(s[fd], '\n')) != NULL)
	{
		*line = ft_strsub(s[fd], 0, str - s[fd]);
		tmp = s[fd];
		s[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(s[fd]);
	s[fd] = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
