/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:43:30 by sidrissi          #+#    #+#             */
/*   Updated: 2024/11/19 17:49:18 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(char c)
{
	char	*str;
	int		i;

	str = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	_handle_cases(va_list ap, char c)
{
	int	count;
	int	n;

	n = 1;
	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		count += ft_hex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
		count += ft_p(va_arg(ap, unsigned long), n);
	else if (c == 'u')
		count += ft_u(va_arg(ap, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (checker(format[i + 1]))
			{
				count += _handle_cases(ap, format[i + 1]);
				i++;
			}
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
