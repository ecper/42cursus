/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:55:24 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/31 20:02:55 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_element(const char format, va_list ap)
{
	if (format == 'c')
		return (ft_putchar_fd((unsigned char)va_arg(ap, int), STDOUT_FILENO));
	else if (format == 's')
		return (ft_putstr_fd((char *)va_arg(ap, char *), STDOUT_FILENO));
	else if (format == 'd')
		return (ft_putnbr_fd((int)va_arg(ap, int), STDOUT_FILENO));
	else if (format == 'p')
		return (ft_putaddr_fd((uintptr_t)va_arg(ap, void *), STDOUT_FILENO));
	else if (format == 'i')
		return (ft_putnbr_fd((int)va_arg(ap, int), STDOUT_FILENO));
	else if (format == 'u')
		return (ft_putnbr_base_fd((unsigned int)va_arg(ap, unsigned int),
				"0123456789", STDOUT_FILENO));
	else if (format == 'x')
		return (ft_putnbr_base_fd((unsigned int)va_arg(ap, unsigned int),
				"0123456789abcdef", STDOUT_FILENO));
	else if (format == 'X')
		return (ft_putnbr_base_fd((unsigned int)va_arg(ap, unsigned int),
				"0123456789ABCDEF", STDOUT_FILENO));
	else if (format == '%')
		return (ft_putchar_fd('%', STDOUT_FILENO));
	return (ft_putchar_fd('%', STDOUT_FILENO));
}

static int	is_success_display(int *element_flag, int *output_count,
		char format, va_list ap)
{
	int	output;

	if (*element_flag)
	{
		output = check_element(format, ap);
		if (output < 0)
			return (-1);
		*output_count += output;
		*element_flag = 0;
	}
	else if (format == '%')
		*element_flag = 1;
	else
	{
		output = ft_putchar_fd(format, STDOUT_FILENO);
		if (output < 0)
			return (-1);
		*output_count += output;
	}
	return (*output_count);
}

static int	check_format(const char *format)
{
	int	i;

	i = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (!(CHAR_MIN <= format[i] && format[i] <= CHAR_MAX))
			return (0);
		i++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		element_flag;
	int		output_count;
	va_list	ap;

	i = 0;
	element_flag = 0;
	output_count = 0;
	if (!check_format(format))
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (is_success_display(&element_flag, &output_count, format[i], ap) < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (output_count);
}
