/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 20:04:27 by houazzan          #+#    #+#             */
/*   Updated: 2021/12/12 21:17:27 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"ft_printf.h"

void	ft_putchar_hex(unsigned long int nbr, char *bas, int *lent)
{
	unsigned int	len;

	len = ft_strlen(bas);
	if (nbr < 0)
	{
		ft_putchar('-', lent);
		nbr = (nbr * -1);
	}
	if (nbr >= len)
	{
		ft_putchar_hex(nbr / len, bas, lent);
		ft_putchar(bas[nbr % len], lent);
	}
	else
		ft_putchar(bas[nbr % len], lent);
}
