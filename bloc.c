/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:31:54 by oouklich          #+#    #+#             */
/*   Updated: 2019/02/10 14:40:54 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*change_t_coordn(t_coordn *xy, int n)
{
	if (max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) < n - 1)
	{
		t_coordn_yplus(xy);
		return ((void*)xy);
	}
	else if (max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) == n - 1 &&
			max(xy[0].x, xy[1].x, xy[2].x, xy[3].x) < n - 1)
	{
		fix_yt_coordn(xy);
		t_coordn_xplus(xy);
		return ((void*)xy);
	}
	else
		return (NULL);
}

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

char		**delete_caract_from_bloc(char **bloc, int n, char c)
{
	int			i;
	int			j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (bloc[i][j] == c)
				bloc[i][j] = '.';
		}
	}
	return (bloc);
}

char		**add_t_coordn_to_bloc(char **bloc, t_coordn *xy)
{
	int			m;

	m = 0;
	while (xy[m].x >= 0)
	{
		bloc[xy[m].x][xy[m].y] = xy[m].c;
		m++;
	}
	return (bloc);
}
