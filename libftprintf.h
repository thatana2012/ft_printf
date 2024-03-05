/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjerdnap <tjerdnap@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:12:06 by tjerdnap          #+#    #+#             */
/*   Updated: 2024/03/05 09:36:24 by tjerdnap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_int(int num);
int	ft_print_hex(unsigned long long hex, int lower);
int	ft_print_ptr(void *ptr);
int	ft_print_uint(unsigned int num);
int	ft_find_format(const char *format, va_list ap, int j);
int	ft_printf(const char *format, ...);

#endif
