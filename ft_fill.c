/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:34:44 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/28 21:41:19 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fill_check(t_filist list, char **board, int bi, int bj)
{
	int i;
	int j;

	i = 0;
	while (list.block[list.i + i][0] != '\0')
	{
		j = 0;
		while (list.block[list.i + i][list.j + j] != '\0')
		{
			if (list.block[list.i + i][list.j + j] == '#' &&
				board[bi + i][bj + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_fill_it(t_filist list, char **board, int bi, int bj)
{
	int i;
	int j;

	i = 0;
	while (list.block[list.i + i][0] != '\0')
	{
		j = 0;
		while (list.block[list.i + i][list.j + j] != '\0')
		{
			if (list.block[list.i + i][list.j + j] == '#')
				board[bi + i][bj + j] = list.num;
			j++;
		}
		i++;
	}
}

void	ft_delete_it(t_filist list, char **board, int n)
{
	int i;
	int j;

	if (n < 0)
		return ;
	i = 0;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (board[i][j] == list.num)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_fill_list(t_filist list[26], char **board, int n)
{
	int i;
	int j;

	i = 0;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			if (ft_fill_check(list[n], board, i, j))
			{
				ft_fill_it(list[n], board, i, j);
				if (list[n + 1].num != '\0')
					ft_fill_list(list, board, n + 1);
				else
					ft_print_board(board); // last block put (finished all)
			}
			j++;
		}
		i++;
	}
	ft_delete_it(list[n - 1], board, n - 1);
}
