/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:31:46 by anhovhan          #+#    #+#             */
/*   Updated: 2021/04/06 18:31:49 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static	int		count(long n)
{
	size_t	cnt;

	cnt = (n > 0 ? 0 : 1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static	char	*reverse(char *str)
{
	size_t	k;
	size_t	i;
	char	tmp;

	if (ft_strlen(str) % 2 == 0)
	{
		k = ft_strlen(str) / 2;
	}
	else
	{
		k = (ft_strlen(str) + 1) / 2;
	}
	i = 0;
	while (i < k)
	{
		tmp = str[i];
		str[i] = str[ft_strlen(str) - 1 - i];
		str[ft_strlen(str) - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char			*ft_utoa(long n)
{
	size_t	i;
	char	*str;
	int		t;
	long	num;

	num = n;
	t = 0;
	if (!(str = (char *)malloc((count(num) + 1) * sizeof(char))))
		return (NULL);
	if (num < 0)
	{
		*str++ = '-';
		num *= -1;
		t = 1;
	}
	i = 0;
	if (num == 0)
		str[i++] = '0';
	while (num != 0)
	{
		str[i++] = (num % 10 + '0');
		num = num / 10;
	}
	str[i] = '\0';
	return (reverse(str) - t);
}
