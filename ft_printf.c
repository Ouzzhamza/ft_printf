/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:52:58 by houazzan          #+#    #+#             */
/*   Updated: 2021/12/12 21:08:47 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	ft_get_value(const char *fmt, va_list ptr, int *i, int *len)
{
	if (fmt[*i] == 'c' )
		ft_putchar(va_arg(ptr, int), len);
	else if (fmt[*i] == 's')
		ft_putstr(va_arg(ptr, char *), len);
	else if ((fmt[*i] == 'd' || fmt[*i] == 'i'))
		ft_putnbr(va_arg(ptr, int), len);
	else if (fmt[*i] == 'u')
		ft_putchar_hex(va_arg(ptr, unsigned int), BASE, len);
	else if (fmt[*i] == 'x')
		ft_putchar_hex(va_arg(ptr, unsigned int), MIN_HEX, len);
	else if (fmt[*i] == 'X')
		ft_putchar_hex(va_arg(ptr, unsigned int), MAX_HEX, len);
	else if (fmt[*i] == 'p')
	{
		ft_putstr("0x", len);
		ft_putchar_hex(va_arg(ptr, unsigned long int), MIN_HEX, len);
	}
	else if (fmt[*i] == '%')
		ft_putchar('%', len);
}

static void	ft_printf_sharp(const char *fmt, va_list ptr, int *i, int *len)
{
	unsigned int	ap;

	(*i)++;
	while (fmt[*i] == '#')
		(*i)++;
	ap = va_arg(ptr, unsigned int);
	if (fmt[*i] == 'x')
	{		
		if (ap != 0)
			ft_putstr("0x", len);
		ft_putchar_hex(ap, MIN_HEX, len);
	}
	if (fmt[*i] == 'X')
	{
		if (ap != 0)
			ft_putstr("0X", len);
		ft_putchar_hex(ap, MAX_HEX, len);
	}
}

static void	ft_printf_space(const char *fmt, va_list ptr, int *i, int *len)
{
	int	ap;

	(*i)++;
	while (fmt[*i] == ' ')
		(*i)++;
	ap = va_arg (ptr, int);
	if (ap >= 0)
		ft_putchar(' ', len);
	if (fmt[*i] == 'd' || fmt[*i] == 'i')
		ft_putnbr(ap, len);
}

static void	ft_printf_plus(const char *fmt, va_list ptr, int *i, int *len)
{
	int	ap;

	if (fmt[*i] == '+')
	{
		while (fmt[*i] == '+')
			(*i)++;
		ap = va_arg(ptr, int);
		if (ap >= 0)
			ft_putchar('+', len);
		if (fmt[*i] == 'd' || fmt[*i] == 'i')
			ft_putnbr(ap, len);
	}
	else if (fmt[*i] == ' ')
		ft_printf_space(fmt, ptr, i, len);
	else if (fmt[*i] == '#')
		ft_printf_sharp(fmt, ptr, i, len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '+' || fmt[i] == ' ' || fmt[i] == '#')
				ft_printf_plus(fmt, ptr, &i, &len);
			else
				ft_get_value(fmt, ptr, &i, &len);
		}
		else
			ft_putchar(fmt[i], &len);
		i++;
	}
	va_end(ptr);
	return (len);
}
