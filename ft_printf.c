/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjerdnap <tjerdnap@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:45:46 by tjerdnap          #+#    #+#             */
/*   Updated: 2024/03/04 11:31:57 by tjerdnap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char(char c, int i)
{
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_print_str(char *s, int i)
{
	if (!s)
		i = ft_print_str("(null)", i);
	else
	{
		while (*s)
		{
			write(1, &(*s), 1);
			s++;
			i++;
		}
	}
	return (i);
}

int	ft_find_format(const char *format, va_list ap, int i, int j)
{
	if (format[j] == 'c')
		i = ft_print_char(va_arg(ap, int), i);
	else if (format[j] == 's')
		i = ft_print_str(va_arg(ap, char *), i);
	else if (format[j] == 'p')
		i = ft_print_ptr(va_arg(ap, void *), i);
	else if (format[j] == 'd' || format[j] == 'i')
		i = ft_print_int(va_arg(ap, int), i);
	else if (format[j] == 'u')
		i = ft_print_uint(va_arg(ap, unsigned int), i);
	else if (format[j] == 'x')
		i = ft_print_hex(va_arg(ap, unsigned int), i, 1);
	else if (format[j] == 'X')
		i = ft_print_hex(va_arg(ap, unsigned int), i, 0);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(ap, format);
	while (format[j])
	{
		if (format[j] == '%')
			i += ft_find_format(format, ap, i, ++j);
		else
		{
			i++;
			write(1, &format[j], 1);
		}
		j++;
	}
	va_end(ap);
	return (i);
}
/*
int	main(void)
{
	char			c;
	char			*s;
	char			*p;
	int				d;
	int				i;
	unsigned int	u;
	int				x;
	int				X;
	int				me_c;
	int				std_c;
	int				me_s;
	int				std_s;
	int				me_p;
	int				std_p;
	int				me_d;
	int				std_d;
	int				me_i;
	int				std_i;
	int				me_u;
	int				std_u;
	int				me_x;
	int				std_x;
	int				me_X;
	int				std_X;

	c = 'n';
	//char s[10] = "Hello";
	s = "hello";
	p = &c;
	// char *p = NULL;
	d = 12;
	i = -345;
	// int d = 123456780;
	// int i = -2147483648;
	u = 1234;
	x = 12334;
	X = 12334;
	printf("\t  %%c \t%%s \t%%p \t\t%%d \t%%i \t%%u \t%%x \t%%X\n");
	printf("printf:    %c\t %s\t %p\t %d\t %i\t %u\t %x\t %X\n", c, s, p, d, i,
		u, x, X);
	ft_printf("ft_printf: %c\t %s\t %p\t %d\t %i\t %u\t %x\t %X\n", c, s, p, d,
		i, u, x, X);
	// COMPARISON OF RETURN VALUE
	me_c = ft_printf("%c", c);
	std_c = printf("%c", c);
	me_s = ft_printf("%s", s);
	std_s = printf("%s", s);
	me_p = ft_printf("%p", p);
	std_p = printf("%p", p);
	me_d = ft_printf("%d", d);
	std_d = printf("%d", d);
	me_i = ft_printf("%i", i);
	std_i = printf("%i", i);
	me_u = ft_printf("%u", u);
	std_u = printf("%u", u);
	me_x = ft_printf("%x", x);
	std_x = printf("%x", x);
	me_X = ft_printf("%X", X);
	std_X = printf("%X", X);
	printf("\n");
	printf("me_c:  %d\n", me_c);
	printf("std_c: %d\n", std_c);
	printf("me_s:  %d\n", me_s);
	printf("std_s: %d\n", std_s);
	printf("me_p:  %d\n", me_p);
	printf("std_p: %d\n", std_p);
	printf("me_d:  %d\n", me_d);
	printf("std_d: %d\n", std_d);
	printf("me_i:  %d\n", me_i);
	printf("std_i: %d\n", std_i);
	printf("me_u:  %d\n", me_u);
	printf("std_u: %d\n", std_u);
	printf("me_x:  %d\n", me_x);
	printf("std_x: %d\n", std_x);
	printf("me_X:  %d\n", me_X);
	printf("std_X: %d\n", std_X);
	return (0);
}
*/