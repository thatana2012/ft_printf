/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjerdnap <tjerdnap@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:10:52 by tjerdnap          #+#    #+#             */
/*   Updated: 2024/03/05 09:36:08 by tjerdnap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_int(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
		i += ft_print_str("-2147483648");
	else if (num < 0)
	{
		i += ft_print_char('-');
		i += ft_print_int(-num);
	}
	else if (num > 9)
	{
		i += ft_print_int(num / 10);
		i += ft_print_char(num % 10 + '0');
	}
	else
		i += ft_print_char(num + '0');
	return (i);
}

int	ft_print_hex(unsigned long long hex, int lower)
{
	int	i;

	i = 0;
	if (hex == 0)
		i += ft_print_char('0');
	else if (hex >= 16)
	{
		i += ft_print_hex(hex / 16, lower);
		i += ft_print_hex(hex % 16, lower);
	}
	else
	{
		if (hex <= 9)
			i += ft_print_char(hex + '0');
		else
		{
			if (lower)
				i += ft_print_char(hex + 'a' - 10);
			else
				i += ft_print_char(hex + 'A' - 10);
		}
	}
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	p;
	int					i;

	i = 0;
	if (!ptr)
		i += ft_print_str("(nil)");
	else
	{
		p = (unsigned long long)ptr;
		i += ft_print_str("0x");
		i += ft_print_hex(p, 1);
	}
	return (i);
}

int	ft_print_uint(unsigned int num)
{
	int	i;

	i = 0;
	if (num > 9)
	{
		i += ft_print_uint(num / 10);
		i += ft_print_char(num % 10 + '0');
	}
	else
		i = ft_print_char(num + '0');
	return (i);
}
