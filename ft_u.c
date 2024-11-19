/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:22:17 by sidrissi          #+#    #+#             */
/*   Updated: 2024/11/19 17:51:12 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	_n_digit(long num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_u(unsigned int num)
{
	unsigned int	num_digit;
	unsigned int	count;

	count = 0;
	num_digit = _n_digit(num);
	if (num >= 10)
		ft_u(num / 10);
	ft_putchar((num % 10) + '0');
	return (num_digit);
}
