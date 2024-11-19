/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:21:29 by sidrissi          #+#    #+#             */
/*   Updated: 2024/11/19 17:48:35 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(unsigned long nb, int n)
{
	char	*x;
	int		count;

	count = 0;
	if (n == 1)
		count += write (1, "0x", 2);
	n = 0;
	x = "0123456789abcdef";
	if (nb / 16)
		count += ft_p((nb / 16), n);
	count += ft_putchar(x[nb % 16]);
	return (count);
}
