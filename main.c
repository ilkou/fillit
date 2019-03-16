/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:32:08 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/26 12:26:50 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**result;

	if (argc != 2)
		ft_putstr("usage: ./fillit file_name\n");
	else
	{
		if (!check(argv[1]))
		{
			ft_putstr("error\n");
			exit(0);
		}
		result = solve(argv[1]);
		print_result(result);
		init((void**)result);
	}
	return (0);
}
