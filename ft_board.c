/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:31:21 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/25 16:37:21 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_bigger_board(char **board, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j > size - 4 || i > size - 4)
				board[i][j++] = '+';
			else
				board[i][j++] = '.';
		}
	}
}

char	**ft_create_board(int size)
{
	int		i;
	char	**board;

	i = 0;
	board = (char**)malloc(sizeof(char*) * (size + 1));
	if (board == NULL)
		return (NULL);
	board[size] = NULL;
	while (i < size)
	{
		board[i] = (char*)malloc(sizeof(char) * (size + 1));
		if (board[i] == NULL)
			return (NULL);
		board[i][size] = '\0';
		i++;
	}
	ft_bigger_board(board, size);
	return (board);
}
/*
int		main(int ac, char **av)
{
	char **res;

	(void)ac;
	res = ft_create_board(10);
	for (int i = 0; i < 10; i++)
		printf("%s\n", res[i]);
	return (0);
}
*/
