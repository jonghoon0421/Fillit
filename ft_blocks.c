/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 14:50:34 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/28 22:25:54 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_store(t_filist *list, char buf[BUF_SIZE + 1])
{
	ft_strncpy(list->block[0], buf, 4);
	ft_strncpy(list->block[1], buf + 5, 4);
	ft_strncpy(list->block[2], buf + 10, 4);
	ft_strncpy(list->block[3], buf + 15, 4);
	ft_i_position(list);
	ft_j_position(list);
}

void	ft_i_position(t_filist *list)
{
	int i;
	int j;

	while (list->num)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				if (list->block[i][j] == '#')
				{
					list->i = i;
					return ;
				}
			}
		}
	}
}

void	ft_j_position(t_filist *list)
{
	int i;
	int j;

	while (list->num)
	{
		j = -1;
		while (++j < 4)
		{
			i = -1;
			while (++i < 4)
			{
				if (list->block[i][j] == '#')
				{
					list->j = j;
					return ;
				}
			}
		}
	}
}
