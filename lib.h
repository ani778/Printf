/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhovhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:28:46 by anhovhan          #+#    #+#             */
/*   Updated: 2021/04/06 18:28:48 by anhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_st
{
	int	minus;
	int zero;
	int	dot;
	int	prec;
	int	width;
	int	len;
}				t_fields;

void			printchar(va_list args, t_fields *st);
void			printdigit(char c, va_list args, t_fields *st);
void			printstr(va_list args, t_fields *st);
char			*ft_anybase(unsigned long n, const char *base);
void			printhex(char c, va_list args, t_fields *st);
void			check_flags(char **str, t_fields *st);
void			check_width(char **str, t_fields *st, va_list args);
void			check_precision(char **str, t_fields *st, va_list args);
void			printch(int quant, char ch, t_fields *st);
void			printpointer(va_list args, t_fields *st);
char			*ft_utoa(unsigned long n);
void			ft_putstr(char *str, t_fields *st);

#endif
