/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erreur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:58:41 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/26 12:10:11 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		check_bloc(char *bloc)
{
	int		i;
	int		full;
	int		voisinage;

	i = 0;
	full = 0;
	voisinage = 0;
	while (bloc[i])
	{
		if (bloc[i] == '#')
		{
			if ((i - 1) >= 0 && bloc[i - 1] == '#')
				voisinage++;
			if ((i + 1) < 16 && bloc[i + 1] == '#')
				voisinage++;
			if ((i + 4) < 16 && bloc[i + 4] == '#')
				voisinage++;
			if ((i - 4) >= 0 && bloc[i - 4] == '#')
				voisinage++;
			full++;
		}
		i++;
	}
	return (!(full != 4 || (voisinage != 6 && voisinage != 8) ||
				ft_strlen(bloc) != 16));
}

int		check_erreur(int fd)
{
	char	*line;
	char	*bloc;
	int		new_line;

	new_line = 1;
	bloc = ft_strdup("");
	while (get_next_line(fd, &line) > 0)
	{
		bloc = ft_strjoin(bloc, line);
		if ((ft_strlen(line) != 0 && ft_strlen(line) != 4) ||
				!check_alpha(line) || ((new_line % 5 == 0) &&
					ft_strcmp(line, "")))
			return (0);
		if (new_line == 4)
		{
			if (!check_bloc(bloc))
				return (0);
			FREE(bloc);
			bloc = ft_strdup("");
			new_line = -1;
		}
		new_line++;
	}
	return (1);
}

int		check(char *file)
{
	int		fd;
	int		fd2;
	char	*line;
	int		line_nbr;

	line_nbr = 1;
	fd = open(file, O_RDONLY);
	fd2 = open(file, O_RDONLY);
	if (get_next_line(fd, &line) <= 0 || !check_erreur(fd2))
		return (0);
	while (get_next_line(fd, &line) > 0)
		line_nbr++;
	if (!ft_strcmp(line, "") || (line_nbr != 4 && (line_nbr + 1) % 5 != 0) ||
			bloc_nbr(file) > 26)
		return (0);
	FREE(line);
	close(fd);
	close(fd2);
	return (1);
}
