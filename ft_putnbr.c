/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:19:21 by sidrissi          #+#    #+#             */
/*   Updated: 2024/11/19 17:50:00 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	_n_digit(long num)
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

int	ft_putnbr(int nb)
{
	long	num_digit;
	long	num;
	int		count;

	count = 0;
	num = nb;
	if (num < 0)
		num_digit = _n_digit(num) + 1;
	else
		num_digit = _n_digit(num);
	if (num < 0)
	{
		ft_putchar('-');
		num = num * -1;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
	return (num_digit);
}
