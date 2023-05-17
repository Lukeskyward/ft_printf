/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasda- <lucasda-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:22:34 by lucasda-          #+#    #+#             */
/*   Updated: 2023/05/17 16:36:02 by lucasda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_format(char spec, va_list ap)
{
	int	counter;

	counter = 0;
	if (!spec)
		return (0);
	else if (spec == 'c')
		counter += ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		counter += ft_putstr(va_arg(ap, char *));
	else if (spec == 'p')
		counter += ft_putpointer(va_arg(ap, unsigned long));
	else if (spec == 'd' || spec == 'i')
		counter += ft_putnbr(va_arg(ap, int));
	else if (spec == 'u')
		counter += ft_utoa(va_arg(ap, unsigned int));
	else if (spec == 'x')
		counter += ft_puthex(va_arg(ap, unsigned int), spec);
	else if (spec == 'X')
		counter += ft_puthex(va_arg(ap, unsigned int), spec);
	else if (spec == '%')
		counter += write(1, "%", 1);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	va_start(ap, format);
	counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			counter += ft_print_format(*(++format), ap);
		else
			counter += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (counter);
}
