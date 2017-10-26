/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:34:44 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/25 18:00:12 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_test(t_filist *list, char **board, int i, int j, int size)
{
	while (i < 4)
	{
		while (j < 4)
		{
			list
		}
	}
}

void	ft_put_block(t_filist *list, char **board)
{
	int i;
	int j;
	int blocki;
	int blockj;

	bi = list->i;
	bj = list->j;
	while (i < size)
	{
		while (j < size)
		{
			if (board[i][j] == '.')
			{
				while (bi < 4 && bj < 4)
				{
					board[i][j] = list->block[bi][bj];
					bj++;
				}
			}
			j++;
		}
		i++;
	}
}
