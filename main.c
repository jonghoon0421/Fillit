/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 17:06:39 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/28 21:25:31 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(char **av, t_filist list[26])
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		i;
	char	lines[26];

	fd = open(av[1], O_RDONLY);
	i = -1;
	if ((ret = read(fd, buf, BUF_SIZE)) <= 0)
		ft_error_msg("error");
	while (ret > 0 && ++i < 26)
	{
		buf[ret] = '\0';
		ft_check_basic(buf);
		lines[i] = *ft_itoa(ft_cnt_lines(buf));
		list[i].num = 'A' + i;
		ft_store(&list[i], buf);
		ret = read(fd, buf, BUF_SIZE);
	}
	lines[i + 1] = '\0';
	ft_check_lines(lines);
	ft_check_connect(list);
	close(fd);
	return (i);
}

int		main(int ac, char **av)
{
	t_filist	list[26];
	int			size;
	int			pcs;
	char		**board;

	size = 0;
	ft_bzero(&list, sizeof(list));
	if (ac != 2)
		return (0);
	pcs = ft_read(av, list) + 1;
	while (size * size < 4 * pcs)
		size++;
	size += 3;
	while (1)
	{
		board = ft_create_board(size);
		ft_fill_list(list, board, 0); // next line starts only if all sub_f fails
		size++;
		free(board);
	}
	return (0);
}
