/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:12:05 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/28 22:31:18 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <string.h>
# include <strings.h>
# include <stdio.h>

# define BUF_SIZE 21

typedef struct	s_filist
{
	char		num;
	char		block[4][5];
	int			i;
	int			j;
}				t_filist;

/* ft_check_valid */
void			ft_check_basic(char *str);
int				ft_single_line(t_filist list[26], int i, int j, int k);
int				ft_check_connect(t_filist list[26]);
int				ft_cnt_lines(char *str);
void			ft_check_lines(char *str);

/* ft_blocks */
void			ft_store(t_filist *list, char buf[BUF_SIZE + 1]);
void			ft_i_position(t_filist *list);
void			ft_j_position(t_filist *list);

/* ft_error */
void			ft_error_msg(char *str);

/* ft_stuff */
char			*ft_strncpy(char *dest, const char *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			ft_putchar(char c);
void			ft_putendl(char const *s);

/* ft_stuffs */
int				ft_int_length(int n);
char			*ft_strdup(const char *s);
char			*ft_itoa(int n);

/* ft_board */
char			**ft_create_board(int size);
void			ft_bigger_board(char **board, int size);
void			ft_print_board(char **board);

/* ft_fill */
int				ft_fill_check(t_filist list, char **board, int bi, int bj);
void			ft_fill_list(t_filist list[26], char **board, int n);
void			ft_fill_it(t_filist list, char **board, int bi, int bj);
void			ft_delete_it(t_filist list, char **board, int n);

#endif
