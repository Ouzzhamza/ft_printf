/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:17:33 by houazzan          #+#    #+#             */
/*   Updated: 2021/12/12 21:18:45 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putnbr(long long nbr, int *len)
{
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = (long int)(nbr * -1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, len);
		ft_putchar(nbr % 10 + '0', len);
	}
	if (nbr <= 9 && nbr >= 0)
		ft_putchar(nbr % 10 + '0', len);
}
