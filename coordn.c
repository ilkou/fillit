/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:29:30 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/26 12:30:29 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*t_coordn_yplus(t_coordn *xy)
{
	int			m;

	m = -1;
	while (++m < 4)
		xy[m].y++;
	return ((void*)xy);
}

void		*t_coordn_xplus(t_coordn *xy)
{
	int			m;

	m = -1;
	while (++m < 4)
		xy[m].x++;
	return ((void*)xy);
}

t_coordn	*bloc_to_t_coordn(char **bloc)
{
	t_coordn	*xy;
	int			i;
	int			j;
	int			m;

	i = -1;
	m = 0;
	xy = (struct s_coordn*)malloc(sizeof(struct s_coordn) * 5);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (bloc[i][j] != '.')
			{
				xy[m].x = i;
				xy[m].y = j;
				xy[m++].c = bloc[i][j];
			}
		}
	}
	xy[m].x = -1;
	xy[m].y = -1;
	xy[m].c = '\0';
	return (xy);
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

t_coordn	**get_t_coordn(char *file)
{
	int			fd;
	char		**tetris;
	t_coordn	**xy;
	int			i;

	i = 0;
	fd = open(file, O_RDONLY);
	xy = (struct s_coordn**)malloc((bloc_nbr(file) + 1) *
			sizeof(struct s_coordn));
	tetris = tetris_string(file, fd);
	while (tetris[i])
	{
		xy[i] = bloc_to_t_coordn(tetris_bloc(tetris[i]));
		i++;
	}
	xy[i] = 0;
	close(fd);
	init((void**)tetris);
	return (xy);
}
