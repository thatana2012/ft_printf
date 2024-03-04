/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjerdnap <tjerdnap@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:12:06 by tjerdnap          #+#    #+#             */
/*   Updated: 2024/03/04 11:32:55 by tjerdnap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(char c, int i);
int	ft_print_str(char *s, int i);
int	ft_print_int(int num, int i);
int	ft_print_hex(size_t hex, int i, int lower);
int	ft_print_ptr(void *ptr, int i);
int	ft_print_uint(unsigned int num, int i);
int	ft_find_format(const char *format, va_list ap, int i, int j);
int	ft_printf(const char *format, ...);

#endif
