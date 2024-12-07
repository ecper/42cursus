/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:36:00 by hauchida          #+#    #+#             */
/*   Updated: 2024/10/31 19:23:59 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	*dest;
	int		result;

	dest = ft_itoa(n);
	if (!dest)
		return (-1);
	result = ft_putstr_fd(dest, fd);
	free(dest);
	return (result);
}
