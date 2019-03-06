/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:27:59 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/25 20:29:11 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		init(void **free_it)
{
	int			i;

	i = 0;
	while (free_it[i])
	{
		FREE(free_it[i]);
		i++;
	}
	FREE(free_it[i]);
	ft_memdel((void**)free_it);
}

char		*set_point(int n)
{
	char		*dest;
	int			i;

	i = 0;
	dest = (char*)malloc((n + 1) * sizeof(dest));
	while (i < n)
		dest[i++] = '.';
	dest[i] = '\0';
	return (dest);
}

char		**result_dimension(int n)
{
	char		**result;
	int			i;

	i = 0;
	result = (char**)malloc((n + 1) * sizeof(result));
	while (i < n)
		result[i++] = set_point(n);
	result[i] = 0;
	return (result);
}

void		*fix_t_coordn(t_coordn *xy)
{
	int			min_x;
	int			min_y;
	int			m;

	min_x = min(xy[0].x, xy[1].x, xy[2].x, xy[3].x);
	min_y = min(xy[0].y, xy[1].y, xy[2].y, xy[3].y);
	m = 0;
	while (m < 4)
	{
		xy[m].x = xy[m].x - min_x;
		xy[m].y = xy[m].y - min_y;
		m++;
	}
	return ((void*)xy);
}

void		*fix_yt_coordn(t_coordn *xy)
{
	int			min_y;
	int			m;

	min_y = min(xy[0].y, xy[1].y, xy[2].y, xy[3].y);
	m = 0;
	while (m < 4)
	{
		xy[m].y = xy[m].y - min_y;
		m++;
	}
	return ((void*)xy);
}
