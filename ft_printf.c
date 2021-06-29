/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:30:50 by anhovhan          #+#    #+#             */
/*   Updated: 2021/03/25 18:30:54 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lib.h"

void	printpercent(t_fields *st)
{
	if (!st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ', st);
	else if (!st->minus && st->zero && st->width)
		printch(st->width - 1, '0', st);
	printch(1, '%', st);
	if (st->minus && !st->zero && st->width)
		printch(st->width - 1, ' ', st);
}

void	init_struct(t_fields *st)
{
	st->minus = 0;
	st->zero = 0;
	st->prec = 0;
	st->width = 0;
	st->dot = 0;
	st->len = 0;
}

void	handle_signs(char c, va_list args, t_fields *st)
{
	if (c == 'c')
		printchar(args, st);
	else if (c == 'd' || c == 'i' || c == 'u')
		printdigit(c, args, st);
	else if (c == 's')
		printstr(args, st);
	else if (c == 'x' || c == 'X')
		printhex(c, args, st);
	else if (c == 'p')
		printpointer(args, st);
}

void	check_sign(char **str, va_list args, t_fields *st)
{
	char	*signs;
	int		j;

	(*str)++;
	j = 0;
	check_flags(str, st);
	check_width(str, st, args);
	check_precision(str, st, args);
	signs = ft_strdup("cspdiuxX");
	while (signs[j] != '\0')
	{
		if (**str == signs[j])
		{
			handle_signs(signs[j], args, st);
			break ;
		}
		j++;
	}
	if (**str == '%')
		printpercent(st);
}

int		ft_printf(const	char *s, ...)
{
	va_list		args;
	int			i;
	int			count;
	char		*str;
	t_fields	st;

	count = 0;
	str = (char *)s;
	i = 0;
	va_start(args, s);
	while (*str != '\0')
	{
		init_struct(&st);
		if (*str == '%')
			check_sign(&str, args, &st);
		else
			printch(1, *str, &st);
		count += st.len;
		str++;
	}
	va_end(args);
	return (count);
}
