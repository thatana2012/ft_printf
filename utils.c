/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjerdnap <tjerdnap@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:10:52 by tjerdnap          #+#    #+#             */
/*   Updated: 2024/03/04 11:32:06 by tjerdnap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_int(int num, int i)
{
	if (num == -2147483648)
		i = ft_print_str("-2147483648", i);
	else if (num < 0)
	{
		i = ft_print_char('-', i);
		i = ft_print_int(-num, i);
	}
	else if (num > 9)
	{
		i = ft_print_int(num / 10, i);
		i = ft_print_char(num % 10 + '0', i);
	}
	else
	{
		i = ft_print_char(num + '0', i);
	}
	return (i);
}

int	ft_print_hex(size_t hex, int i, int lower)
{
	if (hex == 0)
		i = ft_print_char('0', i);
	else if (hex >= 16)
	{
		i = ft_print_hex(hex / 16, i, lower);
		i = ft_print_hex(hex % 16, i, lower);
	}
	else
	{
		if (hex <= 9)
			i = ft_print_char(hex + '0', i);
		else
		{
			if (lower)
				i = ft_print_char(hex + 'a' - 10, i);
			else
				i = ft_print_char(hex + 'A' - 10, i);
		}
	}
	return (i);
}

int	ft_print_ptr(void *ptr, int i)
{
	size_t	p;

	if (!ptr)
		i = ft_print_str("(nil)", i);
	else
	{
		p = (size_t)ptr;
		i = ft_print_str("0x", i);
		i = ft_print_hex(p, i, 1);
	}
	return (i);
}

int	ft_print_uint(unsigned int num, int i)
{
	if (num > 9)
	{
		i = ft_print_uint(num / 10, i);
		i = ft_print_char(num % 10 + '0', i);
	}
	else
	{
		i = ft_print_char(num + '0', i);
	}
	return (i);
}
