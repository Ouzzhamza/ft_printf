/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:08:55 by houazzan          #+#    #+#             */
/*   Updated: 2021/12/12 21:13:26 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef MAX_HEX
#  define MAX_HEX "0123456789ABCDEF"
# endif

# ifndef MIN_HEX
#  define MIN_HEX "0123456789abcdef"
# endif

# ifndef BASE
#  define BASE	"0123456789"
# endif

# include	<stdio.h>
# include	<stdarg.h>
# include	<unistd.h>
# include	<stdlib.h> 
# include	<string.h> 

void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putchar_hex(unsigned long int nbr, char *bas, int *len);
size_t	ft_strlen(const char *str);
void	ft_putnbr(long long nbr, int *len);
int		ft_printf(const char *fmt, ...);

#endif
