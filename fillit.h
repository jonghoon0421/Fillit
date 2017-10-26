/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:12:05 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/25 17:29:07 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
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
	char		block[5][5];
	int			i;
	int			j;
}				t_filist;

/* ft_check_valid */
void			ft_error_msg(char *str);
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

/* ft_board */
char			**ft_create_board(int size);
void			ft_bigger_board(char **board, int size);

#endif
