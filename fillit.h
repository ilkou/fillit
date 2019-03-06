/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:38:02 by oouklich          #+#    #+#             */
/*   Updated: 2019/01/26 12:32:51 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_coordn
{
	int		x;
	int		y;
	char	c;
}				t_coordn;

int				get_next_line(int fd, char **line);

int				check_alpha(char *str);
int				check_bloc(char *bloc);
int				check_erreur(int fd);
int				check(char *file);

int				bloc_nbr(char *file);
int				ft_linelen(t_coordn **str);
int				ft_sqrt(int nb);
int				max(int a, int b, int c, int d);
int				min(int a, int b, int c, int d);

void			init(void **free_it);
char			*set_point(int n);
char			**result_dimension(int n);
void			*fix_t_coordn(t_coordn *xy);
void			*fix_yt_coordn(t_coordn *xy);

void			*t_coordn_yplus(t_coordn *xy);
void			*t_coordn_xplus(t_coordn *xy);
t_coordn		*bloc_to_t_coordn(char **bloc);
t_coordn		*crdn_from_bloc(char **bloc, t_coordn *xy, int n);
t_coordn		**get_t_coordn(char *file);

char			**t_coordn_to_bloc(t_coordn *xy);
char			**tetris_bloc(char *str);
char			**delete_caract_from_bloc(char **bloc, int n, char c);
char			**add_t_coordn_to_bloc(char **bloc, t_coordn *xy);
char			*bloc_to_string(char **bloc);

void			fix_alpha(char *str, char c);
char			**tetris_string(char *file, int fd);
void			*change_t_coordn(t_coordn *xy, int n);
int				ch_t_coordn(t_coordn *xy, int n);

void			print_result(char **tetris);
t_coordn		*check_place(char **tetris, int n, t_coordn *xy);
int				ba_track(char **result, t_coordn **xy, int i, int n);
char			**solve(char *file);

# define BUFF_SIZE 21
# define FREE(x) { if (x) free(x); x = NULL; }

#endif
