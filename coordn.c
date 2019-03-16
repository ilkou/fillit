/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghous <mmaghous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:29:30 by oouklich          #+#    #+#             */
/*   Updated: 2019/02/11 16:57:12 by mmaghous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*fixit(char *bloc, char *line)
{
	char		*temp;

	temp = ft_strjoin(bloc, line);
	FREE(bloc);
	return (temp);
}

int			ch_t_coordn(t_coordn *xy, int n)
{
	if (max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) < n - 1)
		return (1);
	else if (max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) == n - 1 &&
			max(xy[0].x, xy[1].x, xy[2].x, xy[3].x) < n - 1)
		return (1);
	else
		return (0);
}

t_coordn	*crdn_from_bloc(char **bloc, t_coordn *xy, int n)
{
	char		c;
	int			i;
	int			j;
	int			m;

	c = xy[0].c;
	i = -1;
	m = 0;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (bloc[i][j] == c)
			{
				xy[m].x = i;
				xy[m].y = j;
				xy[m++].c = c;
			}
		}
	}
	return (xy);
}

void		get_xy(int c, t_coordn *xy, char *bloc)
{
	int			i;
	int			j;
	int			m;

	i = -1;
	m = 0;
	j = 0;
	while (++i < 16)
	{
		if (bloc[i] != '.')
		{
			if (i < 4)
				xy[m].x = 0;
			else if (i < 8)
				xy[m].x = 1;
			else if (i < 12)
				xy[m].x = 2;
			else
				xy[m].x = 3;
			xy[m].y = j;
			xy[m++].c = c + 65;
		}
		j = j < 3 ? j + 1 : 0;
	}
	xy[m].x = -1;
}

t_coordn	**get_t_coordn(char *file, int fd)
{
	t_coordn	**xy;
	int			i;
	char		*line;
	char		*bloc;
	int			line_nbr;

	i = 0;
	line_nbr = 1;
	bloc = ft_strdup("");
	xy = (struct s_coordn**)malloc((bloc_nbr(file) + 1) *
			sizeof(struct s_coordn));
	while (get_next_line(fd, &line) > 0)
	{
		bloc = fixit(bloc, line);
		if (line_nbr == 4)
		{
			xy[i++] = (struct s_coordn*)malloc(sizeof(struct s_coordn) * 5);
			get_xy(i - 1, xy[i - 1], bloc);
			fix_t_coordn(xy[i - 1]);
			FREE(bloc);
			bloc = ft_strdup("");
		}
		line_nbr = line_nbr < 4 ? line_nbr + 1 : 0;
	}
	return (xy);
}
