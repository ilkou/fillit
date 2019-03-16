/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghous <mmaghous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:50:38 by oouklich          #+#    #+#             */
/*   Updated: 2019/02/11 16:40:18 by mmaghous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_line(char **store, char **line, int fd)
{
	char	*temp;
	int		len;

	len = 0;
	while (store[fd][len] != '\n' && store[fd][len] != '\0')
		len++;
	if (store[fd][len] == '\n')
	{
		*line = ft_strsub(store[fd], 0, len);
		temp = ft_strdup(store[fd] + len + 1);
		free(store[fd]);
		store[fd] = temp;
		if (!(*line) || !store[fd])
			return (-1);
	}
	else if (store[fd][len] == '\0')
	{
		*line = ft_strdup(store[fd]);
		if (!(*line))
			return (-1);
		ft_strdel(&store[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*store[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (line == NULL)
		return (-1);
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (store[fd] == NULL)
			store[fd] = ft_strnew(1);
		temp = ft_strjoin(store[fd], buf);
		free(store[fd]);
		store[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (store[fd] == NULL || store[fd][0] == '\0'))
		return (0);
	return (ft_read_line(store, line, fd));
}
