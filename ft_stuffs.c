/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stuffs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:06:58 by jonkim            #+#    #+#             */
/*   Updated: 2017/10/28 22:14:52 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_int_length(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (s[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (++j < i)
		str[j] = s[j];
	str[j] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*conv;
	int		leng;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	leng = ft_int_length(n);
	if (!(conv = (char*)malloc(sizeof(char) * (leng + 1))))
		return (NULL);
	conv[leng] = '\0';
	if (n < 0)
	{
		conv[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		conv[--leng] = (n % 10) + 48;
		n /= 10;
	}
	conv[--leng] = n + 48;
	return (conv);
}
