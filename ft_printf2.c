/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjerdnap <tjerdnap@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:45:46 by tjerdnap          #+#    #+#             */
/*   Updated: 2024/03/02 11:08:52 by tjerdnap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char(char c)
{
	//int	i;

	//i = 1;
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s, int i)
{
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
		i++;
	}
	return (i);
}

int	ft_print_int(int num, int i)
{
	if (num == -2147483648)
	{
		ft_print_str("-2147483648", i);	
		return (i);
	}
	else if (num < 0)
	{
		ft_print_char('-');
		ft_print_int(-num, i);
		i++;
	}
	else if (num > 9)
	{
		ft_print_int(num / 10, i);
		ft_print_char(num % 10 + '0');
		i++;
	}
	else
	{
		ft_print_char(num + '0');
		i++;
	}
	return (i);
}

int	ft_print_hex(unsigned int hex, int i)
{
	return (i);
}

int	ft_find_format(const char *format, va_list ap, int i, int j)
{
	if (format[j] == 'c')
		ft_print_char(va_arg(ap, int));
	if (format[j] == 's')
		ft_print_str(va_arg(ap, char *), i);
	if (format[j] == 'd' || format[j] == 'i')
		ft_print_int(va_arg(ap, int), i);
	if (format[j] == 'x' || format[j] == 'X')
		ft_print_hex(va_arg(ap, int), i);
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
			i = ft_find_format(format, ap, i, ++j);
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

int	main(void)
{
	char c = 'n';
	char s[10] = "Hello";
	char *p = NULL;
	int d = 12;
	int i = -345;
	// int d = 123456780;
	// int i = -2147483648;
	unsigned int u = 1234;
	int x = 12334;
	int X = 12334;

	//printf("\t  %%c \t%%s \t%%p \t\t%%d \t\t%%i \t%%u \t%%x \t%%X\n");
	//printf("printf:    %c\t%s\t %p\t %d\t %i\t %u\t %x\t %X\n", c, s, p, d, i,
	//	u, x, X);
	printf("%s", "hello"); 
	//printf("%d\n", a);
	//ft_printf("%c", c);
	//printf("%d\n", b);
	//ft_printf("ft_printf: %c \t%s \t\t %d \t %i\n", c, s, d, i);

	// ft_printf("ft_printf: %c\t %s\t %p\t %d\t %i\t %u\t %x\t %X\n", c, s, p, d, i, u, x, X);

		// COMPARISON
		// printf("\tprintf\t ft_printf\n");
		// printf("%%c: %c\t", c);
		// ft_printf("%%c: %c\n", c);
		// printf("%%s: %s\t", "hello there");
		// ft_printf("%%s: %s\n", "hello there");
		// printf("%%p: %p\t", p);
		// ft_printf("%%p: %p\n", p);
		// printf("%%d: %d\t", d);
		// ft_printf("%%d: %d\n", d);
		// printf("%%i: %i\t", i);
		// ft_printf("%%i: %i\n", i);
		// printf("%%u: %u\t", u);
		// ft_printf("%%u: %u\n", u);
		// printf("%%x: %x\t", x);
		// ft_printf("%%x: %x\n", x);
		// printf("%%X: %X\t", X);
		// ft_printf("%%X: %X\n", X);
		return (0);
}