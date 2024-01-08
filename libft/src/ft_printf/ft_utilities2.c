/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:41:59 by anporced          #+#    #+#             */
/*   Updated: 2023/10/19 18:11:17 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbrlen_unsigned(unsigned long long nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (ft_nbrlen_unsigned(nb, 10));
}

int	ft_putnbr_hex(unsigned long long nbr)
{
	int	len;

	len = ft_nbrlen_unsigned(nbr, 16);
	if (nbr >= 16)
	{
		ft_putnbr_hex(nbr / 16);
		ft_putnbr_hex(nbr % 16);
	}
	else
	{
		if (nbr > 9)
			nbr += 'a' - '9' - 1;
		ft_putchar(nbr + '0');
	}
	return (len);
}

int	ft_putnbr_x(unsigned long int nbr, int check)
{
	if (nbr >= 16)
	{
		ft_putnbr_x(nbr / 16, check);
		ft_putnbr_x(nbr % 16, check);
	}
	else
	{
		if (nbr > 9 && check)
			ft_putchar(nbr + 'a' - 10);
		else if (nbr > 9 && !check)
			ft_putchar(nbr + 'A' - 10);
		else
			ft_putchar(nbr + '0');
	}
	return (ft_nbrlen_unsigned(nbr, 16));
}

int	ft_putptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	i += ft_putstr("0x");
	i += ft_putnbr_hex(ptr);
	return (i);
}
