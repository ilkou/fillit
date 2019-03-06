/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:31:54 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/25 20:33:12 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**t_coordn_to_bloc(t_coordn *xy)
{
	char		**bloc;
	int			m;

	bloc = result_dimension(4);
	m = 0;
	while (xy[m].x >= 0)
	{
		bloc[xy[m].x][xy[m].y] = xy[m].c;
		m++;
	}
	return (bloc);
}

char		**tetris_bloc(char *str)
{
	char		**tetris;
	int			i;
	int			j;
	t_coordn	*xy;

	i = 0;
	j = 0;
	tetris = (char**)malloc(5 * sizeof(char**));
	while (j < 4)
	{
		tetris[j++] = ft_strsub(str, i, 4);
		i = i + 4;
	}
	tetris[j] = 0;
	xy = bloc_to_t_coordn(tetris);
	tetris = t_coordn_to_bloc(fix_t_coordn(xy));
	return (tetris);
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

char		*bloc_to_string(char **bloc)
{
	char		*str;
	int			i;
	int			j;
	int			k;

	str = (char*)malloc(17 * sizeof(char*));
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			str[k++] = bloc[i][j];
		}
	}
	str[k] = '\0';
	return (str);
}
