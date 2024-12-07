/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:16:36 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 20:20:49 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_space(const char *nptr, int *index)
{
	while (nptr[*index] && (nptr[*index] == ' ' || nptr[*index] == '\f'
			|| nptr[*index] == '\n' || nptr[*index] == '\r'
			|| nptr[*index] == '\t' || nptr[*index] == '\v'))
	{
		*index += 1;
	}
}

static int	check_minus(const char *nptr, int *index)
{
	if (nptr[*index] == '-' || nptr[*index] == '+')
	{
		if (nptr[*index] == '-')
		{
			*index += 1;
			return (-1);
		}
		*index += 1;
	}
	return (1);
}

static int	is_overflow(int minus, unsigned long num, unsigned long tmp)
{
	unsigned long	check;

	if (minus > 0)
		check = INT_MAX;
	else
		check = ((unsigned long)INT_MAX) + 1;
	if (check / 10 < num || check - num * 10 < tmp)
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *nptr)
{
	int				minus;
	int				i;
	unsigned long	num;

	i = 0;
	num = 0;
	minus = 1;
	check_space(nptr, &i);
	minus = check_minus(nptr, &i);
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		if (is_overflow(minus, num, (nptr[i] - '0')))
		{
			if (minus > 0)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (minus * num);
}
