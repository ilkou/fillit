/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghous <mmaghous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:26:13 by oouklich          #+#    #+#             */
/*   Updated: 2019/02/11 16:52:02 by mmaghous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			bloc_nbr(char *file)
{
	char		*line;
	int			line_nbr;
	int			fd;

	line_nbr = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		line_nbr++;
	free(line);
	close(fd);
	return (line_nbr / 5);
}

int			ft_linelen(t_coordn **str)
{
	int			ln;

	ln = 0;
	while (str[ln])
		ln++;
	return (ln);
}

int			ft_sqrt(int nb)
{
	int			i;

	i = 1;
	while ((i * i) <= nb)
		i++;
	i--;
	if ((i * i) == nb)
		return (i);
	else
		return (i + 1);
}

int			max(int a, int b, int c, int d)
{
	int			max;

	max = a > b ? a : b;
	max = max > c ? max : c;
	max = max > d ? max : d;
	return (max);
}

int			min(int a, int b, int c, int d)
{
	int			min;

	min = a > b ? b : a;
	min = min > c ? c : min;
	min = min > d ? d : min;
	return (min);
}
