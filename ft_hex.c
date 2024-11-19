/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:20:18 by sidrissi          #+#    #+#             */
/*   Updated: 2024/11/19 17:48:46 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int nb, char c)
{
	char	*x;
	char	*_x;
	int		count;

	x = "0123456789abcdef";
	_x = "0123456789ABCDEF";
	count = 0;
	if (c == 'x')
	{
		if (nb / 16)
			count += ft_hex((nb / 16), c);
		count += ft_putchar(x[nb % 16]);
	}
	else if (c == 'X')
	{
		if (nb / 16)
			count += ft_hex((nb / 16), c);
		count += ft_putchar(_x[nb % 16]);
	}
	return (count);
}
