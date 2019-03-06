/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:33:27 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/25 20:36:24 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fix_alpha(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = c;
		i++;
	}
}

char		**tetris_string(char *file, int fd)
{
	char		**tetris;
	char		*line;
	char		*bloc;
	int			new_line;
	int			i;

	bloc = ft_strdup("");
	tetris = (char**)malloc((bloc_nbr(file) + 1) * sizeof(char**));
	new_line = 1;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		bloc = ft_strjoin(bloc, line);
		if (new_line == 4)
		{
			fix_alpha(bloc, 65 + i);
			tetris[i++] = ft_strdup(bloc);
			FREE(bloc);
			bloc = ft_strdup("");
			new_line = -1;
		}
		new_line++;
	}
	tetris[i] = 0;
	return (tetris);
}

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
