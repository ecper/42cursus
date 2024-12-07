/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:58:31 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/19 06:51:07 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char	*check_space(const char *s)
{
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	return (s);
}

static const char	*check_minus(const char *s, int *sign)
{
	if (*s == '-')
	{
		*sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	return (s);
}

int	ft_isdouble(const char *str)
{
	int	has_digits;

	if (str == NULL || *str == '\0')
		return (0);
	str = check_space(str);
	if (*str == '+' || *str == '-')
		str++;
	has_digits = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		str++;
		has_digits = 1;
	}
	if (*str == '.')
	{
		str++;
		while (*str && ('0' <= *str && *str <= '9'))
			str++;
	}
	return (*str == '\0');
}

double	ft_atof(const char *str)
{
	double	result;
	double	factor;
	int		sign;

	result = 0.0;
	sign = 1;
	factor = 1.0;
	str = check_space(str);
	str = check_minus(str, &sign);
	while (*str && ('0' <= *str && *str <= '9'))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str && ('0' <= *str && *str <= '9'))
		{
			factor /= 10.0;
			result = result + (*str - '0') * (factor);
			str++;
		}
	}
	return (sign * result);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2))
	{
		if (*s1 != *s2)
		{
			return ((unsigned const char)*s1 - (unsigned const char)*s2);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
