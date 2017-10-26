/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 23:27:24 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/17 15:00:59 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_basic(char *str)
{
	int	dot_cnt;
	int	hash_cnt;
	int	i;

	dot_cnt = 0;
	hash_cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			ft_error_msg("error");
		if (str[i] == '.')
			dot_cnt++;
		if (str[i] == '#')
			hash_cnt++;
		i++;
	}
	if (dot_cnt != 12 || hash_cnt != 4)
		ft_error_msg("error");
}

int		ft_cnt_lines(char *str)
{
	int		i;
	int		new_cnt;

	i = 0;
	new_cnt = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			new_cnt++;
		i++;
	}
	return (new_cnt);
}

void	ft_check_lines(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (str[i])
	{
		if (i == (len - 1) && str[i] != '4')
			ft_error_msg("error");
		if (i < (len - 1) && str[i] != '5')
			ft_error_msg("error");
		i++;
	}
}

int		ft_single_line(t_filist list[26], int i, int j, int k)
{
	int	count;

	count = 0;
	if (j > 0 && list[i].block[j - 1][k] == '#')
		count++;
	if (j < 3 && list[i].block[j + 1][k] == '#')
		count++;
	if (k > 0 && list[i].block[j][k - 1] == '#')
		count++;
	if (k < 3 && list[i].block[j][k + 1] == '#')
		count++;
	return (count);
}

int		ft_check_connect(t_filist list[26])
{
	int	i;
	int j;
	int k;
	int cnt;

	i = -1;
	cnt = 0;
	while (++i < 26 && list[i].num != '\0')
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				if (list[i].block[j][k] == '#')
					cnt += ft_single_line(list, i, j, k);
			}
		}
		if (cnt == 6 || cnt == 8)
			cnt = 0;
		else
			ft_error_msg("error");
	}
	return (0);
}
