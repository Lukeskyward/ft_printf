/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbrs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasda- <lucasda-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:14:59 by lucasda-          #+#    #+#             */
/*   Updated: 2023/05/17 16:33:06 by lucasda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nb)
{
	int		counter;
	long	n;

	n = nb;
	counter = 0;
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		counter += ft_putnbr((n / 10));
		counter += ft_putnbr((n % 10));
	}
	if (n < 10)
		counter += ft_putchar(n + 48);
	return (counter);
}

int	ft_puthex(unsigned long nb, const char c)
{
	char	*base;
	int		counter;

	counter = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		counter += ft_puthex((nb / 16), c);
		counter += ft_puthex((nb % 16), c);
	}
	else
		counter += write(1, &base[nb], 1);
	return (counter);
}

int	ft_putpointer(unsigned long nb)
{
	int	counter;

	counter = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	counter += ft_putstr("0x");
	counter += ft_puthex(nb, 'x');
	return (counter);
}

int	ft_utoa(unsigned int nb)
{
	int				counter;
	unsigned long	n;

	n = nb;
	counter = 0;
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		counter += ft_putnbr((n / 10));
		counter += ft_putnbr((n % 10));
	}
	if (n < 10)
		counter += ft_putchar(n + 48);
	return (counter);
}
