/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:17:24 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/26 12:12:20 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_result(char **tetris)
{
	int			i;

	i = 0;
	while (tetris[i])
		ft_putstr(ft_strjoin(tetris[i++], "\n"));
}

t_coordn	*check_place(char **tetris, int n, t_coordn *xy)
{
	int			m;
	int			empty;

	m = -1;
	empty = 0;
	if (max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) >= n ||
			max(xy[0].x, xy[1].x, xy[2].x, xy[3].x) >= n)
		return (NULL);
	while (++m < 4)
	{
		if (tetris[xy[m].x][xy[m].y] == '.')
			empty++;
	}
	if (empty != 4 && max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) < n - 1)
		return (check_place(tetris, n, t_coordn_yplus(xy)));
	if (empty != 4 && max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) == n - 1 &&
			max(xy[0].x, xy[1].x, xy[2].x, xy[3].x) < n - 1)
	{
		xy = fix_yt_coordn(xy);
		return (check_place(tetris, n, t_coordn_xplus(xy)));
	}
	if (max(xy[0].y, xy[1].y, xy[2].y, xy[3].y) >= (n - 1) &&
			max(xy[0].x, xy[1].x, xy[2].x, xy[3].x) >= (n - 1) && empty != 4)
		return (NULL);
	return (xy);
}

int			ba_track(char **result, t_coordn **xy, int i, int n)
{
	if (i == ft_linelen(xy))
		return (1);
	while (check_place(result, n, xy[i]) != NULL)
	{
		add_t_coordn_to_bloc(result, xy[i]);
		fix_t_coordn(xy[i]);
		if (ba_track(result, xy, i + 1, n))
			return (1);
		else
		{
			fix_t_coordn(xy[i + 1]);
			crdn_from_bloc(result, xy[i], n);
			delete_caract_from_bloc(result, n, xy[0]->c + i);
			if (ch_t_coordn(xy[i], n))
				change_t_coordn(xy[i], n);
			else
			{
				fix_t_coordn(xy[i]);
				return (0);
			}
		}
	}
	return (0);
}

char		**solve(char *file)
{
	char		**result;
	t_coordn	**xy;
	int			n;
	int			d;

	n = ft_sqrt(4 * bloc_nbr(file));
	result = result_dimension(n);
	xy = get_t_coordn(file);
	d = ba_track(result, xy, 0, n);
	while (d == 0)
	{
		init((void**)xy);
		xy = get_t_coordn(file);
		init((void**)result);
		result = result_dimension(n + 1);
		d = ba_track(result, xy, 0, n + 1);
	}
	init((void**)xy);
	return (result);
}
