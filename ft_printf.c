/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjerdnap <tjerdnap@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:45:46 by tjerdnap          #+#    #+#             */
/*   Updated: 2024/03/01 14:42:15 by tjerdnap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int	ft_printf(const char *, ...)
// {
// 	va_list ap;
// }

int	main(void)
{
	char c = 'a';
	char s[20] = "Hello there";
	char *p = NULL;
	int d = 123456780;
	int i = -2147483648;
	unsigned int u = 1234;
	int x = 12334;
	int X = 12334;

	printf("%%c: %c\n", c);
	printf("%%s: %s\n", s);
	printf("%%p: %p\n", p);
	printf("%%d: %d\n", d);
	printf("%%i: %i\n", i);
	printf("%%u: %u\n", u);
	printf("%%x: %x\n", x);
	printf("%%X: %X\n", X);
	return (0);
}