/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:36:27 by anhovhan          #+#    #+#             */
/*   Updated: 2021/04/06 18:36:29 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib.h"

void	printch(int quant, char ch, t_fields *st)
{
	int		i;

	i = 0;
	while (i < quant)
	{
		write(1, &ch, 1);
		st->len += 1;
		i++;
	}
}

void	ft_putstr(char *str, t_fields *st)
{
	write(1, str, ft_strlen(str));
	st->len += ft_strlen(str);
}
